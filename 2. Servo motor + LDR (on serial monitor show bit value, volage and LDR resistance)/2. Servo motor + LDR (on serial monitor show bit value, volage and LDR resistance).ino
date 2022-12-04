/*
Main theme :
    The goal of this program is to make use of the Light Dependent Resistor (Photoelectric Resistor thats reacts to light that changes the amount of its resistance) to show an output in the servo motor (0 - 180 degrees).
*/
#include <Servo.h> // include the library for the servo motor.

Servo myservo; // create servo object to control a servo.

int servo_range; //creates a variable
int R_reference = 1000; // Creates a value (1k Ohms) for the reference resistor to compute the amount of resistance the LDR has.

void setup() { //setups the code here, to run once.

  Serial.begin(9600); // Begins the serial to produce texts in the serial monitor.

  myservo.attach(7); // a command that came from the library to attach the signal pin for the servo motor.
}

void loop() { // Codes that are in this block runs repeatedly.


  int val = analogRead(A0); // sets the value of analog pin A0 as a variable "val".
  float volt = val/204.6; // Converts bit value to voltage.
  int volt_a = volt*1000; // uses a variable named "volt_a" to be later used in the map function to find out the range of the servo motor.
  servo_range = map(volt_a, 0, 4750, 0, 180); // maps the value in degrees of how much the servo will turn.
  
  float resistance = (R_reference*((5/volt)-1)); //Creates a variable named "resistance" and computes the value of the Light Dependent Resistor.
  
  Serial.print("Voltage : "); // Prints the label of the voltage value.
  Serial.print(volt); // Prints the voltage value.
  Serial.print(" V    "); // Prints the symbol for voltage.

  Serial.print("Bit Value : "); // Prints the label of the bit value.
  Serial.print(val); // Prints the bit value.
  Serial.print(" bits    "); // Prints the symbol for bits.

  Serial.print("Resistance : "); // Prints the label of the resitance of the LDR (Photoresistor sensor).
  Serial.print(resistance); // Prints the bit value.
  Serial.println(" Ohms"); // Prints the symbol for resistance.
  
  
  myservo.write(servo_range); //writes the range of how much the servo needs to turn. (0-180).
}

