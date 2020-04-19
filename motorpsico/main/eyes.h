/*
 * created by Rui Santos, https://randomnerdtutorials.com
 * 
 * Complete Guide for Ultrasonic Sensor HC-SR04
 *
    Ultrasonic sensor Pins:
        VCC: +5VDC
        Trig : Trigger (INPUT) - Pin11
        Echo: Echo (OUTPUT) - Pin 12
        GND: GND
 */
#include "timeMachine.h"

int trigPin = 4;    // Trigger
int echoPin = 5;    // Echo
long duration, cm, inches;
unsigned long motionMutex = millis();
void look() {
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(15);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  // Convert the time into a distance
  cm = (duration/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
  inches = (duration/2) / 74;   // Divide by 74 or multiply by 0.0135
  int moving = digitalRead(EYESMOVE);
  if(moving == HIGH)
  {
    sensorActive = true;
  }
  if(moving == LOW)
  {
    sensorActive = false;
  }
  if(sensorActive != previousSensorState)
  {
    if(sensorActive == true)
    {
      previousSensorState = sensorActive;
      digitalWrite(EYESMOVELED, HIGH);
      Serial.println("MotionDetected");
    }
    if(sensorActive == false)
    {
      digitalWrite(EYESMOVELED, LOW);
      previousSensorState = sensorActive;
    }
    delay(50);
  }
  if(cm < 10){
    digitalWrite(EYESLEDNEAR, HIGH);
  } else {
    digitalWrite(EYESLEDNEAR, LOW);
  }
  
  //delay(2*1000UL);
}
