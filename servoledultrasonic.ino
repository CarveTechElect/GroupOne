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
  ultra();
  Servo1.write(0);
  digitalWrite(4, LOW);
  if(distance <= 50){
  Servo1.write(180);
  digitalWrite(4, HIGH);
  }
}
 
void ultra(){
  digitalWrite(2, HIGH); // Trigger Pin
  delayMicroseconds(2);
  digitalWrite(3, HIGH); // Echo Pin
  delayMicroseconds(5);
  digitalWrite(2, LOW); // Trigger Pin
  duration = pulseIn(3, HIGH); // Echo Pin
  distance = duration*0.034/2;
  }
