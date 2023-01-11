#include <Arduino.h>
#include <Encoder.h>
//set the pins for the encoders
const int encoder1PinA = 2; //this is the pin for encoder 1
const int encoder1PinB = 3;
const int encoder2PinA = 4;// this is the pin for encoder 2
const int encoder2PinB = 5;

Encoder encoder1(encoder1PinA, encoder1PinB);
Encoder encoder2(encoder2PinA, encoder2PinB);
//set the number of coun ts per reverlution
const float encoderCountsPerRevolution = 360.0;
const float gearRatio = 20.0;
const float wheelDiameter = 70.0; // millimeters

void setup() {
  Serial.begin(9600);
}

void loop() {
  long encoder1Count = encoder1.read();
  long encoder2Count = encoder2.read();

  float distance1 = (encoder1Count / encoderCountsPerRevolution) * (wheelDiameter * PI) * gearRatio;
  float distance2 = (encoder2Count / encoderCountsPerRevolution) * (wheelDiameter * PI) * gearRatio;

  Serial.print("Distance 1: ");
  Serial.print(distance1);
  Serial.print(" mm, Distance 2: ");
  Serial.println(distance2);

  delay(1000);
}
