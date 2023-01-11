#include <Servo.h>

const int TRIG_PIN = 9;
const int ECHO_PIN = 8;
const int MOTOR_1_FORWARD_PIN = 3;
const int MOTOR_1_BACKWARD_PIN = 4;
const int MOTOR_2_FORWARD_PIN = 5;
const int MOTOR_2_BACKWARD_PIN = 6;

void setup() {
  
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  
  pinMode(MOTOR_1_FORWARD_PIN, OUTPUT);
  pinMode(MOTOR_1_BACKWARD_PIN, OUTPUT);
  pinMode(MOTOR_2_FORWARD_PIN, OUTPUT);
  pinMode(MOTOR_2_BACKWARD_PIN, OUTPUT);
}

void loop() {
  
  moveBackwardUntilDistance(10);
}

void moveBackwardUntilDistance(int distance) {
  while (true) {
    
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    while (digitalRead(ECHO_PIN) == LOW);

    long startTime = micros();

    
    while (digitalRead(ECHO_PIN) == HIGH);

    long endTime = micros();

    int duration = endTime - startTime;
    float distanceCm = duration / 2.0 / 29.1;

    if (distanceCm < distance) {
      stop();
      break;
    }

    moveBackward();
  }
}

void moveBackward() {
  digitalWrite(MOTOR_1_BACKWARD_PIN, HIGH);
  digitalWrite(MOTOR_2_BACKWARD_PIN, HIGH);
}

void stop() {
  digitalWrite(MOTOR_1_FORWARD_PIN, LOW);
  digitalWrite(MOTOR_1_BACKWARD_PIN, LOW);
  digitalWrite(MOTOR_2_FORWARD_PIN, LOW);
  digitalWrite(MOTOR_2_BACKWARD_PIN, LOW);
}
