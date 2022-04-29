// in this tab, the Receiver Gyro is passed through,
//where the value measured is the GyroAngleX.
void gyroscope() 
{
   
   mpu6050.update();

  recieverX  = mpu6050.getGyroAngleX();
  

  Serial.print("      X---R.. : ");Serial.println(mpu6050.getGyroAngleX());

 // Serial.print("Gyro after");
  
  }
  
