#include <Servo.h>

const int S1_PIN = ??;
const int S2_PIN = ??;
const int YELLOW_LED_PIN = ??;
const int RED_LED_PIN = ??;
const int CAM_PIN = ??;
const int GATE_PIN = ??;
Servo gateServo;
boolean gateState; // false si la barrière est baissée, true si la barrière est levée

// Fonction d'initialisation du système
void setup() {
    Serial.begin(9600);
    // Configuration des broches des LED
    pinMode(YELLOW_LED_PIN, ??);
    pinMode(RED_LED_PIN, ??);
    // Configuration de la broche de la barrière
    gateServo.attach(GATE_PIN);
    gateServo.write(0);
    // Configuration de la broche de la caméra
    pinMode(CAM_PIN, ??);
    Serial.println("SYSTÈME INITIALISÉ !\n");
}

// Fonction tournant en boucle indéfiniment
void loop() {
    int s1State = ??(S1_PIN);
    int s2State = ??(S2_PIN);
    if (s1State == false && gateState == false) { // véhicule détecté devant la barrière    
        int camState = ??(CAM_PIN);
        if (camState == true) { // ouverture de la barrière
            ????();
        } else { // plaque d'immatriculation non reconnue
            ????();
        }
    }
    if (s1State == true && s2State == true && gateState == true) { // zone de détection libérée
        ????();
    }
    // Code de test
    // delay(500);
    // printSystemState();
}

// Fonction de test permettant d'afficher l'état du système dans le moniteur-série
void printSystemState() {
    String systemState = "ÉTAT SYSTÈME :\n";
    systemState += "  - Capteur 1 : " + (String)digitalRead(S1_PIN) + "\n";
    systemState += "  - Capteur 2 : " + (String)digitalRead(S2_PIN) + "\n";
    systemState += "  - Caméra : " + (String)digitalRead(CAM_PIN) + "\n";
    systemState += "  - Barrière : " + (String)gateState + "\n";
    Serial.println(systemState);
}

// Fonction réalisant la séquence complète d'ouverture de la barrière
void gateOpening() {
    blink(YELLOW_LED_PIN, 2.5);
    gateUp();
    gateState = true;
}

// Fonction réalisant la séquence complète de fermeture de la barrière
void gateLocking() {
    blink(YELLOW_LED_PIN, 2.5);
    gateDown();
    gateState = false;
}

// Fonction réalisant la séquence de refus d'ouverture de la barrière
void accesDenied() {
    blink(RED_LED_PIN, 3);
}

// Fonction faisant clignoter la LED choisie pendant une durée indiquée en secondes
void blink(int LED_PIN, int duration) {
    for (int i = 0; i <= duration * 5; i++) {
        digitalWrite(LED_PIN, HIGH);
        delay(100);
        digitalWrite(LED_PIN, LOW);
        delay(100);
    }
}

// Fonction faisant se lever la barrière tout en faisant clignoter la LED
void gateUp() {
    for (int i = 0; i <= 90; i++) {
        digitalWrite(YELLOW_LED_PIN, i / 10 % 2 == 0);
        gateServo.write(i);
        delay(11);
    }
    digitalWrite(YELLOW_LED_PIN, LOW);
}

// Fonction faisant se baisser la barrière tout en faisant clignoter la LED
void gateDown() {
    for (int i = 90; i >= 0; i--) {
        digitalWrite(YELLOW_LED_PIN, i / 10 % 2 == 0);
        gateServo.write(i);
        delay(11);
    }
    digitalWrite(YELLOW_LED_PIN, LOW);
}
