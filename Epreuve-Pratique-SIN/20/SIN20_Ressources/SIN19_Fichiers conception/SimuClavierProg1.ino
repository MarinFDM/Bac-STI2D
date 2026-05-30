// Programme 1 Clavier matricé pour la touche 1
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
                                {"C","0","V"}};

// Initialisation                              
void setup() 
{
  //Configuration des broches à compléter
  
  pinMode (...,INPUT);
  pinMode (...,INPUT);
  pinMode (...,INPUT);
  
  pinMode (...,OUTPUT);
  pinMode (...,OUTPUT);
  pinMode (...,OUTPUT);
  pinMode (...,OUTPUT);
  //Initialisation du port Série
  Serial.begin(9600);
  //Mise en route de l'afficheur lcd
  lcd.init();
  lcd.backlight();
  delay(1000);
  
}

//Programme principal
void loop() 
{
  //Affichage du Premier texte
  lcd.setCursor(0,0);
  lcd.print("Identifiez-vous :");
  //Positionnement du curseur pour l'affichage du numéro de touche
  lcd.setCursor(0,1);
  //Variable de détection de la touche appuyée
  toucheAppuyee=0;

  //Mise à 1 de toutes les lignes à compléter
  digitalWrite(..., HIGH);
  digitalWrite(..., HIGH);
  digitalWrite(..., HIGH);
  digitalWrite(..., HIGH);

  //Mise à zero de la ligne 0 à compléter
  digitalWrite(...,LOW);

  //Teste si la première colonne est égale à 0 à compléter
  if(digitalRead(...)==LOW)
  {
    //Si oui on met a 1 la variable de detection de touche appuyee
    //on memorise la touche
    toucheAppuyee=1;
    touche=tabClav[0][...];  // à compléter
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
