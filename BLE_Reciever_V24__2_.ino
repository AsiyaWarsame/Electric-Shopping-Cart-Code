////////////////////////////////////////////////////////

//BLE_RECIEVER_V24_(2),include the forward and pause movement

////////////////////////////////////////////////////////

// including libraries.
#include <ArduinoBLE.h>
#include <MPU6050_tockn.h>
#include <Wire.h>
BLEDevice peripheral;

//defining variable
int recieverX;
int32_t x = 0;
MPU6050 mpu6050(Wire);
long timer = 0;

/////////////////////////////

#include<NewPing.h>
#define TRIGGER_PIN A1
#define ECHO_PIN A0
#define MAX_DISTANCE 100
int dig2 = 8;
int dig13 = 9;
int digA5 = 10;
//integer d is used as a distance to call out the ultrasonic sensor.
int d;

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // newPing setup of pins and maximum distance.
int const motors = 0;

void setup() {

  Serial.begin(9600);

  //calling setupf function which contain the sender gyro value.
  Setupf();

  //gyroscpe
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);

}

void loop() {

  peripheral = BLE.available();
  peripheral_detection();

  while (peripheral.connect())
  {
    servicef();
  
    // print the RSSI
    Serial.print("    RSSI: ");
    Serial.print(peripheral.rssi());
 
// the ultrasoni sensor function is written below.
// the sense will pause if there are any object lose to 40cm.
    d = sonar_sensor();

    if (d < 40)
    {
      pause();  // calling out the pause function.
    }
    else
    {
      // the forward movement
      if (peripheral.rssi() < -55) {
        forward();

      }
      // the backward movement
      // if (peripheral.rssi() >= -70) {
      //  backward();
    }
    
// calling out the receiver gyro.
    gyroscope();

    if ( x > 5)
    {
      TurnLeft();

    } else if ( x < -5)
    {
      TurnRight();

    }
    else {

      pause();

    }
  }

}
