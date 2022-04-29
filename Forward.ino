void forward()
{
 
  //the motor's speed are set at 120.
  Motor1.setSpeed(speed1);
    Motor1.run(FORWARD); 
    Motor2.setSpeed(speed2);
    Motor2.run(FORWARD);  
    Motor3.setSpeed(speed3);
    Motor3.run(BACKWARD); 
    Motor4.setSpeed(speed4);
    Motor4.run(BACKWARD);
  
  
  }
