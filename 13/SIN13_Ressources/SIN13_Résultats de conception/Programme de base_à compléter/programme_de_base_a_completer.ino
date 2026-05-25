#include <Wire.h>
#include "rgb_lcd.h"
// Initialisation de l'écran LCD RGB Grove
rgb_lcd lcd;
const int pinUltrasons = 7;
// Température ambiante (à modifier en ajoutant la partie définition des variables du capteur de température choisi)
float temperature = 20.0; // en degrés Celsius

void setup() {
  Serial.begin(9600);
  pinMode(pinUltrasons, OUTPUT);
  digitalWrite(pinUltrasons, LOW);

  lcd.begin(16, 2);
  lcd.setRGB(0, 128, 255);
  lcd.setCursor(0, 0);
  lcd.print("Distance:");
}

void loop() {
  // Ajouter la partie mesure de la température avec le capteur de tempétature choisi
 
  // Envoi d'une impulsion ultrasonique (10 µs)  
  long temps;
  float distance, vitesseSon;
  // Envoi impulsion ultrasonique
  pinMode(pinUltrasons, OUTPUT);
  digitalWrite(pinUltrasons, LOW);
  delayMicroseconds(2);
  digitalWrite(pinUltrasons, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinUltrasons, LOW);

  // Réception de l'écho
  pinMode(pinUltrasons, INPUT);
  temps = pulseIn(pinUltrasons, HIGH); // temps d'aller-retour en microsecondes

  /*
   * compléter la ligne suivante :
   * Calculer la vitesse du son en fonction de la température :
   * Formule : vitesse = 331.3 + 0.606 × température (en m/s)
   */
  vitesseSon = 343.0; // ← à remplacer par la formule

// Calcul distance (cm)
  float offset = 2.0;
  distance = (temps * (vitesseSon * 100 / 1000000)) / 2 + offset;

  // Affichage sur LCD
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature, 1);
  lcd.print(" C   "); // Espaces pour effacer

  lcd.setCursor(0, 1);
  lcd.print("Dist: ");
  lcd.print(distance, 1);
  lcd.print(" cm  "); // Espaces pour effacer

  // Affichage sur port série
  Serial.print("Temp: ");
  Serial.print(temperature);
  Serial.print(" C, Distance : ");
  Serial.print(distance, 1);
  Serial.println(" cm");

  delay(500);
}
