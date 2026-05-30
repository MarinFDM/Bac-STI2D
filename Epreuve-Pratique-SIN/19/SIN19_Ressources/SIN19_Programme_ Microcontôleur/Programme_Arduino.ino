#define pin_LUM ......
#define pin_MODE ......
#define pin_LAMP ......
#define pin_PIR ......

bool DETECT_PIETON = false;
int LUM = 0;
bool mode_AUTO = false;
bool bdetect = false;


//--------------------------------------------------------------
// -                     INITIALISATION                        - 
//-------------------------------------------------------------- 
void setup()
{
  Serial.begin(9600);
  pinMode(pin_PIR, ......);
  pinMode(pin_MODE, ......);
  pinMode(pin_LAMP, ......);
  
  //Fixe la luminosité à 0%
  digitalWrite(pin_LAMP,0);
  
  Serial.println("-------------DEBUT PROGRAMME---------------");
}

//--------------------------------------------------------------
// -                     PROGRAMME PRINCIPAL                   - 
//-------------------------------------------------------------- 
void loop()
{
  
  //Lecture du mode de fonctionnement
  //--------------------------------------------------
  mode_AUTO = ......;
  
  //Test mode de fonctionnement
  //--------------------------------------------------
  if(mode_AUTO == 1){
    
    .
    .
    .
    <A compléter>
    .
    .
    .
    
    
    
  }else{
    //MODE FORCÉ : Fixe la luminosité à 100%
    digitalWrite(pin_LAMP,255);
  }
}   
   
