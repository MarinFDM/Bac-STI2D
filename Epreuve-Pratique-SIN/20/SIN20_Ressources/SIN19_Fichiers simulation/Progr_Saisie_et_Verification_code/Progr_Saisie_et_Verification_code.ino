// programme d'acquisition des touches avec fonction keypad et de vérification du code saisie
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>

/*
 * Création de la structure Réservation
 */
struct _Reservation {
  String code;
  int etage;
  int place;
};

typedef struct _Reservation Reservation;

/* 
 * Définition des constantes (Documentation dans le dossier ressource)
 */
#define NUM_ROWS 4
#define NUM_COLS 3
#define RESERVATION_COUNT 10

Reservation RESERVATION_DATA [RESERVATION_COUNT] = {

  // A compléter

};

char keys[NUM_ROWS][NUM_COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'C', '0', 'V'}
};

byte rowPins[] = {4, 5, 6, 7}; 
byte colPins[] = {8, 9, 10}; 

Keypad kp = Keypad(makeKeymap(keys), rowPins, colPins, NUM_ROWS, NUM_COLS);
LiquidCrystal_I2C lcd(0x27,20,4);

/*
 * Fonctions d'affichage
 */
void AfficherPlace(Reservation data)
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Etage : ");
  lcd.print(data.etage);

  lcd.setCursor(0, 1);
  lcd.print("Place : ");
  lcd.print(data.place);
}

void AfficherCodeErrone()
{
  lcd.clear();
  lcd.setCursor(1, 1);
  lcd.print("Code errone");
}

/*
 * Fonction getCode() : Récupère le code saisi par l'utilisateur
 */
String getCode()
{
  String code = String("");
  bool finishedCode = false;
  while (!finishedCode)
  {
    char key = kp.getKey();
    while(key == NO_KEY)
    {
      key = kp.getKey();
    }
    
    if( key == 'V')
    {
      finishedCode = true;
    }
    else if( key == 'C')
    {
      if(code.length() >= 1)
      {
        code.remove(code.length()-1);
      }
    }
    else
    {
      code.concat(key);
    }
  }
  return code;
}

/*
 * Fonction ControlCode() : Vérifie que la réservation existe, et indique à l'utilisateur la place qui lui est réservée.
 */
void ControlCode(String code)
{
  for(int i = 0; i < RESERVATION_COUNT; i++)
  {
    if (code == RESERVATION_DATA[i].code)
    {
      AfficherPlace(RESERVATION_DATA[i]);
      return;
    }
  }
  AfficherCodeErrone();
}


void setup()
{
  lcd.init();       // Initialisation de l'écran
  lcd.backlight();  // Activation de l'éclairage de l'écran
}

void loop() 
{
  // Demande du code à l'utilisateur
  lcd.clear();
  lcd.print("Entrez votre code");
  
  //Récupération du code
  String code = getCode();

  //Vérification du code
  ControlCode(code);
  
  //Attente avant un nouveau cycle.
  delay(2000);
}
