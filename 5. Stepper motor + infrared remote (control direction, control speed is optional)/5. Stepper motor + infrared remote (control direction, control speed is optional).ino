/*
Main Theme :
The main purpose of this program is to make use of the library of the Infrared Remote and Infrared Receiver combined with the use of the stepper motor and
to see the different rotations (Clockwise and Counter Clockwise) and the change of speed using volume down and up.
*/
#include "Stepper.h" //includes the stepper motors library to declare the pins.
#include "IRremote.h" //includes the IR Remote and the receivers library to the program.
/*----- Variables, Pins -----*/
#define STEPS  32   // Number of steps per revolution of Internal shaft.
int  Steps2Take;  // 2048 = 1 Revolution.
int receiver = 6; // Signal Pin of IR receiver to Arduino Digital Pin 6.

/*-----( Declare objects )-----*/
// Setup of proper sequencing for Motor Driver Pins.
// In1, In2, In3, In4 in the sequence 1-3-2-4.

Stepper small_stepper(STEPS, 8, 10, 9, 11);
IRrecv irrecv(receiver);    // create instance of 'irrecv'.
decode_results results;     // create instance of 'decode_results'.

void setup() // Program here runs once.
{ 
 Serial.begin(9600); // Begins the serial for infrared values to be read later.
  irrecv.enableIRIn(); // Start the receiver.
}
int direction = 2048; //sets 1 revolution to direction.
void loop() // Program here runs repeatedly.
{


if (irrecv.decode(&results)) // have we received an IR signal? (results can be printed in hex or decimal)

  {
       
    switch(results.value) // uses the values of the signals that are received into a switch case function to make conditions if different buttons are pressed in the IR Remote. e.g 0 and 1

    {

      case 16724175: // 1 Pressed CCW (Counter Clockwise).
      direction = 1;         
               break; // breaks case "16724175" and case "16718055" to separete statements inside.    
                      

      case 16718055: // 2 Pressed CW (Clockwise).
      direction = 0;
               break; // breaks case "16718055" and the end of the switch loop for the function to be checked once again. 
                  
                      
}
Serial.println(results.value); // Prints the value that the IR receiver received.
irrecv.resume(); // receive the next value
  }  
if(direction == 0) // if revolution is low/0 then the stepper motor rotates clockwise.
{
small_stepper.setSpeed(500); //Max seems to be <700 otherwise the stepper motor does not take another step.
Steps2Take  =  -10;  // Rotates CW
small_stepper.step(Steps2Take); // uses the variable "Steps2Take" in a value of -10 to rotate clockwise
}
else if(direction == 1) // the else if statement is if the revolution is high/1 then the stepper motor rotates counter-clockwise.
{
small_stepper.setSpeed(500); //Max seems to be <700 otherwise the stepper motor does not take another step.
Steps2Take  =  10;  // Rotates CCW
small_stepper.step(Steps2Take); // uses the variable "Steps2Take" in a value of 10 to rotate counter-clockwise
}
}/* --end main loop -- */
