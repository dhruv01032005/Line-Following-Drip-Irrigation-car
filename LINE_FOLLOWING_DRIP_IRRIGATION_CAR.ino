#include <AFMotor.h>
#include <Servo.h>  
#define lefts A0
#define rights A1

AF_DCMotor motor1(1, MOTOR12_1KHZ); 
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);
Servo name_servo;   
int servo_position = 0;

void setup() {
  motor1.setSpeed(180);
  motor2.setSpeed(180);
  motor3.setSpeed(180);
  motor4.setSpeed(180);
  pinMode(lefts,INPUT);
  pinMode(rights,INPUT);
  name_servo.attach(10);
  Serial.begin(9600);
}

void loop(){
  Serial.println(analogRead(lefts));
  Serial.println(analogRead(rights));
  for(servo_position = 0; servo_position<=120;servo_position+=2){
    Serial.println(analogRead(lefts));
    Serial.println(analogRead(rights));
    if(analogRead(lefts)<=350 && analogRead(rights)<=350){
      //Forward
      motor1.run(FORWARD);
      motor2.run(FORWARD);
      motor3.run(FORWARD);
      motor4.run(FORWARD);
    }
    //line detected by left sensor
    else if(analogRead(lefts)<=350 && !analogRead(rights)<=350){
      //turn left
      motor1.run(FORWARD);
      motor2.run(FORWARD);
      motor3.run(BACKWARD);
      motor4.run(BACKWARD);
      
    }
    //line detected by right sensor
    else if(!analogRead(lefts)<=350 && analogRead(rights)<=350){
      //turn right
      motor1.run(BACKWARD);
      motor2.run(BACKWARD);
      motor3.run(FORWARD);
      motor4.run(FORWARD);
    
    }
    //line detected by both
    else if(!analogRead(lefts)<=350 && !analogRead(rights)<=350){
      //stop
      motor1.run(RELEASE);
      motor2.run(RELEASE);
      motor3.run(RELEASE);
      motor4.run(RELEASE);
    
    }
    name_servo.write(servo_position);
    delay(25);

  }
  //line detected by none
  if(analogRead(lefts)<=350 && analogRead(rights)<=350){
    //Forward
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
  }
  //line detected by left sensor
  else if(analogRead(lefts)<=350 && !analogRead(rights)<=350){
    //turn left
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(BACKWARD);
    motor4.run(BACKWARD);
    
  }
  //line detected by right sensor
  else if(!analogRead(lefts)<=350 && analogRead(rights)<=350){
    //turn right
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
   
  }
  //line detected by both
  else if(!analogRead(lefts)<=350 && !analogRead(rights)<=350){
    //stop
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    motor4.run(RELEASE);
   

  }
  for(servo_position = 120; servo_position >= 0; servo_position-=2){
    Serial.println(analogRead(lefts));
    Serial.println(analogRead(rights));
    if(analogRead(lefts)<=350 && analogRead(rights)<=350){
      //Forward
      motor1.run(FORWARD);
      motor2.run(FORWARD);
      motor3.run(FORWARD);
      motor4.run(FORWARD);
    }
    //line detected by left sensor
    else if(analogRead(lefts)<=350 && !analogRead(rights)<=350){
      //turn left
      motor1.run(FORWARD);
      motor2.run(FORWARD);
      motor3.run(BACKWARD);
      motor4.run(BACKWARD);
      
    }
    //line detected by right sensor
    else if(!analogRead(lefts)<=350 && analogRead(rights)<=350){
      //turn right
      motor1.run(BACKWARD);
      motor2.run(BACKWARD);
      motor3.run(FORWARD);
      motor4.run(FORWARD);
    
    }
    //line detected by both
    else if(!analogRead(lefts)<=350 && !analogRead(rights)<=350){
      //stop
      motor1.run(RELEASE);
      motor2.run(RELEASE);
      motor3.run(RELEASE);
      motor4.run(RELEASE);
    
    }
    name_servo.write(servo_position);
    delay(25);
  }
}
