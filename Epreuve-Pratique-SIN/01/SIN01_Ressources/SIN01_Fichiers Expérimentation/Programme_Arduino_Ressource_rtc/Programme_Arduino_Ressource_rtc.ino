#include <Wire.h>
#include "RTClib.h"

RTC_DS1307 rtc;

// Déclaration d'une variable concernant le nobre de jours écoulés
unsigned int diff_j;   

void setup () 
{
  Serial.begin(9600);
  if (!rtc.begin()) {
    Serial.println("RTC non détecté !");
    while (1);
  }
  // initialisation à la date de compilation
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));  
}

void loop () 
{
  DateTime now = rtc.now();
  Serial.print("Date actuelle : ");
  Serial.print(now.day());
  Serial.print('/');
  Serial.print(now.month());
  Serial.print('/');
  Serial.println(now.year());

  // Exemple de date précédente (à modifier)
  DateTime date_ancienne(2025, 8, 20, 0, 0, 0);
  TimeSpan diff = now - date_ancienne;
  diff_j = diff.days();
  Serial.print("Différence en jours : ");
  Serial.println(diff_j);
  delay(10000); // toutes les 10 secondes
}
