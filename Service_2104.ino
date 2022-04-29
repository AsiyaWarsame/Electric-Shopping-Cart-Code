// The sender Gyro value (x) is passed through this tab.

void servicef()
{
   // Serial.print("Service before");
  
  BLEService service = peripheral.service("1101");
  BLECharacteristic Xchar = service.characteristic("2104");

  if (Xchar.canRead()) {
    //read the characteristic value
    x = 0;
    Xchar.readValue(&x, 4);
    Serial.print("           X--S = ");
    Serial.print((float)x);

  }

//Serial.print("Service after");
}
