/* Example sketch to control a stepper motor with L298N motor driver, Arduino UNO and Stepper.h library. More info: https://www.makerguides.com 

Example code and instruction here: https://www.makerguides.com/l298n-stepper-motor-arduino-tutorial/
*/

// Include the Stepper library:
#include <Stepper.h>

// Define number of steps per revolution:
const int stepsPerRevolution = 200;

// Initialize the stepper library on pins 8 through 11:
Stepper myStepper = Stepper(stepsPerRevolution, 8, 9, 10, 11);

void setup() {
  // Set the motor speed (RPMs):
  myStepper.setSpeed(25); //was originally 100
  pinMode(13, OUTPUT); // This is stepper enable to stop the hold function which draws ~700mA - just enable hold when moving or turning only will save a lot of power 
}

void loop() {
  // Step one revolution in one direction:
  digitalWrite(13, HIGH);
  myStepper.step(200);
  digitalWrite(13, LOW);

  delay(2000);

  // Step on revolution in the other direction:
  digitalWrite(13, HIGH);
  myStepper.step(-200);
  digitalWrite(13, LOW);

  delay(2000);
}
