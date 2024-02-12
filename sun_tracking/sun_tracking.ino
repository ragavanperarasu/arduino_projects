// This is Sun Tracking Project use Time based system

// Hardware Library file
#include <Servo.h>
#include <LiquidCrystal_I2C.h>

// Hardware Objects declaraction
Servo myservo;
LiquidCrystal_I2C lcd(0x27,16,2);

// Variables
int oneMinuteMillisecond = 50; // One minute value of milliseconds
int solarTimeStart = 5;        // Solar Panel Starting Time

// Custom char creation
byte deg[] = {
  B11100,
  B10100,
  B11100,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};

byte sunf[] = {
  B00000,
  B01100,
  B11110,
  B01100,
  B00000,
  B10000,
  B01000,
  B00111
};

byte suns[] = {
  B00000,
  B01100,
  B11110,
  B01100,
  B00000,
  B00001,
  B00010,
  B11100
};

byte slf[] = {
  B00000,
  B00110,
  B00110,
  B00110,
  B00000,
  B00000,
  B11111,
  B00000
};

byte sls[] = {
  B00000,
  B01100,
  B01100,
  B01100,
  B00000,
  B00000,
  B11111,
  B00000
};

void setup()
{
  myservo.attach(9);   // Servo motor Pin declaration
  lcd.init();                      
  lcd.backlight();
  
  pinMode(11, INPUT);  // Touch Sensor (up)
  pinMode(10, INPUT);  // Touch Sensor (ok)
  pinMode(2, OUTPUT);  // Buzzer Pin 

  // custom char object creation  
  lcd.createChar(0, deg);
  lcd.createChar(1, sunf);
  lcd.createChar(2, suns);
  lcd.createChar(3, slf);
  lcd.createChar(4, sls);
}


void loop()
{
  // Reset Time
  lcd.clear();
  solarTimeStart = 5;
  delay(1000);

  // Time change Entry condition
  if (digitalRead(10) == HIGH && digitalRead(11) == HIGH){
    
    lcd.setCursor(0,0);
    lcd.print("  Sun Traking   ");
    lcd.setCursor(14,0);
    lcd.write(1);
    lcd.setCursor(15,0);
    lcd.write(2);
    lcd.setCursor(0,1);
    lcd.print(" Time Reseting  ");
    delay(5000);

    // Time change loop
    while (true) {
      lcd.setCursor(0,0);
      lcd.print("Enter Time : ");
      lcd.setCursor(12,0);
      lcd.print(solarTimeStart);
      lcd.setCursor(0,1);
      lcd.print("Time-up set-ok ");

      // Time Increment Condition
      if (digitalRead(11) == HIGH) {
        solarTimeStart += 1;
      }

      // Time Update condition
      if (digitalRead(10) == HIGH) {
        break;
      }
      delay(500);
    }
    lcd.setCursor(0,0);
    lcd.print("  Time Update   ");
    lcd.setCursor(0,1);
    lcd.print("  Successfully  ");
    delay(2000);
  }

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("  Sun Traking   ");
  lcd.setCursor(14,0);
  lcd.write(1);
  lcd.setCursor(15,0);
  lcd.write(2);

  // Solar Panel Control loop
  while((4 < solarTimeStart) && (solarTimeStart < 19)){
    lcd.setCursor(0,1);
    lcd.print("Tim:");
    lcd.setCursor(4,1);
    lcd.print(solarTimeStart);

    lcd.setCursor(7,1);
    lcd.print("Ang:");

    // Solar Panel Angle Changing conditions....
    if((4 < solarTimeStart) && (solarTimeStart < 12)){
      if(solarTimeStart == 5){
        myservo.write(0);
        lcd.setCursor(11,1);
        lcd.print(0);
      }
      else if(solarTimeStart == 6){
        myservo.write(11);
        lcd.setCursor(11,1);
        lcd.print(14);
      }
      else if(solarTimeStart == 7){
        myservo.write(22);
        lcd.setCursor(11,1);
        lcd.print(28);
      }
      else if(solarTimeStart == 8){
        myservo.write(33);
        lcd.setCursor(11,1);
        lcd.print(42);
      }
      else if(solarTimeStart == 9){
        myservo.write(44);
        lcd.setCursor(11,1);
        lcd.print(56);
      }
      else if(solarTimeStart == 10){
        myservo.write(55);
        lcd.setCursor(11,1);
        lcd.print(70);
      }
      else{
        myservo.write(78);   // 11
        lcd.setCursor(11,1);
        lcd.print(66);
      }
    }
    else {
      if(solarTimeStart == 12){
        myservo.write(78);      // center
        lcd.setCursor(11,1);
        lcd.print(98);
      }
      else if(solarTimeStart == 13){
        myservo.write(95);
        lcd.setCursor(11,1);
        lcd.print(112);
      }
      else if(solarTimeStart == 14){
        myservo.write(112);
        lcd.setCursor(11,1);
        lcd.print(126);
      }
      else if(solarTimeStart == 15){
        myservo.write(129);
        lcd.setCursor(11,1);
        lcd.print(140);
      }
      else if(solarTimeStart == 16){
        myservo.write(146);
        lcd.setCursor(11,1);
        lcd.print(154);
      }
      else if(solarTimeStart == 17){
        myservo.write(163);
        lcd.setCursor(11,1);
        lcd.print(168);
      }
      else {
        myservo.write(180);
        lcd.setCursor(11,1);
        lcd.print(182);
      }
    }

    // Solar Panel Angle show Condition
    if((4 < solarTimeStart)&&(solarTimeStart < 12)){
      lcd.setCursor(14,1);
      lcd.print("E");
      lcd.setCursor(15,1);
      lcd.write(0);
    }
    else{
      lcd.setCursor(14,1);
      lcd.print("W");
      lcd.setCursor(15,1);
      lcd.write(0);
    }

    // Buzzer sound creation
    digitalWrite(2, HIGH);
    delay(500);
    digitalWrite(2, LOW);

    // Time increment loop (1 Hour)    
    for(int m = 0 ; m < 60 ; m++){
      delay(oneMinuteMillisecond);
    }

    // Time variable
    solarTimeStart++;
  }

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("  Sun Traking   ");
  lcd.setCursor(14,0);
  lcd.write(3);
  lcd.setCursor(15,0);
  lcd.write(4);
  lcd.setCursor(0,1);
  lcd.print("  Go to sleep  ");

  // Night to Midnight loop
  for(solarTimeStart ; solarTimeStart <= 24 ; solarTimeStart++){
    delay(oneMinuteMillisecond);
  }

  // Moring loop
  for(solarTimeStart = 1 ; solarTimeStart <  5; solarTimeStart++){
    delay(oneMinuteMillisecond);
  }
  
  delay(500);
  
}
