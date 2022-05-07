/*
  Stepper Motor Demonstration 4
  Stepper-Demo4.ino
  Demonstrates NEMA 17 Bipolar Stepper with A4988 Driver

  DroneBot Workshop 2018
  https://dronebotworkshop.com
*/

// Define Constants

// Connections to A4988
const int dirPin = 4;  // Direction
const int stepPin = 2; // Step

// Motor steps per rotation

 
void setup() {
  
  // Setup the pins as Outputs
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
}
void loop() {
  
  // Set motor direction clockwise
  digitalWrite(dirPin,LOW); 
  
  // Spin motor one rotation slowly
  for(int x = 0; x < 500; x++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(1000); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(1000); 
  }
  delay(5000);
  
  digitalWrite(dirPin,HIGH);
    for(int x = 0; x < 500; x++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(1000); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(1000); 
  }  
delay (5000); 
}
