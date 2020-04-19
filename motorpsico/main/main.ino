int IN2 = 0;
int ENB = 3;
int IN1 = 7;
int EYESMOVELED = 8;
int EYESMOVE = 9;
int EYESLEDNEAR = 12;
int RECV_PIN = 10;

boolean sensorActive = false;
boolean previousSensorState = false;
#include "humtemp.h"
#include "eyes.h"
#include "IREye.h"

IRrecv irrecv(RECV_PIN);
IREye ireye(&irrecv, RECV_PIN);
int MinV = 75;
int calibrationTime = 30;

unsigned long StartTime = millis();
unsigned long CurrentTime = millis();
unsigned long ElapsedTime = CurrentTime - StartTime;
  
void setup() {
    // dht setup
  Serial.begin(9600);
  pinMode(RECV_PIN, INPUT);
  pinMode(EYESLEDNEAR, OUTPUT);
  pinMode(EYESMOVE, INPUT);
  digitalWrite(EYESMOVE, LOW);
//  for(int i = 0; i < calibrationTime; i++){
//    Serial.print(".");
//    delay(250);
//    Serial.print(".");
//    delay(250);
//    Serial.print(".");
//    delay(250);
//    Serial.print(".");
//    delay(250);
//  }
  
  Serial.println("");
  Serial.println("Sensor Calibration Completed");
  Serial.println("Sensor Reading Active");
  delay(50);
  sensorActive = false;
  previousSensorState = false;
  
  pinMode(EYESMOVELED, OUTPUT);
  // put your setup code here, to run once:
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.println(F("DHTxx test!"));
  dht.begin();
  ireye.setup();
}

void goFoward(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
    analogWrite(ENB, MinV + 20);
}

void goBackward(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
    analogWrite(ENB, MinV);
}

void stopGoing() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}

void loop() {
//  StartTime = millis();
//  CurrentTime = millis();
//  ElapsedTime = CurrentTime - StartTime;
  
  // put your main code here, to run repeatedly:
  //getDhtData();
//  while(ElapsedTime < 10000){
//    look();
//    CurrentTime = millis();
//    ElapsedTime = CurrentTime - StartTime;
//  }
  look();
  ireye.recieve();
  //ireye.emit();
  //goFoward();
  //delay(2*1000UL);
  //goBackward();
  //delay(10*1000UL);
  //stopGoing();
}
