#include <ArduinoBLE.h>
#include <MPU6050_tockn.h>
#include <Wire.h>

MPU6050 mpu6050(Wire);


//integer variables to send via BLE
int xBLE = 0; //*pow(10,d_a);
int yBLE = 0; //*pow(10,d_a);
int zBLE = 0; //*pow(10,d_a);

//Introducing the servies
BLEService SensorService("1101");
BLEUnsignedIntCharacteristic XChar("2104", BLERead | BLENotify);
BLEUnsignedIntCharacteristic YChar("2105", BLERead | BLENotify);
BLEUnsignedIntCharacteristic ZChar("2106", BLERead | BLENotify);


void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);

 
  pinMode(LED_BUILTIN, OUTPUT);

  if (!BLE.begin()) {
    Serial.println("BLE failed to Initiate");
    delay(500);
    while (1);
  }

  BLE.setLocalName("Arduino (reciever)");
  BLE.setAdvertisedService(SensorService);
  SensorService.addCharacteristic(XChar);
  SensorService.addCharacteristic(YChar);
  SensorService.addCharacteristic(ZChar);

  BLE.addService(SensorService);

  //XChar.writeValue(xBLE);
  //YChar.writeValue(yBLE);
  //ZChar.writeValue(zBLE);

  BLE.advertise();
  Serial.println("Arduino reciever device is now active, waiting for connections...");
}


void loop() {
long timer =0;
  
  BLEDevice central = BLE.central();
  if (!central)
  {
    BLE.advertise();
    Serial.println("Advertising for connection...");
    Serial.println("                              ");
    Serial.println(BLE.address());
    
  }

  if (central) {
    Serial.print("Connected to sender: ");
    Serial.print("* Device MAC address: ");
    Serial.println(central.address());
    Serial.println(" ");

    digitalWrite(LED_BUILTIN, HIGH);

    while (central.connected()) {


      mpu6050.update();
if(millis() - timer > 200){
  
  
    Serial.print("Sender X : ");Serial.println(mpu6050.getGyroAngleX());
   
     //multiply them by 10
      xBLE = mpu6050.getGyroAngleX() ;
      yBLE = mpu6050.getGyroAngleY();
      zBLE = mpu6050.getGyroAngleZ();
 

   timer = millis();
    
  }
     

      Serial.print("axSensor ");
      Serial.print(xBLE);
      Serial.print(" - aySensor ");
      Serial.print(yBLE);
      Serial.print(" - azSensor ");
      Serial.println(zBLE);


      XChar.writeValue(xBLE);
      YChar.writeValue(yBLE);
      ZChar.writeValue(zBLE);


    }
  }
  else {
    delay(100);
  }
  digitalWrite(LED_BUILTIN, LOW);
  //Serial.print("Disconnected from central: ");
  //Serial.println("                              ");
  //Serial.println(central.address());
  //BLE.advertise();
}
