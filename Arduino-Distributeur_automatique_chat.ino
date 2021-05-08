#include <Stepper.h>

// Number of steps in one revolution of your motor.
// If your motor gives the number of degrees per step, divide that number into 360
// to get the number of steps (e.g. 360 / 3.6 gives 100 steps).
const int stepsPerRevolution = 2048; // 32*64 = 2048

// Pin for capactitive touch sensor
#define ctsPin 2 

// Initialize with pin sequence IN1-IN3-IN2-IN4 with 28BYJ-48 stepper motor
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
  // The speed at which the motor should turn in rotations per minute - a positive number
  myStepper.setSpeed(8);
}

void loop() {
  int ctsValue = digitalRead(ctsPin);
  
  if (ctsValue == HIGH){
    myStepper.step(stepsPerRevolution*4);

    reset();
  }
}

void reset() {
  // Pin 12 must be connected to Reset pin
  pinMode(12, OUTPUT);
}
