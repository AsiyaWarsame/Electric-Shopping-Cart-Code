// This tab contain the forward movement,
// where this function is called when the RSSI is less than -55dBm.
void forward()
{

                    digitalWrite (dig2, LOW);
                    digitalWrite (dig13, LOW);
                    digitalWrite (digA5, HIGH);
                    Serial.println ("Forward");
  
  }
