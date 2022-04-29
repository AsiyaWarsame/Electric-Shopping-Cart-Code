//The peripheral detection tab contains the connection program.
// The receiver device advertise its address and wait for a connection to be established.

void peripheral_detection() {

  if (peripheral.address() != "cb:f4:b7:9e:70:72") 
  {
    Serial.println("Device not found Scanning... ");  // A message will be displayed, informing that the device isnt found.
    // the device will continue scanning until the connection is made.
    BLE.scan();
    peripheral = BLE.available();
    Serial.println("Scanning done.");

  }
// once the address is found, the devices will be connected/
  else  if (peripheral.address() == "cb:f4:b7:9e:70:72") {
    Serial.print("Found ");
    Serial.print(peripheral.address());
    Serial.print(" '");
    Serial.print(peripheral.localName());
    Serial.print("' ");
    Serial.print(peripheral.advertisedServiceUuid());
    Serial.println();
    BLE.stopScan(); // the scanning process will be terminated.


    if (peripheral.connect()) {
      Serial.println("Connected");
    } else {
      Serial.println("Failed to connect!");
      return;
    }

    // discover peripheral attributes
    Serial.println("Discovering attributes ...");
    if (peripheral.discoverAttributes()) {
      Serial.println("Attributes discovered");
    } else {
      Serial.println("Attribute discovery failed!");
      peripheral.disconnect();
      return;
    }
  }
}
