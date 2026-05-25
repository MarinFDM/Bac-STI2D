//Définition des constantes
#define HUMIDITE A0
#define TEMP_AIR A1
#define POMPE 2
#define CAPT_TRAPPE_HAUT 4
#define CAPT_TRAPPE_BAS 5
#define TRAPPE1 6
#define TRAPPE2 7

//Définition des variables
unsigned int tempCan = 0;
unsigned int temperature = 0;
unsigned int seuilTemperatureHaut = 30;
unsigned int seuilTemperatureBas = 20;
unsigned int humiditeCan = 0;
unsigned int seuilHumidite = 512;


void setup() {
  Serial.begin(9600);
  pinMode(POMPE, OUTPUT);
  pinMode(CAPT_TRAPPE_HAUT, INPUT_PULLUP);
  pinMode(CAPT_TRAPPE_BAS, INPUT_PULLUP);
  pinMode(TRAPPE1, OUTPUT);
  pinMode(TRAPPE2, OUTPUT);

  digitalWrite(POMPE, HIGH);
  digitalWrite(TRAPPE1, LOW);
  digitalWrite(TRAPPE2, LOW);
}

void loop() {
  //traitement température de l'air
  tempCan = analogRead (TEMP_AIR); //lecture dans le vide préconisée
  delay(100);
  tempCan = analogRead (TEMP_AIR); //lecture LM35
  temperature = 500*tempCan/1023; //convertion en degrés
  Serial.print("temp : ");
  Serial.println(temperature);
  if (temperature > seuilTemperatureHaut) ouvrirTrappe(); //on aère si la température devient trop forte
  else if (temperature < seuilTemperatureBas)fermerTrappe(); //on garde la chaleur

  //traiment humidité sol
  humiditeCan = analogRead(HUMIDITE);
  delay(100);
  humiditeCan = analogRead(HUMIDITE);
  Serial.print("humidite : ");
  Serial.println(humiditeCan);
  if (humiditeCan < seuilHumidite) alimenterPompe(); //on arrose si l'humidité du sol est inférieur au seuil
  else arreterPompe(); //on arrête d'arroser

  delay(1000);
}

void ouvrirTrappe() {
  while (digitalRead(CAPT_TRAPPE_HAUT) == 1) digitalWrite(TRAPPE1, HIGH);
  digitalWrite(TRAPPE1, LOW);
}
void fermerTrappe() {
  while (digitalRead(CAPT_TRAPPE_BAS) == 1) digitalWrite(TRAPPE2, HIGH);
  digitalWrite(TRAPPE2, LOW);
}
void alimenterPompe() {
  Serial.println("On arrose");
  digitalWrite(POMPE, HIGH);
}
void arreterPompe() {
  Serial.println("On n'arrose pas");
  digitalWrite(POMPE, LOW);
}
