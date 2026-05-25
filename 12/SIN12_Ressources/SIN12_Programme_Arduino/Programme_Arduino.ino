//Définition des constantes
const int pinPIR = 4;            // Capteur de présence
const int pinLED = 3;            // PWM vers la LED
const int seuilAbsence = 5000;   // 5 secondes

//Définition des variables
unsigned long T_dernierMouvement = 0;
bool lumiereAllumee = false;
bool presence = false;

void setup() {
  pinMode(pinPIR, INPUT);
  pinMode(pinLED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  //traitement de la détection de présence
  int presence_detectee = digitalRead(pinPIR);

  if (presence_detectee == HIGH) {
    T_dernierMouvement = millis();
    presence = true;
  } 
  else {
    // traitement de la désactivation quand il n'y a plus de présence
    if (lumiereAllumee && (millis() - T_dernierMouvement > seuilAbsence)) {
      digitalWrite(pinLED, LOW);
      presence = false;
      lumiereAllumee = false;
      
      Serial.println("Pas de presence - LED eteinte");
    }
  }

  // traitement de l'éclairage
  if(presence){
    reguler_luminosite();
  }

  delay(100); // Stabilité du système
}

void reguler_luminosite(){
  // traitement de la régulation d'éclairage
    digitalWrite(pinLED, HIGH);
    lumiereAllumee = true;

    Serial.println("Presence detectee - LED allumee");
}