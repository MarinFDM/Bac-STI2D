/*
Programme de test du module RFID RC522 avec le microcontroleur ARDUINO MEGA
Ce programme teste la validite du code UID du Tag RFID présentée devant le lecteur RFID
et de la temperature corporelle
affichage  " acces : oui" ou "acces : non"
Commande d'une DEL rouge et verte pour vérifier la validation ou non du code
actionne un servomoteur pour le verrouillage/déverrouilage
*/
// Bibliothèque utilisees
#include <SPI.h>      // gere la communication SPI
#include <MFRC522.h>  // gere la communication du module RFID RC522
#include <Servo.h>    // gere le servo moteur
#include <DFRobot_MLX90614.h>
#include "rgb_lcd.h"

// Affectation des numéros de broches des entrées / sorties
const byte LED_ROUGE = 2;         // affectation de la broche 2 de l'ARDUINO a la led rouge
const byte LED_VERTE = 3;         // affectation de la broche 3 de l'ARDUINO a la led verte
const byte SERVO1 = 4;            // affectation de la broche 4 de l'ARDUINO au servo moteur
const byte RST_PIN = 9;           // affectation de la broche 9 de l'ARDUINO a la broche RST du RC522
const byte SS_PIN = 53;           // affectation de la broche 10 de l'ARDUINO a la broche NSS du RC522

// Déclaration des objets
MFRC522 mfrc522(SS_PIN, RST_PIN); // objet de communication RFID broches RST et NSS
Servo servo_1;                    // objet de commande du servo moteur
DFRobot_MLX90614_I2C sensor;      //objet de commande du capteur de température
rgb_lcd lcd;          // Création d'un objet nommé lcd


// Déclaration des variables globales et constantes utilisées par le programme
String val_uid = "";              // UID du TAG est sauvegardé dans une variable nommée " val_uid"
bool tag_present = false;


// configurations materielles
void setup(){
  
  lcd.begin(16, 2); 
  sensor.enterSleepMode();             // configuration du mode Sleep du MLX90614
  delay(50);
  sensor.enterSleepMode(false);
  delay(200);
  
  pinMode(LED_ROUGE,OUTPUT);    // Configuration des broches 2 et 3 de l'ARDUINO en sortie
  pinMode(LED_VERTE,OUTPUT);
  digitalWrite(LED_ROUGE,LOW);  // Extinction des LEDs au démarrage
  digitalWrite(LED_VERTE,LOW);
  servo_1.attach(SERVO1);       // Connexion du servomoteur a la broche 4
  servo_1.write(10);             // servomoteur 0 degre (porte verouillée)
  Serial.begin(115200);           // Initialisation de la liaison série entre l'ARDUINO et le MONITEUR Série
  while (!Serial);
  Serial.println("serial OK");
  SPI.begin(); // Initialisation de la communication SPI
  Serial.println("SPI OK");
  mfrc522.PCD_Init();                // Initialisation de la communication avec le module RFID

}

// Boucle du programme principal
void loop(){
  
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("Presentez ");
  lcd.setCursor(0, 1);
  lcd.print("RFID temperature ");
  delay(1000);
  lcd.clear();
  delay(1000);

      
  //lecture de presence d'un tag
  tag_present = mfrc522.PICC_IsNewCardPresent();

  if (tag_present == true){ // si un tag est present
    val_uid = lecture_tag();
    Serial.println("n° UID = " + val_uid);    // Affichage du n° UID
    traitement(val_uid);
    tag_present=false;
  }
  else {
    clignote_led();
  }
}


// déclaration et définition des fonctions
void traitement(String uid){
  
  float objectTemp=0.0 ;
  objectTemp = sensor.getObjectTempCelsius();         // acquisition température corporelle
  Serial.print(objectTemp);  Serial.println(" °C");
  
  
  /* traitement suivant validité du tag RFID */
  if ((uid == "...................") ....... (objectTemp..............)){   // A compléter
    Serial.println(" acces: oui");   		//
    lcd.print("acces: oui");
    digitalWrite(LED_VERTE,HIGH);       //Allumage de la DEL verte
    servo_1.write(150);					//Déverrouillage
    delay(5000);						//Attendre 5s
    digitalWrite(LED_VERTE,LOW);        //Extinction de la DEL verte
    servo_1.write(10);					//Verrouillage
    delay(1000);            //Attendre 1s
  }
  else{
    Serial.println(" acces: non");     	// 
    lcd.print("acces: non");
    digitalWrite(LED_ROUGE,HIGH);       //Allumage de la DEL rouge
    delay(3000);						//Attendre 3s
    digitalWrite(LED_ROUGE,LOW);        //Extinction de la DEL rouge
  }
}


String lecture_tag(){
  /* lecture du n°UID du tag RFID*/
  String uid="";
  // Récupération de toutes les informations du TAG RFID
  if (!mfrc522.PICC_ReadCardSerial()){
    return;
  }
  // Recuperation du code UID du TAG RFID
  for ( byte i=0; i<mfrc522.uid.size; i++){
    uid.concat(String(mfrc522.uid.uidByte[i] <0x10?" 0" :" "));
    uid.concat(String(mfrc522.uid.uidByte[i], HEX));
  }  
  uid=uid.substring(1);
  return uid;
}


void clignote_led(){
  /*  clignote led 1 fois */
  digitalWrite(LED_ROUGE,HIGH);         //Allumage de la DEL rouge
  delay(100);
  digitalWrite(LED_ROUGE,LOW);          //Extinction de la DEL rouge
  delay(100);
}

