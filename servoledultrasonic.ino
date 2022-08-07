#include <Servo.h> // Include the Servo library 
Servo Servo1; // Create a servo object
int ledPin = 4;
const int trigPin = 2;
const int echoPin = 3;

long duration;
int distance;

void setup() { 
   // We need to attach the servo to the used pin number 
   Servo1.attach(5);
   pinMode(2, OUTPUT); // Trigger Pin
   pinMode(3, INPUT); // Echo Pin
   pinMode(4, OUTPUT); // LED Pin
   Serial.begin(9600);
}

void loop() {
  Servo1.write(0); // sets rotation to 0 degree
  digitalWrite(4, LOW); // sets LED pin to stay OFF
  if(distance <= 50){ // if detect range of less than 50 cm
  Servo1.write(180); // turns servo 180 degree
  digitalWrite(4, HIGH); // sets LED pin to go ON
  }
  digitalWrite(2, HIGH); // Trigger Pin set to detect movement
  delayMicroseconds(2); // delays for 2 microseconds
  digitalWrite(3, HIGH); // Echo Pin creates a response
  delayMicroseconds(5);
  digitalWrite(2, LOW); // Trigger Pin trigger pin goes back to idle position
  duration = pulseIn(3, HIGH); // Echo Pin
  distance = duration*0.034/2;
 }
