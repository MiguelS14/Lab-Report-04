/*
Main Theme:
    The goal of this circuit is to make use of the output as a unipolar stepper motor and to adjust the speed and direction using an input as a joystick in an arduino UNO.
*/
 
// include Arduino stepper motor library
#include <Stepper.h>
 
// define number of steps per revolution
#define STEPS 32
 
// define stepper motor control pins
#define IN1  8 // defines IN1 as pin 8
#define IN2  9 // defines IN2 as pin 9
#define IN3  10 // defines IN3 as pin 10
#define IN4  11 // defines IN4 as pin 11
 
// initialize stepper library
Stepper stepper(STEPS, IN4, IN2, IN3, IN1); // sets the inputs from the definition it was set on the pins.
 
// joystick pot output is connected to Arduino A0
#define joystick  A0 // defines the A0 pin as a component named "joystick".
 
void setup() // Program here runs once.
{
  pinMode(6,INPUT); // Sets pin 6 as an input.
}
 int shook = 0; // sets a variable for 0 named "shook".
void loop() // Program here runs repeatedly.
{
  shook = digitalRead(6); 
  if(shook == 0){ // if pin 6 reads 0 then it will read the value of A0.
  // read analog value from the potentiometer.
  int val = analogRead(joystick); //It will read the value of A0 if pin 6 is low/off.
 
  // if the joystic is in the middle ===> stop the motor
  if(  (val > 500) && (val < 523) ) // if the value is more than 500 and less than 523 the stepper motor should be off.
  {
    digitalWrite(IN1, LOW); // Sets pin 8 as low/off.
    digitalWrite(IN2, LOW); // Sets pin 9 as low/off.
    digitalWrite(IN3, LOW); // Sets pin 10 as low/off.
    digitalWrite(IN4, LOW); // Sets pin 11 as low/off.
  }
  else // else statement if statement does not verify as true.
  {
    // move the motor in the first direction.
    while (val >= 523) // while the value is more than or equal to 523 it must use the following statements:
    {
    
      int speed_ = map(val, 523, 1023, 5, 1000); //uses a variable named speed_ to map the speed between 5 and 500 rpm.
      
      stepper.setSpeed(speed_); // set motor speed.
 
      
      stepper.step(1); // move the motor (1 step).
 
      val = analogRead(joystick); // name "val" is equivalent to value of "analogRead(joystick)"
    }
 
  
    while (val <= 500) // while the value is less than or equal to 500 it must use the following statements:
    {
      int speed_ = map(val, 500, 0, 5, 1000); //uses a variable named speed_ to map the speed between 5 and 500 rpm.
      // set motor speed
      stepper.setSpeed(speed_); // sets the speed using the variable "speed_" from the mapped value or move the motor in the other direction
 
      
      stepper.step(-1); // move the motor (1 step)
 
      val = analogRead(joystick); // Reads the analog value of pin A0 or as the variable joystick.
    }
 
  }
  }
}
