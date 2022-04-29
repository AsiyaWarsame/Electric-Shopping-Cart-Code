// the pause function is called when the sensor senses an object less than 40cm.
//the pause function instruct the robot to stop, while waiting for the object
//to be cleared out of the path.

void pause()
{

                    digitalWrite (dig2, LOW);
                    digitalWrite (dig13, LOW);
                    digitalWrite (digA5, LOW);
                    //Serial.println ("stop");
  
  }
