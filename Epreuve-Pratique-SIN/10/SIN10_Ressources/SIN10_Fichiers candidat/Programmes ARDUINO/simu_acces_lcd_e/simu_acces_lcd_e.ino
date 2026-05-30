/*   Document Elève
Programme de test du module RFID RC522 pour le simulateur TINKERCAD/PROTEUS avec le microcontroleur ARDUINO MEGA
Ce programme teste la validite du code UID du Tag RFID (saisie dans le moniteur série)
ainsi que la température corporelle ( acquisition par un capteur classique DHT22) afin d'activer ou non un servomoteur pour l'accès ou non
Affichage sur l'afficheur LCD " Accès : oui"  ou "Accès: non " 

 
*/
// Bibliothèque utilisees
#include <SPI.h>      // gere la communication SPI
#include <Servo.h>    // gere le servo moteur
#include "DHT.h"
#include <Wire.h>     // gère l'afficheur Lcd
#include "rgb_lcd.h"

rgb_lcd lcd;          // Création d'un objet nommé lcd

// Affectation des numéros de broches des entrées / sorties
const byte LED_ROUGE = 2;         // affectation de la broche 2 de l'ARDUINO a la led rouge
const byte LED_VERTE = 3;         // affectation de la broche 3 de l'ARDUINO a la led verte
const byte SERVO1 = 4;            // affectation de la broche 4 de l'ARDUINO au servo moteur
#define DHTPIN 5                 // Definit la broche de l'Arduino sur laquelle la broche DATA du capteur DHT22 est reliée 
#define DHTTYPE DHT11             //// Definit le type de capteur utilise   ( Ne pas modifier cette ligne)      

// Déclaration des variables globales et constantes utilisées par le programme
DHT dht(DHTPIN, DHTTYPE);         //Declare un objet de type DHT
                                     //Il faut passer en parametre du constructeur 
                                    // de l'objet la broche et le type de capteur
Servo servo_1;                    // objet de commande du servo moteur
String val_uid = "";              // UID du TAG est sauvegardé dans une variable nommée " val_uid"
bool tag_present = false;

// configurations materielles
void setup(){

  
  lcd.begin(16, 2);           // set up the LCD's number of columns and rows:
  pinMode(LED_ROUGE,OUTPUT);    // Configuration des broches 2 et 3 de l'ARDUINO en sortie
  pinMode(LED_VERTE,OUTPUT);
  digitalWrite(LED_ROUGE,LOW);  // Extinction des LEDs au démarrage
  digitalWrite(LED_VERTE,LOW);
  servo_1.attach(SERVO1);       // Connexion du servomoteur a la broche 4
  servo_1.write(0);
  Serial.begin(9600);           // Initialisation de la liaison série entre l'ARDUINO et le MONITEUR Série
  while (!Serial);
  Serial.println("serial OK");
  SPI.begin(); // Initialisation de la communication SPI
  Serial.println("SPI OK");
  // Initialise la capteur DHT22
  dht.begin();
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
  
  //lecture de la température
  float val_temp = dht.readTemperature();
  
  
  
  //lecture de presence d'un tag
  tag_present = Serial.available();
 
   if (tag_present > 0){   // si un tag est present
    val_uid = lecture_tag();
    Serial.println("n° UID = " + val_uid);    // Affichage du n° UID
    traitement(val_uid,val_temp);
    tag_present=false;
  }
  else {
    clignote_led();
  }
}


// déclaration et définition des fonctions
void traitement(String uid,float temp){
  /* traitement du tag RFID */
  if ((uid == "...............") ....... (temp......)){     // A compléter
    
    lcd.print("acces: oui");                          // affichage sur l'afficheur LCD
    digitalWrite(LED_VERTE,HIGH);                    //Allumage de la DEL verte
    servo_1.write(180);                             //Déverrouillage
    delay(3000);                                    //Attendre 3s
    digitalWrite(LED_VERTE,LOW);                    //Extinction de la DEL verte
    lcd.print("acces: non");
    servo_1.write(0);                               //Verrouillage
  }
  else{
    
    lcd.print("acces: non");
    digitalWrite(LED_ROUGE,HIGH);       //Allumage de la DEL rouge
    delay(3000);						//Attendre 3s
    digitalWrite(LED_ROUGE,LOW);        //Extinction de la DEL rouge
  }
}


String lecture_tag(){
  /* lecture du n°UID du tag RFID */
  String uid="";
  // Récupération de toutes les informations du TAG RFID
  while (Serial.available()>0) { // tant qu'un octet en réception
	uid=uid+char(Serial.read()); // Lit le 1er octet reçu et le met dans la variable        
  }
  return uid;
}


void clignote_led(){
  /*  clignote led 1 fois */
  digitalWrite(LED_ROUGE,HIGH);         //Allumage de la DEL rouge
  delay(100);
  digitalWrite(LED_ROUGE,LOW);          //Extinction de la DEL rouge
  delay(100);
}
