//--Déclaration des variables utilisées pour les broches des composants
int buzzer = 3;
int trig = 7;
int echo = 6;




//déclaration des variables
long duree_impulsion;
long distanceincm;

void setup()
{
//--Déclaration en entrées/sorties des broches utilisées
  pinMode(trig,OUTPUT);  //broches SRF04
  pinMode(echo,INPUT);
  pinMode(buzzer,OUTPUT);  //broche buzzer

 
  

  
}

void loop(){
//-----mesure de la distance--------      
  
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  duree_impulsion = pulseIn(echo,HIGH); //mesure de la durée de l'impulsion recue en µs
  distanceincm = (duree_impulsion * 0.034)/2; //calcul de la distance en cm

  
//----allumage des LEDs et génération du son suivant la distance
  
  
  if (distanceincm<100){
    generation_du_son();  // appel de la fonction generation_du_son()
  }
    //---------ALLUMAGE DES LEDS A COMPLETER ICI ------------------------------------
 
  
  

}  //--------- Fin du LOOP----  
    
void  generation_du_son()    //fonction qui génére un son en fonction de la distance
{
      tone(buzzer,500,(5000/distanceincm));
      delay(10*(distanceincm));
  	  noTone(buzzer);
  }

  
