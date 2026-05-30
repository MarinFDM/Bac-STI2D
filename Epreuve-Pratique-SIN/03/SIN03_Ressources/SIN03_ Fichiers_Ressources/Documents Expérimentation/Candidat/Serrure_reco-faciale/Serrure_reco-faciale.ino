/***************************************************
 HUSKYLENS et Serrure solénoïde
  ***************************************************
 Si la reconnaissance faciale est correcte (ID1 ou ID2)
 alors l'ouverture de la serrure est activée pendant 4 secondes

 Une surveillance de l'état de charge de la batterie de secours:
    Batterie chargée: led verte allumée
    Batterie déchargée: led rouge allumée 
 ****************************************************/

#define Batterie A0
#define SERRURE 2
#define LED_verte 3
#define LED_rouge 4
#include <Wire.h>     //librairie pour communiquer en i2C avec l'afficheur
#include <rgb_lcd.h>  //librairie de l'afficheur LCD
rgb_lcd lcd;  //on déclare un LCD
const int colorR = 150;
const int colorG = 150;
const int colorB = 150;
String message;
#include "HUSKYLENS.h"

HUSKYLENS huskylens;
//HUSKYLENS fil vert >> SDA; fil bleu >> SCL
void printResult(HUSKYLENSResult result);

void setup() {
    Serial.begin(115200);
    pinMode(SERRURE, OUTPUT);
    pinMode(LED_verte, OUTPUT);
    pinMode(LED_rouge, OUTPUT); 

  lcd.begin(16, 2); //initialise le LCD avec le nombre de colonnes et de lignes
  lcd.setRGB(colorR, colorG, colorB);
  lcd.clear();      //Efface l'écran
    Wire.begin();
    while (!huskylens.begin(Wire))
    {
        Serial.println(F("Begin failed!"));
        Serial.println(F("1.Please recheck the \"Protocol Type\" in HUSKYLENS (General Settings>>Protocol Type>>I2C)"));
        Serial.println(F("2.Please recheck the connection."));
        delay(130);
    }
}

void loop() {
    Niveau_Batterie();
    
    if (!huskylens.request()) Serial.println(F("Echec de la requete vers la caméra, vérifiez la connexion!"));
    else if(!huskylens.isLearned()) Serial.println(F("Appuyez sur le bouton d'apprentissage de la caméra pour apprendre!"));
    else if(!huskylens.available()){
                digitalWrite(SERRURE, LOW);
                lcd.setCursor(0, 0); 
                lcd.print("Non reconnu...");
                lcd.setCursor(0, 1);      //place le curseur en colonne0, ligne 1
                lcd.print("              "); 
                
                Serial.println("Aucune reconnaissance apparait à l'écran!");}
    else
    {
        while (huskylens.available())
        {
            HUSKYLENSResult result = huskylens.read();
            int ID=result.ID;
            if(ID==1 || ID==2){
              lcd.clear();      //Efface l'écran
              lcd.setCursor(0, 0);      //place le curseur en colonne0, ligne 0
              lcd.print("Bonjour");
              lcd.setCursor(0, 1);      //place le curseur en colonne0, ligne 1

              switch(ID){
                case 1: message="M. MARTIN"; Serial.println("M. MARTIN"); break;
                case 2: message="Mme FAIVRE"; Serial.println("Mme FAIVRE") ;break;
              }
              lcd.print(message); 


            // Partie à compléter


 
            }
           
        }    
    }
}

void Niveau_Batterie() { // détection du niveau de charge de la batterie de secours
    int N = analogRead(Batterie);
    if (N>600){   // Valeur de N à modifier pour répondre à l'exigence souhaitée.
          digitalWrite(LED_verte,HIGH);
          digitalWrite(LED_rouge,LOW);
       }
    else {          
          digitalWrite(LED_verte,LOW);
          digitalWrite(LED_rouge,HIGH);
       }
}
