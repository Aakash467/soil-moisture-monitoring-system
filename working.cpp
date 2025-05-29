#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x26,16,2); 

const int soilMoisturePin = A0;
const int blueLEDPin = 2;
const int orangeLEDPin = 3;
const int redLEDPin = 4;
const int buzzerPin = 5;

void setup() {
  lcd.init();
  lcd.backlight();
  
  pinMode(blueLEDPin, OUTPUT);
  pinMode(orangeLEDPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  
  lcd.setCursor(0, 0);
  lcd.print("Moisture:");
}

void loop() {
  int moisture = analogRead(soilMoisturePin);
  
  lcd.setCursor(0, 1);
  lcd.print("Moist: " + String(moisture) + "   ");

  if (moisture > 500) {
    digitalWrite(blueLEDPin, HIGH);
    digitalWrite(orangeLEDPin, LOW);
    digitalWrite(redLEDPin, LOW);
  } 
  else if (moisture >= 151) {
    digitalWrite(blueLEDPin, LOW);
    digitalWrite(orangeLEDPin, HIGH);
    digitalWrite(redLEDPin, LOW);
  } 
  else {
    digitalWrite(blueLEDPin, LOW);
    digitalWrite(orangeLEDPin, LOW);
    digitalWrite(redLEDPin, HIGH);
    tone(buzzerPin, 1000);
    delay(1000);
    noTone(buzzerPin);
  }

  delay(1000);
}
