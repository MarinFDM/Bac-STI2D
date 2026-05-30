#include <Servo.h>
Servo servo_az; //servo azimut (Est-Ouest : gauche/droite)
Servo servo_el; //servo élévation (haut/bas)
int pos=90;
void setup() {
  servo_az.attach(2); 
  servo_el.attach(3);
  //positionnement du tracker solaire vers l'Est en position basse
  servo_az.write(0);
  servo_el.write(90);
  delay(2000);
  Serial.begin(9600);
}


void loop() {
  
 
  
}
