
#include <rgb_lcd.h>            // Écran LCD RGB
#include <Adafruit_RGBLCDShield.h>

#include <Wire.h>             // Communication I2C

// Définir l'entrée Analogique utilisée
const int Signal_GBF = _ _ _ _ ;  // à compléter

unsigned long etat_haut ;
unsigned long etat_bas ;
long periode ;
long frequence ; 

rgb_lcd ecran; // Déclaration de l'objet ecran de type rgb_lcd

// Couleur de fond de l'écran (RVB)
byte colorR = 10;
byte colorG = 255;
byte colorB = 10;

void setup() {
  ecran.begin(16, 2);                    // Écran LCD 16 colonnes x 2 lignes
  ecran.setRGB(colorR, colorG, colorB);  // Couleur d'affichage

// Configure le port série pour l'exemple
  Serial.begin(9600);


// Configure la broche de signal venant du GBF en entrée
  pinMode(Signal_GBF, INPUT);
}

void loop() {
  
// Mesure la durée de l'impulsion haute
 etat_haut = pulseIn(Signal_GBF, HIGH);

  
// Mesure la durée de l'impulsion basse
 etat_bas = pulseIn(Signal_GBF, LOW);

  
// Calcul de la periode = 
  _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _// à compléter

  
// Calcul de la frequence 
_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ // à compléter
  


 // Afffichage de la fréquence sur l'écran LCD :

    ecran.clear();
    ecran.setCursor(0, 0);
    ecran.print("Frequence = ");
    ecran.setCursor(0, 1);
    //  affichage de la fréquence
    ecran.print(_ _ _ _ _ _ _ _ _ ); // à compléter
    delay(50);
  }
