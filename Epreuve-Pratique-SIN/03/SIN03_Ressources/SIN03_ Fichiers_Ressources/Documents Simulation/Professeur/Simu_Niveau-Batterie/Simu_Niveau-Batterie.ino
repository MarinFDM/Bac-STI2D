/***************************************************
 HUSKYLENS et Serrure solénoïde
  ***************************************************
 Remarque: "extrait de programme final" 
           Seul la gestion du niveau de charge batterie est traitée ci-dessous

 Une surveillance de l'état de charge de la batterie de secours:
    Batterie chargée: led verte allumée
    Batterie déchargée: led rouge allumée 
 ****************************************************/

#define Batterie A0

#define LED_verte 3
#define LED_rouge 4

void setup() {
    Serial.begin(115200);

    pinMode(LED_verte, OUTPUT);
    pinMode(LED_rouge, OUTPUT); 
}


void loop() {
    Niveau_Batterie();
}

void Niveau_Batterie() { // détection du niveau de charge de la batterie de secours
    int N = analogRead(Batterie);
    if (N>768){
          digitalWrite(LED_verte,HIGH);
          digitalWrite(LED_rouge,LOW);
       }
    else {          
          digitalWrite(LED_verte,LOW);
          digitalWrite(LED_rouge,HIGH);
       }
}
