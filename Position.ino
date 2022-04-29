//This tab contains the trolley's movement including forward, left and right movement.



void positions()
{
  //the value of the power.
if(peripheral.rssi() < -55  ) {
 forward();
                  
           gyroscope();
                
           if ( x >5)
           {    
                TurnLeft(); //calling the TurnLeft function.
           }
                
            else if ( x <-5)
           {    
                TurnRight(); //calling the TurnRight function.
           } 

            else if (x> 65 || x < -65 )  // the optimum angle turning point.
           { 
            delay (100);
            Serial.print("delay 1ms"); // adding a delay.
            forward();
            
            } 
              
   }

}
  
  
  
