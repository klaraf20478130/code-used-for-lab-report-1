#include <Servo.h> 
#include <Ultrasonic.h> // add ultrasonic library

#define servoPin 4 
Servo myservo;
float steeringAngle;

#define enA 5   
#define enB 6   

#define INa A0  
#define INb A1  
#define INc A2  
#define INd A3  

#define trigPin 7 // ultrasonic sensor trig pin
#define echoPin 8 // ultrasonic sensor echo pin

Ultrasonic ultrasonic(trigPin, echoPin);

byte speedSetting = 0; 

void setup() {
  myservo.attach(servoPin);  

  pinMode(INa, OUTPUT);
  pinMode(INb, OUTPUT);
  pinMode(INc, OUTPUT);
  pinMode(INd, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);   

  Serial.begin(9600);

  speedSetting = 255;
  motors(speedSetting, speedSetting); 
  Serial.print("Motor Speeds: ");
  Serial.println(speedSetting); 
}

void loop() {
  myservo.write(89);
  goBackwards(); //function

  long distance = ultrasonic.distanceRead(); // read distance from ultrasonic sensor
  if (distance < 10) { 
    stopMotors(); // function to stop the motors
  }
  delay(100);
}

void motors(int leftSpeed, int rightSpeed) {
  analogWrite(enA, leftSpeed);
  analogWrite(enB, rightSpeed);
}

void goBackwards() {
  digitalWrite(INa, LOW);
  digitalWrite(INb, HIGH);
  digitalWrite(INc, LOW);
  digitalWrite(INd, HIGH);
}

void stopMotors(){
  analogWrite(enA, 0); 
  analogWrite(enB, 0);
}
