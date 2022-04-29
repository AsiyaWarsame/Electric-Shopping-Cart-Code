void right()
{
 
  
  Motor1.setSpeed(speed1);
    Motor1.run(FORWARD); //Initially this as going backward
    Motor2.setSpeed(speed2);
    Motor2.run(FORWARD);  //and this one was also going backward.
    Motor3.setSpeed(speed3);
    Motor3.run(FORWARD); // therefore, i have swicth around the direction
    Motor4.setSpeed(speed4);
    Motor4.run(FORWARD);
  
  
  }
