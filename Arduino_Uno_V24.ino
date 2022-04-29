
#include<Servo.h>
#include<AFMotor.h>

int p8, p9, p10;
char var = 0;
int speed1=120;
int speed2=120;
int speed3=120;
int speed4=120;

AF_DCMotor Motor1(1, MOTOR12_1KHZ);
AF_DCMotor Motor2(2, MOTOR12_1KHZ);
AF_DCMotor Motor3(3, MOTOR34_1KHZ);
AF_DCMotor Motor4(4, MOTOR34_1KHZ);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode (2, INPUT);
  pinMode (13, INPUT);
  pinMode(A5, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  p8 = digitalRead(2);
  p9 = digitalRead(13);
  p10 = analogRead(A5);

  Serial.print ("PIN 2   ");
  Serial.print(p8);

  Serial.print ("        PIN 13    ");
  Serial.print(p9);


  Serial.print ("       PIN A5    ");
  Serial.println(p10);

  // setting the condition

  if ((p8 == 0) && (p9 == 0) && (p10 < 10)) {


    pause();
   // delay(4000);
  }

  else if ((p8 == 0) && (p9 == 0) && (p10 > 10)) {

    forward();
  //  delay(4000);
    
  }

  //backward condition
  else if ((p8 == 0) && (p9 == 1) && (p10 < 10)) {

    backward();
   // delay(4000);


  }

  else if ((p8 == 0) && (p9 == 1) && (p10 > 10)) {

    left();
   // delay(4000);


  }

  else if ((p8 == 1) && (p9 == 0) && (p10 < 10)) {

    right();
   // delay(4000);


  }

  else
  {
    pause();
  }

}
