// C++ code

//Définition des constantes
#define pButtonOuvertureWeb 7
#define pButtonFermetureWeb 2
#define pButtonButeeOuverture 9
#define pButtonButeeFermeture 10
// e1 du L293 correspond à la broche 5 arduino
#define e1 5
// e2 du L293 correspond à la broche 6 arduino
#define e2 6
#define pinFeuClignotant 4
// detecteur d'obstacle
/*
 * A compléter
 */
// vitesse d'ouverture du portail 
#define pVit 2
#define gVit 20

// pour la simulation on considère que le portail s'ouvre en dix secondes
#define dureeOuvertureFermeturePortail 10000


// Simulations des boutons de la page Web
int buttonOuvertureWebState = 0;
int buttonFermetureWebState = 0;

//Simulation des butées d'ouverture et de fermeture
int buttonButeeOuvertureState = 0;
int buttonButeeFermetureState = 0;

// configuration du feu clignotant
unsigned long timerFeuClignotant =0;
int delayFeuClignotant = 500;
// Etat en cours du Feu clignotant
bool etatFeuClignotant = LOW;
bool etatLedFeuClignotant = LOW;


//tempsOuverture portail
unsigned long timerOuvertureFermeturePortail = 0;


bool cycleOuverture = false;
bool cycleFermeture = false;
 


void setup()
{
  pinMode(pButtonOuvertureWeb, INPUT_PULLUP);
  pinMode(pButtonFermetureWeb, INPUT_PULLUP);
  pinMode(pButtonButeeOuverture, INPUT_PULLUP);
  pinMode(pButtonButeeFermeture, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);

    /*
   * A compléter
   */
  
  pinMode(e1, OUTPUT);  
  pinMode(e2, OUTPUT);
  pinMode(pinFeuClignotant, OUTPUT);
  
  timerFeuClignotant= millis();
  Serial.begin(9600);
}

void loop()
{
  
  buttonOuvertureWebState = !digitalRead(pButtonOuvertureWeb);
  buttonFermetureWebState = !digitalRead(pButtonFermetureWeb);
  
  buttonButeeOuvertureState = !digitalRead(pButtonButeeOuverture);
  buttonButeeFermetureState = !digitalRead(pButtonButeeFermeture);
  
  // Si l'un des boutons de l'interface web est appuyé on lance le cycle correspondant.
  if (buttonOuvertureWebState == HIGH) {
    startCycleOuverture();    
  }
  if (buttonFermetureWebState == HIGH){
    startCycleFermeture();
  }
}
void startCycleOuverture(){
    // Activation du feu clignotant
    gestionFeuClignotant(HIGH);
    feuClignotantCycleInit(); 
    cycleOuverture = true;
    bool obstacle = false;
    /*  Les differentes étapes de l'ouverture/fermeture du portail
      0 ouverture du portail a gVit
        1 passage en pVit
        2 gestion des obstacles
      3 attente de la butée
        4 fin du ccyle d'ouverture
    */
    int etape = 0;
    while(cycleOuverture){
      buttonButeeOuvertureState = !digitalRead(pButtonButeeOuverture);
      feuClignotant();
      if (detectionObstacle()&& etape!=2 && etape !=4){
        etape = 2;
        Serial.println("Obstacle detecte");
      }
      // fonctionnement normal
      else if (etape==0){
        //Ouverture du portail a GVIT et passage a l'étape 1
        Ouverture(gVit);
        timerOuvertureFermeturePortail=millis();
        etape =1;
        Serial.println("ouverture grande Vitesse");
      }
      else if(etape == 1 && (millis() - timerOuvertureFermeturePortail) > dureeOuvertureFermeturePortail){
      Ouverture(pVit);
        etape = 3;
        Serial.println("ouverture petite Vitesse");
      }
      else if (etape==3 && buttonButeeOuvertureState){
        // Arret fin ouverture
        Arret();
        Fermeture(pVit);
        delay(500);
        Arret();
        etape=4;
        Serial.println("Detection de la butee");

      }
      else if (etape ==4){
        feuClignotantCycleInit();
        gestionFeuClignotant(LOW);
        cycleOuverture=false;
        Serial.println("Fin de cycle d'ouverture");
      }
      // gestion des obstacles - degagement de l'obstacle
      else if (etape ==2){
        Arret();
        Fermeture(pVit);
        delay(1000);
        Arret();
        etape = 4;
        Serial.println("Degagement de l'obstacle");

      }
    }
    
}

