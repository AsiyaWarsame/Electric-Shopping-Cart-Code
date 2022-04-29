// This tab enables the TurnRight function to be called,
//if the sender gryo turns more than -5 degree to the left.

void TurnRight()
{
 
do{
  //Serial.print("Should go right ");
  servicef();
  gyroscope();
  
  right();
  
  }while(recieverX<x && recieverX >=-25 && recieverX <=-30);


}

//  Serial.print("Should go Left ");
//  if (recieverX >= -5 && recieverX <= 5)
//  
//  { Serial.print("Should stop ");
//    pause();
//  
//    }
