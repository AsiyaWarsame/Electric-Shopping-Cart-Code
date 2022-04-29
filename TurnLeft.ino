// This tab enables the TurnLeft function to be called,
//if the sender gryo turns more than 5 degree to the left.

void TurnLeft()
{
 
do{
 // Serial.print("Should go left ");
  servicef();
  gyroscope();
  
  left();
  
  }while(recieverX<x && recieverX >=25 && recieverX <=30);


}
