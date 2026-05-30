/*  pilotage du projecteur DMX par une manette avec affichage sur afficheur LCD-I2C */

//importation des librairies
#include <DmxSimple.h>


//Definition des constantes
#define BUS_DMX 3         //utilisation de la broche 3 pour la connexion au module grove DMX 512



//declaration des variables globales utilisees par le programme
unsigned int lum = 25;		//variable valeur numerique intensite lumineuse du spot a 10%





//configurations materielles
void setup(){
  DmxSimple.usePin(BUS_DMX);	//broche de connexion au bus DMX
  DmxSimple.maxChannel(15);		//nombre max de canaux utilises
	
}

//boucle du programme principal
void loop(){
	DmxSimple.write(11, 255);       //Lumiere blanche
  DmxSimple.write(6, lum);        //Reglage lumiere du spot à 10%
  
	//Acquisition, adaptation et envoie des valeurs numeriques de positionnement  








	
	//Affichage des valeurs numeriques pour retour technicien







  delay(100);									  	//attendre 100 ms avant de recommencer 
  
}
