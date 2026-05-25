// C++ code

//Définition des constantes
#define pButtonButeeOuverture 7
#define pButtonButeeFermeture 6
// pin de Direction du shield motor
#define directionPin 12 
// pin de PWM 
#define pwmPin 3
#define brakePin 9 
#define pinFeuClignotant 4
// detecteur d'obstacle
/*
 * A compléter
 */

// Vitesse d'ouverture du portail 
#define pVit 2
#define gVit 20

// Pour la simulation, on considère que le portail s'ouvre en dix secondes
#define dureeOuvertureFermeturePortail 10000


// Simulation des boutons de la page Web
int buttonOuvertureWebState = 0;
int buttonFermetureWebState = 0;

// Simulation des butées d'ouverture et de fermeture
int buttonButeeOuvertureState = 0;
int buttonButeeFermetureState = 0;

// Configuration du feu clignotant
unsigned long timerFeuClignotant =0;
int delayFeuClignotant = 500;
// Etat en cours du Feu clignotant
bool etatFeuClignotant = LOW;
bool etatLedFeuClignotant = LOW;


//tempsOuverture portail
unsigned long timerOuvertureFermeturePortail = 0;


bool cycleOuverture = false;
bool cycleFermeture = false;
 

/*
  WiFi Web Server LED Blink

 A simple web server that lets you blink an LED via the web.
 This sketch will print the IP address of your WiFi Shield (once connected)
 to the Serial monitor. From there, you can open that address in a web browser
 to turn on and off the LED on pin 9.

 If the IP address of your shield is yourAddress:
 http://yourAddress/H turns the LED on
 http://yourAddress/L turns it off

 This example is written for a network using WPA encryption. For
 WEP or WPA, change the Wifi.begin() call accordingly.

 Circuit:
 * WiFi shield attached
 * LED attached to pin 9

 created 25 Nov 2012
 by Tom Igoe
 */
#include <SPI.h>
#include <WiFi.h>
// a modifier avec les identifiants du points d'acces du téléphone portable
char ssid[] = "yourNetwork";      //  your network SSID (name)
char pass[] = "secretPassword";   // your network password

int keyIndex = 0;                 // your network key Index number (needed only for WEP)

int status = WL_IDLE_STATUS;
WiFiServer server(80);

void setup() {
  
  // Ajout du code de la simulation
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
  //  fin de l'ajout du code
  Serial.begin(9600);      // initialize serial communication
 

  // check for the presence of the shield:
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present");
    while (true);       // don't continue
  }

  String fv = WiFi.firmwareVersion();
  if (fv != "1.1.0") {
    Serial.println("Please upgrade the firmware");
  }

  // attempt to connect to Wifi network:
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to Network named: ");
    Serial.println(ssid);                   // print the network name (SSID);

    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    status = WiFi.begin(ssid, pass);
    // wait 10 seconds for connection:
    delay(10000);
  }
  server.begin();                           // start the web server on port 80
  printWifiStatus();                        // you're connected now, so print out the status
}


void loop() {
  WiFiClient client = server.available();   // listen for incoming clients

  if (client) {                             // if you get a client,
    Serial.println("new client");           // print a message out the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            // loop while the client's connected
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        if (c == '\n') {                    // if the byte is a newline character

          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();

            // the content of the HTTP response follows the header:
            client.print(" <a href=\"/H\">Ouverture du portail</a> <br>");
            client.print(" <a href=\"/L\">Fermeture du portail</a> <br>");
             /*
              Compléter ici
            */

            // The HTTP response ends with another blank line:
            client.println();
            // break out of the while loop:
            break;
          } else {    // if you got a newline, then clear currentLine:
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }

        // Check to see if the client request was "GET /H" or "GET /L":
        if (currentLine.endsWith("GET /H")) {
          // GET /H Ouverture du Portail
           /*
              Compléter ici
          */
        }
        if (currentLine.endsWith("GET /L")) {
          // GET /L Fermeture du Portail
            /*
             * A compléter
             */
        }
      }
    }
    // close the connection:
    client.stop();
    Serial.println("client disconnected");
  }
}

void printWifiStatus() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
  // print where to go in a browser:
  Serial.print("To see this page in action, open a browser to http://");
  Serial.println(ip);
}



void startCycleOuverture(){
    // Activation du feu clignotant
    gestionFeuClignotant(HIGH);
    feuClignotantCycleInit(); 
    cycleOuverture = true;
    bool obstacle = false;
    /*  Les différentes étapes de l'ouverture/fermeture du portail
        0 ouverture du portail a gVit
        1 passage en pVit
        2 gestion des obstacles
        3 attente de la butée
        4 fin du cycle d'ouverture
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
        Serial.println("Ouverture grande Vitesse");
      }
      else if(etape == 1 && (millis() - timerOuvertureFermeturePortail) > dureeOuvertureFermeturePortail){
        Ouverture(pVit);
        etape = 3;
        Serial.println("Ouverture petite Vitesse");
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
  digitalWrite(brakePin, LOW);
  digitalWrite(directionPin,HIGH);
  analogWrite(pwmPin, vit);  // Application du signal PWM sur e1 
  
}
// Vit doit être egal a PVit ou GVit 
void Fermeture(int vit){
  digitalWrite(brakePin, LOW);
  digitalWrite(directionPin,LOW);
  analogWrite(pwmPin, vit);  // Application du signal PWM sur e1 
}
// Arret du moteur du vantail 
void Arret(){
  digitalWrite(brakePin, HIGH);
  analogWrite(pwmPin, 0);
}
// Simulation de la détection d'un obstacle par detection de présence
bool detectionObstacle(){
    
  bool obstacle= false;
    /*
              Compléter ici
    */
  return obstacle;
}
