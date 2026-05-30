#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); 

void setup() {
  Serial.begin(9600);
  lcd.init();           // Initialise l'afficheur LCD
  lcd.backlight();      // Active le rétroéclairage
}

void loop() {
  int num = analogRead(A0);
  float voltage = num * (5.0 / 1023.0);
  float temperature = voltage * 100.0;

  Serial.print("Valeur numérique ");
  Serial.print(num);
  Serial.print(" | Tension: ");
  Serial.print(voltage, 3);
  Serial.print(" V | Température: ");
  Serial.print(temperature);
  Serial.println(" °C");

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature, 1); // Affiche 1 chiffre après la virgule
  lcd.print(" C");

  delay(1000);
}