void startCycleFermeture(){
   // Activation du feu clignotant
    gestionFeuClignotant(HIGH);
    feuClignotantCycleInit(); 
    cycleFermeture = true;
    bool obstacle = false;
    /*  Les differentes étapes de l'ouverture/fermeture du portail
      0 Fermeture du portail a gVit
        1 passage en pVit
        2 gestion des obstacles
        3 attente de la butée
        4 fin du cycle de fermeture
    */
    int etape = 0;
    while(cycleFermeture){
      buttonButeeFermetureState = !digitalRead(pButtonButeeFermeture);
      feuClignotant();
      if (detectionObstacle()&& etape!=2 && etape !=4){
        etape = 2;
        Serial.println("Obstacle detecte");
      }
      // fonctionnement normal
      else if (etape==0){
        //Fermeture du portail a GVIT et passage a l'étape 1
        Fermeture(gVit);
        timerOuvertureFermeturePortail=millis();
        etape =1;
        Serial.println("Fermeture grande Vitesse");
      }
      else if(etape == 1 && (millis() - timerOuvertureFermeturePortail) > dureeOuvertureFermeturePortail){
        Fermeture(pVit);
        etape = 3;
        Serial.println("Fermeture petite Vitesse");

      }
      else if (etape==3 && buttonButeeFermetureState){
        // Arret fin ouverture
        Arret();
        Ouverture(pVit);
        delay(500);
        Arret();
        etape=4;
        Serial.println("Detection de la butee");

      }
      else if (etape ==4){
        feuClignotantCycleInit();
        gestionFeuClignotant(LOW);
        cycleFermeture=false;
        Serial.println("Fin de cycle de fermeture");

      }
      // gestion des obstacles - degagement de l'obstacle
      else if (etape ==2){
        Arret();
        Ouverture(pVit);
        delay(1000);
        Arret();
        etape = 4;
        Serial.println("Degagement de l'obstacle");
      }   
    }
}


// Activation du feu clignotant pendant 3secondes
void feuClignotantCycleInit(){
  unsigned long timer3Secondes = millis();
    while (millis() - timer3Secondes < 3000){
      feuClignotant();
    }
    digitalWrite(pinFeuClignotant,0);
    Serial.println(timer3Secondes);
}
// Activation du feu clignotant lorsque etat == HIGH
void gestionFeuClignotant(bool etat){
  etatFeuClignotant = etat;
}
// Gestion du clignotement
void feuClignotant(){
  if(etatFeuClignotant==HIGH){
    if ((millis() - timerFeuClignotant) > delayFeuClignotant){
      etatLedFeuClignotant = !etatLedFeuClignotant;
      digitalWrite(pinFeuClignotant,etatLedFeuClignotant);
      timerFeuClignotant = millis(); 
    }
  }
}

// Vit doit être egal a PVit ou GVit 
void Ouverture(int vit){
	analogWrite(e1, vit);  // Application du signal PWM sur e1 
    digitalWrite(e2, LOW); // Etat bas sur e2
}
// Vit doit être egal a PVit ou GVit 
void Fermeture(int vit){
	digitalWrite(e1, LOW);  // Application du signal PWM sur e1 
    analogWrite(e2, vit); // Etat bas sur e2
}
// Arret du moteur du vantail 
void Arret(){
  digitalWrite(e1, LOW);
  digitalWrite(e2, LOW);
}
// Simulation de la détection d'un obstacle 
bool detectionObstacle(){
  bool obstacle= false;
  /*
   * A compléter
   */
  
  return obstacle;
}
