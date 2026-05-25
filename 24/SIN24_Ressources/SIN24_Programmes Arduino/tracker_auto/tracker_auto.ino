#include <Servo.h>
Servo servo_az; //servo azimut (Est-Ouest : gauche/droite)
Servo servo_el; //servo élévation (Nord/Sud : haut/bas)
int angle_az;   //variable contenant la valeur de l'angle du servomoteur d'azimut
int angle_el; //variable contenant la valeur de l'angle du servomoteur d'élévation
void setup() {
  servo_az.attach(2); 
  servo_el.attach(3);
  Serial.begin(9600);
  
}


void loop() {
  for (angle_az=180;angle_az>=0;angle_az--){   //balayage en azimut du tracker d'Est en Ouest (180° à 0°)
    servo_az.write(angle_az);

    if (angle_az>90){   //si le tracker est orienté entre l'Est et le Sud
      angle_el=(angle_az*120)/90-60;  //calcul de l'angle d'élévation en fonction de l'angle d'azimut
      
    }
    else{               //si le tracker est orienté entre le Sud et l'Ouest
      angle_el=180-(120*angle_az)/90;  //calcul de l'angle d'élévation en fonction de l'angle d'azimut
      
    }
  servo_el.write(angle_el);
  
  delay(100);
  Serial.print(angle_az);
  Serial.print("   ");
  Serial.println(angle_el);
  }
  for (angle_az=0;angle_az<180;pos++){   //retour du tracker en position initiale vers l'Est
    servo_az.write(angle_az);
    delay(15);
  }
  
  

 
  
}
