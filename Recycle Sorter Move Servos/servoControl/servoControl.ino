// Import the Arduino Servo library
#include <Servo.h> 

// Create a Servo object for each servo
Servo servos[3];
// User input for servo
int startbyte;       // start byte, begin reading input
int servo;           // which servo to pulse?
int pos = 0;       // position of servo

void setup() 
{ 
  // Attach each Servo object to a digital pin
  servos[0].attach(7);
  servos[1].attach(8);
  servos[2].attach(9);
  // Open the serial connection, 9600 baud
  Serial.begin(9600);
} 

void loop() 
{ 
  // Wait for serial input (min 2 bytes in buffer)
  if (Serial.available() > 1) {
    // Read the first byte
    startbyte = Serial.read();
    // If it's really the startbyte (255) ...
    if (startbyte == 255) {
      // ... then get the next byte
        servo = Serial.read();
        
      for (pos = 140; pos >= 60; pos -= 1) { // goes from 180 degrees to 0 degrees
        servos[servo].write(pos);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15ms for the servo to reach the position
      }
      delay(1000);
      for (pos = 60; pos <= 140; pos += 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        servos[servo].write(pos);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15ms for the servo to reach the position
      }
    }
  }
}

