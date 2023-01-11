#include <Servo.h>  // Include the Servo library

Servo leftMotor;   // Declare a Servo object for the left motor
Servo rightMotor;  // Declare a Servo object for the right motor

const int REVERSE_SPEED = 160;  // Set the reverse speed

void setup() {
  leftMotor.attach(9);  
  rightMotor.attach(10);  

  leftMotor.write(REVERSE_SPEED);  // Set the left motor to the reverse speed
  rightMotor.write(REVERSE_SPEED);  // Set the right motor to the reverse speed
}

void loop() {
  // The car will continue to move in reverse until the sketch is stopped
}
