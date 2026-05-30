#include <Servo.h>
Servo servo_az; //servo azimut (Est-Ouest : gauche/droite)
Servo servo_el; //servo élévation (haut/bas)
int pos;
void setup() {
  servo_az.attach(2); 
  servo_el.attach(3);
  //positionnement du tracker solaire vers l'Est en position basse
  servo_az.write(....); //à compléter
  servo_el.write(....); //à compléter
  delay(2000);
  Serial.begin(9600);
}


void loop() {
  
  int ldr1 = .......... ;   // à compléter
  int ldr2 = ...........;   // à compléter
  int lum = ............;   // à compléter
  if (.........){           // à compléter
    angle=angle+1;
  }
  else if (..........){     // à compléter
    angle=angle-1;
  }
  ...................;      // à compléter
  delay(15);
 
//dernière partie à écrire  : retour vers l'Est après le coucher du soleil




}
