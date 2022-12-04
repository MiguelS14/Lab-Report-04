/*
Main theme :
    The goal of this program is to make use of the joystick using an 
    analog pin (a double-axis potentiometer) that  produces an output in the servo motor.
*/

#include <Servo.h> //includes the library for Servo

Servo myservo;  // create servo object to control a servo.

int potpin = A0;  // analog pin used to connect the joysticks X-Axis or Y-Axis
int val;    // variable to read the value from the analog pin

void setup() {
  myservo.attach(7);  // attaches the servo on pin 7 to the servo object
}

void loop() {
  val = analogRead(potpin);            // reads the value of the potentiometer in the joystick (value between 0 and 1023) as a bit value.
  val = map(val, 0, 1023, 0, 180);     // scale it for use with the servo (value between 0 and 180) with the use of map.
  myservo.write(val);                  // sets the servo position according to the scaled value with the value that is computed in the map() function.
  delay(15);                           // waits for the servo to get there.
}
