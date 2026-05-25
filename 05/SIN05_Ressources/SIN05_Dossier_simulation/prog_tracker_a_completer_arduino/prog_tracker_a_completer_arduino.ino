#include <Servo.h> // Inclusion de la bibliothèque permettant de contrôler un servomoteur

 
#define CaptG A1 // Définition des broches analogiques pour les LDR (gauche = A1)
#define CaptD A2 // Définition des broches analogiques pour les LDR (droite = A2)
#define capt_fdc 2 //borne d'entréee du fin de course

Servo horizontal; // Création d’un objet 'horizontal' représentant le servomoteur

int servoh = 0; // Initialisation de la position du servo horizontal à 90°

int val_captD; // Variable pour stocker la lecture du capteur LDR droit
int val_captG; // Variable pour stocker la lecture du capteur LDR gauche

bool img_capteur = 1; // Variable pour l'image de l'état du fin de course

const int calage_traqueur_haute = 270; //valeur maxi (diagramme ressource) pour inclinaison 30° panneau
const int calage_traqueur_basse = 90; //valeur mini (diagramme ressource) pour inclinaison 30° panneau
const int val_plein_sud =90; //valeur angulaire position plein SUD
int servoh_Limit_haute ; // Définition de la limite maxi de rotation du servomoteur
int servoh_Limit_basse ; // Définition de la limite mini de rotation du servomoteur

const int seuil_nuit=100; //seuil de luminosité pour détecter la nuit

void setup() {
  Serial.begin(9600); // Démarrage de la communication série pour le débogage
  horizontal.attach(5); // Connexion du servomoteur à la broche numérique 5
	servoh_Limit_haute = calage_traqueur_haute - val_plein_sud;
	servoh_Limit_basse = calage_traqueur_basse - val_plein_sud;
  horizontal.write(servoh); // Envoi de la position initiale au servomoteur
  delay(3000); // Pause de 3 secondes pour stabiliser le système
}

void loop() {mode_jour_ou_nuit();}

void mode_jour_ou_nuit(){
	img_capteur=digitalRead(capt_fdc);
	// Remplacer les  ......... par les instructions souhaitées
	//...................................................
	//...................................................
	
	if(..........................){
  		Retour_position_EST();
	}
	else {	.................... );}
						}

// fonction de mise en position initiale du tracker
void Retour_position_EST() {
	while(img_capteur == 1){
		servoh -=1;
		horizontal.write(servoh);
		delay(100);
		img_capteur=digitalRead(capt_fdc);
		}
	
    				  }

// fonction de mise en position du tracker
void Automatique(int CaptG, int CaptD) {
  
  int dhoriz = CaptG - CaptD; // Calcul de la différence entre les deux capteurs
  const int Tol = 30; // Tolérance définissant une zone morte pour éviter les micro-ajustements
  if (abs(dhoriz) > Tol) { // Si la différence dépasse la tolérance...
    if (dhoriz < 0) { servoh += 1;} // Si la gauche est plus lumineuse, on tourne vers la droite
     else {servoh -= 1;} // Sinon, on tourne vers la gauche
  
	if (servoh<=servoh_Limit_basse){servoh=servoh_Limit_basse;}
	if (servoh>=servoh_Limit_haute){servoh=servoh_Limit_haute;}
	servoh = constrain(servoh, servoh_Limit_basse, servoh_Limit_haute); // On limite la nouvelle position du servo dans les bornes autorisées
    horizontal.write(servoh); // Mise à jour de la position du servomoteur
    delay(100); // pause pour laisser le servo bouger
	
  }
}
