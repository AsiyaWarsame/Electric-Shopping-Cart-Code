// This tab contains the ultrasonic sensor.

int sonar_sensor() {

  delay(50);// wait 50ms between pings.
  unsigned int distance = sonar.ping_cm(); //send ping, get ping in microseconds (uS).
  //Serial.print("Ping:   ");
  Serial.print("distance  ");
  Serial.println(distance);


  // currently, this code is only running with the ultrasonic sensor and the infrared when they are both ZERO.
  //
  return distance;

}
