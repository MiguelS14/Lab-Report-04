/*
Main Theme :
    The main goal of this program is to make use of the joystick using analog values (0-1023) while using an output as a DC Motor to 
control its speed and its direction using polarity.
*/
  void setup() { // Program here runs once.
    Serial.begin(9600); // Begins the serial for infrared values to be read later.
    pinMode(3, OUTPUT); // Uses pin 3 as an output for the motor.
    pinMode(11, OUTPUT); // Uses pin 11 as an output for the motor.
  }

  void loop() { // Program here runs repeatedly.
    int joystick_X = analogRead(A0); // Uses the name "joystick_X" as a variable for the pin (A0) that is being read.

    int result_X = map(joystick_X, 0, 1023, 0, 3); // Maps the value of the X-Axis of the joystick from the Bit-value to Low, Middle and High Ranges.
    int Low = map(joystick_X, 0, 347, 255 , 0); // Low Range is mapped from 0 - 347 bits and the min and max of an 8 bit value.
    int Middle = map(joystick_X, 348, 695, 0, 255); // Middle Range is mapped from 348 - 695 bits and the min and max of an 8 bit value.
    int High = map(joystick_X, 696, 1023, 0, 255); // High Range is mapped from 696 - 1023 bits and the min and max of an 8 bit value.
    
    Serial.print("X Value : "); // Prints the label for the "X Value : ".
    Serial.print(result_X); //Prints the value of result_X that was mapped.
    Serial.print(" Joystick X : "); // Prints the label for the " Joystick X : ".
    Serial.print(joystick_X); //Prints the value of joystick_X or pin A0 that was read.
    Serial.print(" L RANGE : "); // Prints the label for the " Low RANGE : "
    Serial.print(Low); //Prints the value of Low Range that was mapped.
    Serial.print(" M RANGE : "); // Prints the label for the " Middle RANGE : "
    Serial.print(Middle); //Prints the value of Middle Range that was mapped.
    Serial.print(" H RANGE : "); // Prints the label for the " High RANGE : "
    Serial.println(High); //Prints the value of High Range that was mapped.
    switch(result_X){ // Makes a switch case function fo rthe following statements to switch from a condition to another e.g : Low, Middle, and High

      case 0: // This case is to provide the  statement and switch the condition in the Lowest range 0 - 347.
      analogWrite(3, Low); // if the button is at it's lowest range it will give the DC motor the value that the Low range mapped.
      analogWrite(11, 0); // the positive pin is not supplied power for it to run in Clockwise
      break; // Breaks the statements between case 0 and 1

      case 1: // This case is the default range if the motor is not running therefore the joysticks is at its default position.
      analogWrite(3, 0); // if joystick is at it's default position the motor does not run.
      analogWrite(11, 0); // if joystick is at it's default position the motor does not run.
      break; // Breaks the statements between case 1 and 2 
      
      case 2: // This case is to provide the  statement and switch the condition in the Average range 348 - 695.
      analogWrite(3, 0); // the positive pin is not supplied power for it to run in Counter Clockwise.
      analogWrite(11, High); // pin 11 uses the value of the mapped value of "int High = map(joystick_X, 696, 1023, 0, 255)"
      break; // Breaks the statements between case 2 and 3
      
      case 3: // This case is to provide the statement and switch the condition in the Highest range 696 - 1023.
      analogWrite(3, 0); // the positive pin is not supplied power for it to run in Counter Clockwise.
      analogWrite(11, High); // pin 11 uses the value of the mapped value of "int High = map(joystick_X, 696, 1023, 0, 255)"
      break; // Breaks the statements between case 3 and back to the first case to recheck the value.
    }
  }