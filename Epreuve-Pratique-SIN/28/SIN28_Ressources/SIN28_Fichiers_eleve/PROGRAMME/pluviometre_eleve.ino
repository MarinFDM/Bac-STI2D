#include "rgb_lcd.h"                         // https://wiki.seeedstudio.com/Grove-16x2_LCD_Series/
rgb_lcd lcd;
const int colorR = 255;
const int colorG = 0;
const int colorB = 0;

const int pinPluviometre = ................;          // compléter le numéro de broche choisi pour le pluviomètre
volatile int comptage = 0;             // Compteur de basculements
unsigned long dernierTemps = 0;        // Pour l'anti-rebond
const unsigned long delaiAntiRebond = 500;  // 500 ms de délai anti-rebond

#define VALEUR_PLUVIOMETRE ......................... // compléter valeur en mm d'eau à chaque bascule d'auget.

void setup() {
  Serial.begin(9600);
//  Compléter les 2 informations manquantes
  attachInterrupt(digitalPinToInterrupt(.......................), interruptionPluie, ....................);

// Initialisation de l'afficheur
  lcd.begin(16, 2);
  lcd.setRGB(colorR, colorG, colorB);
  lcd.print("STATION METEO");
  delay(1000);
  lcd.clear();
}

void loop() {
  // millis() contient le temps écoulé depuis le lancement du programme.
  // Affiche le cumul de précipitations toutes les 5 secondes
  static unsigned long dernierAffichage = 0;
  if (millis() - dernierAffichage >= 5000) {
    dernierAffichage = millis();
    float mmPluie = comptage * VALEUR_PLUVIOMETRE; //1 basculement = 0,2794 mm de pluie
    
    //Affichage sur moniteur série
    Serial.print("Pluie accumulée : ");
    Serial.print(mmPluie, 2);
    Serial.println(" mm");
    
    //Affichage sur l'écran 2 lignes
    lcd.setCursor(0, 0);
    lcd.print("Pluie en mm :");
    lcd.setCursor(0, 1);
    lcd.print(mmPluie);
    lcd.print(" mm.");
  }
}

// Fonction appelée à chaque front descendant sur l'entrée (basculement ILS)
void interruptionPluie() {
  unsigned long maintenant = millis();
  if (maintenant - dernierTemps > delaiAntiRebond) {
    comptage++;
    dernierTemps = maintenant;
  }
}
