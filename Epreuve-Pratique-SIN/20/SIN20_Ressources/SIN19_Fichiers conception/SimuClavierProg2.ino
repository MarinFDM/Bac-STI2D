// Programme 2 : Clavier matricé pour détecter une ligne de touches (la touche « 1 », « 2 » et « 3 »).
//#include "rgb_lcd.h"
#include <LiquidCrystal_I2C.h>

//Initialisation des variables touche et toucheAppuyee
String touche="";
int toucheAppuyee=0;

//Instanciation de l'objet lcd
LiquidCrystal_I2C lcd(0x27,16,2);

//Tableau des valeurs des touches du clavier
const String tabClav[4][3] = {  {"1","2","3"},
                                {"4","5","6"},
                                {"7","8","9"},
                                {"*","0","#"}};

// Initialisation
void setup() 
{
  //Configuration broches à compléter
  pinMode (...,INPUT);
  pinMode (...,INPUT);
  pinMode (...,INPUT);
  
  pinMode (...,OUTPUT);
  pinMode (...,OUTPUT);
  pinMode (...,OUTPUT);
  pinMode (...,OUTPUT);

  //Initialisation du port Serie
  Serial.begin(9600);
  //Mise en route de l'afficheur lcd
  lcd.init();
  lcd.backlight();
  delay(1000);
  
}

// programme Principal
void loop() 
{
  //Affichage du Premier texte
  lcd.setCursor(0,0);
  lcd.print("Identifiez-vous :");
  //Positionnement du curseur pour l'affichage du numero de touche
  lcd.setCursor(0,1);
  //Variable de detection de touche appuyee
  toucheAppuyee=0;

  //Mise à 1 de toutes les lignes
  digitalWrite(..., HIGH);
  digitalWrite(..., HIGH);
  digitalWrite(..., HIGH);
  digitalWrite(..., HIGH);
  //Mise à zero d une ligne
  digitalWrite(..., LOW);
 
  //Test des 3 colonnes
  for (int col=0; ... ; ...)
  {
    //Test si la colonne (de 3 à 5) est egale à 0
    if(digitalRead(...)==0)
    {
      //Si oui on met à 1 la variable de detection de touche appuyee
      //on memorise la touche
      toucheAppuyee=1;
      touche=tabClav[...][...];
    }
  }
  //Affichage de la touche
  if(toucheAppuyee==1)
  {
    lcd.print("Touche "+touche+" appuyee");
  }
  else
  {
    lcd.println("Touche relachee ");
  }
}
