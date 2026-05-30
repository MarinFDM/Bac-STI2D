#include <Servo.h>
// Informations
//Dans cette conception, les capteurs de lumière ont été remplacés par deux potentiomètres afin de simuler des conditions d'éclairement variées et d'assurer une plus grande stabilité lors des tests.

// Définition des broches
#define PIN_SERVO 5
#define PIN_POT_EST A1   // Potentiomètre simulant le capteur est
#define PIN_POT_OUEST A2 // Potentiomètre simulant le capteur ouest

// Instantiation d'objet
Servo servo1;

// Déclaration des Variables
int valEST, valOUEST; // Valeurs brutes des potentiomètres (simulant les capteurs)
int AngleServo ;// Variable position absolue du servomoteur
int angleDeplacement = 1 ; // Angle de déplacement à chaque étape

void setup() {
  Serial.begin(115200); // Initialisation de la communication série
  servo1.attach(PIN_SERVO);
  AngleServo = 180 ; // Position initiale du servomoteur
  servo1.write(AngleServo); // Envoi de l'angle au servomoteur
  delay(2000);
}

void loop() {
  // 1. Acquérir : Lire les potentiomètres (simulant les capteurs de lumière)
  // Note : Dans l'exercice original, ces broches étaient connectées à des capteurs de lumière (photorésistances).
  // Ici, on utilise des potentiomètres pour plus de stabilité et pour faciliter les tests.
  valEST = analogRead(PIN_POT_EST);
  valOUEST = analogRead(PIN_POT_OUEST);

  // 2. Traiter : à compléter par le candidat
  //------------------------------------------------
  //Lors de votre conception vous serait vigilent à ce que :
  //Etape 1 : le servo moteur s’oriente bien vers le capteur le plus lumineux. Noter que la vitesse et la qualité de suivi ne sera pas évalué ici.
  //Etape 2 : La notion de bande morte soit visible dans la mise en position du servo.

  AngleServo = valEST / 6 ; // ligne pour valider le fonctionnement du code : à modifier








  // ------------------------------------------------
  // Borner l'angle entre 0 et 180 après le calcul
  AngleServo = constrain(AngleServo, 0, 180);

  // 3a. Communiquer vers la machine : Appliquer le nouvel angle
  servo1.write(AngleServo);

  // 3b. Communiquer vers l'humain : Afficher les informations
  Serial.print("valEST (potentiomètre): ");
  Serial.print(valEST);
  Serial.print(" | valOUEST (potentiomètre): ");
  Serial.print(valOUEST);
  Serial.print(" | AngleServo: ");
  Serial.println(AngleServo);

  delay(50); // Délai pour stabiliser le système
}
