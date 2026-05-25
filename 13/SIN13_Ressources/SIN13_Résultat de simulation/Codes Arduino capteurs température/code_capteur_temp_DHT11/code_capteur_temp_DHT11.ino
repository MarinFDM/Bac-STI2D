//Code pour le capteur de température DHT11 sur D2
//Définition des variables 
#include "DHT.h"
#define DHTPIN 2       // Port D2 du Grove Base Shield
#define DHTTYPE DHT11  // Capteur DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("Lecture de la température avec Grove DHT11");
  dht.begin();
}

void loop() {
    //Lecture de la température en °C
  float temperature = dht.readTemperature();

  // Vérifier si la lecture est valide
  if (isnan(temperature)) {
    Serial.println("Erreur de lecture !");
  } else {
    Serial.print("Température : ");
    Serial.print(temperature);
    Serial.println(" °C");
  }

  delay(2000); // Une mesure toutes les 2 secondes
}

