void serialEvent() {
   //when u read the value from the serial, they are char so u use casting to convert the char value into integers.
  //var = Serial.read();
   var=Serial.read();
   Serial.print("Var   ");
   //charcaters 0 is the ascii of 48
   Serial.println(var);
}
