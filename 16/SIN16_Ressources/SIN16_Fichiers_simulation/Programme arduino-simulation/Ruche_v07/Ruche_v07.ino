//
//    FILE: HX_is_ready.ino
//  AUTHOR: Rob Tillaart
// PURPOSE: HX711 demo
//     URL: https://github.com/RobTillaart/HX711


#include "HX711.h"
#include <Wire.h>
#include "arduino.h"
// #include <LiquidCrystal_I2C.h>
#include "rgb_lcd.h"
HX711 scale;

//  adjust pins if needed
const int  dataPin = A0;    // A0 pin 14   -  2
const int  clockPin = A1;   // A1 pin 15   -3
const int ledPin = 8;   // the number of the LED pin
int ledState = LOW;  // ledState used to set the LED
const int tareButton = 7;
// Adresse I2C (souvent 0x27 ou 0x3F)
//LiquidCrystal_I2C lcd(0x27, 16, 2); // ou (0x27, 20, 4)
//LiquidCrystal_I2C lcd(0x3E, 16, 2); // ou (0x27, 20, 4)
rgb_lcd lcd;

void setup()
{
  Wire.begin();
  Serial.begin(9600);
  Serial.println("Ruche BAC");
   Serial.println();

  scale.begin(dataPin, clockPin);
  //scale.set_gain(128);

  pinMode(ledPin, OUTPUT);
  pinMode(tareButton, INPUT);


  //scale.set_scale(1);               //  Si on veut faire la calibaration = 1.
  scale.set_scale(442540/10);         //  [Valeur_brute_CAN avec scale.set_scale(1)] /  Poids_reel

  lcd.begin(16,2);
  //lcd.backlight(); // Active le rétroéclairage
  lcd.setRGB(250, 255, 0); // couleur verte
  //lcd.setCursor(0, 0);
  //lcd.print("Poids:");
}


void loop()
{
  if (digitalRead(tareButton) == HIGH) 
  {
    scale.tare(50);   // Tare :moyenne sur 10 valeurs si Poids = 0
    Serial.println("Tare manuelle effectuée !");
    lcd.clear();
    lcd.setRGB(55, 50, 250); // couleur 
    lcd.setCursor(0, 0);
    lcd.print("-- RAZ du Poids--");
    delay(5000);
  }
  if (scale.is_ready())
  {
    float poids = scale.get_units(1); // lecture HX711
    Serial.println(poids);
    if (poids>25)
      {
        ledState = HIGH;
        lcd.setRGB(255, 50, 50); // couleur 
      }
      else 
      {
        ledState = LOW;
        lcd.setRGB(50, 250, 50); // couleur 
      }
          // set the LED with the ledState of the variable:
    digitalWrite(ledPin, ledState);


    lcd.clear();

    lcd.print("Poids:");
    lcd.setCursor(8, 0);
    lcd.print(poids, 1); // affiche avec 1 décimale
    lcd.print(" kg");


    delay(500);


  }
}


//  -- END OF FILE --
