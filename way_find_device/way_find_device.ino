
#include <Arduino.h>
#include <Servo.h>
#include "Talkie.h"
#include "Vocab_US_Large.h"
#include "Vocab_Special.h"

Talkie voice;
Servo myservo;

int trigPin = 7;    // TRIG pin
int echoPin = 8;    // ECHO pin
float duration_us, distance_cm;

void setup() {
    Serial.begin(9600);
    myservo.attach(5);
    pinMode(2, OUTPUT);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);

}
void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(100);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration_us = pulseIn(echoPin, HIGH);
  distance_cm = 0.017 * duration_us;
    
  if (distance_cm < 60.00 ){
      
      digitalWrite(2,HIGH);
      delay(1500);
      digitalWrite(2,LOW);
      delay(1500);
      
      myservo.write(0);
      delay(1500);
      
      digitalWrite(trigPin, LOW);
      delayMicroseconds(100);
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      delayMicroseconds(10);
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      
      duration_us = pulseIn(echoPin, HIGH);
      distance_cm = 0.017 * duration_us;

      
      if (distance_cm < 60.00 ){
        digitalWrite(2,HIGH);
        delay(1500);
        digitalWrite(2,LOW);
      }
      
      else {
        digitalWrite(2,HIGH);
        delay(200);
        digitalWrite(2,LOW);
        delay(200);
        digitalWrite(2,HIGH);
        delay(200);
        digitalWrite(2,LOW);
      }

      delay(1500);
      
      myservo.write(90);
      delay(500);
      
      myservo.write(180);
      
      delay(1000);
      
      digitalWrite(trigPin, LOW);
      delayMicroseconds(100);
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      delayMicroseconds(10);
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      
      duration_us = pulseIn(echoPin, HIGH);
      distance_cm = 0.017 * duration_us; 

      
      if (distance_cm < 60.00 ){
        digitalWrite(2,HIGH);
        delay(1500);
        digitalWrite(2,LOW);
      }
      else {
        digitalWrite(2,HIGH);
        delay(200);
        digitalWrite(2,LOW);
        delay(200);
        digitalWrite(2,HIGH);
        delay(200);
        digitalWrite(2,LOW);

      }
      delay(1000);
    }
    myservo.write(90);
    delay(50);
}
