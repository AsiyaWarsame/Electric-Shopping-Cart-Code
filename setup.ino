void Setupf()
{
  if (!BLE.begin()) {
    Serial.println("* Starting BLE module failed!");
    while (1);
  }
  BLE.setLocalName("Arduino XYZT (Central)");
  Serial.println("Arduino XYZT (Central)");
  Serial.println("Scanning... ");

  //BLE.advertise();
  BLE.scan();
  Serial.println("Scanning done.");

  pinMode (dig2, OUTPUT);
  pinMode (dig13, OUTPUT);
  pinMode (digA5, OUTPUT);
}
