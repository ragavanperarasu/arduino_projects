#include <Servo.h>
Servo myservo;
void setup() {
  myservo.attach(9);
  Serial.begin(9600);
}

void loop() {
  if ((analogRead(A0) == 1023) && (analogRead(A1) < 700 && analogRead(A1) > 300)){
    myservo.write(0);
    Serial.println("right"); 
  }
  else if ((analogRead(A0) == 0)&&(analogRead(A1) < 800 && analogRead(A1) > 300)){
    myservo.write(180);
    Serial.println("left");
  }
  else {
    myservo.write(90);
    Serial.println("center");
  }
  delay(100);
}
