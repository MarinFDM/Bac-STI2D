// Définition des commandes MIDI
#define NOTE_ON 0x90   // Commande MIDI pour "Note On" (allumer une note sur le canal 1)
#define NOTE_OFF 0x80  // Commande MIDI pour "Note Off" (éteindre une note sur le canal 1)

const int BROCHE_CAPTEUR = A0;    // Broche analogique A0 reliée au capteur ADKEY
const int BROCHE_BUZZER = 3;      // Broche PWM pour le buzzer
int valeurClavier = 0;            // Variable pour stocker la valeur lue du capteur

void setup() {
  Serial.begin(9600);             // Initialisation du port série
  pinMode(BROCHE_BUZZER, OUTPUT); // Initialisation de la broche du buzzer en sortie
}

// Fonction d'envoi de messages MIDI via le port série
void envoyerMessageMIDI(byte commande, byte noteMIDI, byte velocite) {
  Serial.write(commande);    // Envoi de la commande (note on/off + canal)
  Serial.write(noteMIDI);    // Envoi de la hauteur de note (note MIDI)
  if (commande == NOTE_ON || commande == NOTE_OFF) {
    Serial.write(velocite);   // Envoi de la vélocité (intensité de la note)
  }
}

void loop() {
  valeurClavier = analogRead(BROCHE_CAPTEUR);  // Lecture de la valeur transmise par le clavier 10 boutons

  /* Détection de la touche appuyée
     et génération de la note correspondante sur le buzzer
     puis envoi de la note MIDI correspondante via le port série */

  /* Code à compléter : XXXXX et xx sont à remplacer */
     
  if (valeurClavier < 45) {                 // Do4 (C4)
    tone(BROCHE_BUZZER, 261.63);   
    envoyerMessageMIDI(NOTE_ON, 60, 100); 
  }
  else if (valeurClavier < 130) {           // Ré4 (D4)
    tone(BROCHE_BUZZER, XXXXXX);   
    envoyerMessageMIDI(NOTE_ON, xx, 100);  
  }
  else if (valeurClavier < 200) {           // Mi4 (E4)
    tone(BROCHE_BUZZER, XXXXXX);   
    envoyerMessageMIDI(NOTE_ON, xx, 100); 
  }
  else if (valeurClavier < 260) {           // Fa4 (F4)
    tone(BROCHE_BUZZER, XXXXXX);   
    envoyerMessageMIDI(NOTE_ON, xx, 100); 
  }
  else if (valeurClavier < 315) {           // Sol4 (G4)
    tone(BROCHE_BUZZER, XXXXXX);  
    envoyerMessageMIDI(NOTE_ON, xx, 100); 
  }
  else if (valeurClavier < 360) {           // La4 (A4)
    tone(BROCHE_BUZZER, XXXXXX);  
    envoyerMessageMIDI(NOTE_ON, xx, 100);  
  }
  else if (valeurClavier < 400) {           // Si4 (B4)
    tone(BROCHE_BUZZER, XXXXXX);  
    envoyerMessageMIDI(NOTE_ON, xx, 100);  
  }
  else if (valeurClavier < 435) {           // Do5 (C5)
    tone(BROCHE_BUZZER, XXXXXX);   
    envoyerMessageMIDI(NOTE_ON, xx, 100);  
  }
  else if (valeurClavier < 470) {           // Ré5 (D5)
    tone(BROCHE_BUZZER, XXXXXX);   
    envoyerMessageMIDI(NOTE_ON, xx, 100);  
  }
  else if (valeurClavier < 512) {           // Mi5 (E5)
    tone(BROCHE_BUZZER, XXXXXX);
    envoyerMessageMIDI(NOTE_ON, xx, 100); 
  }
  else {
    // Arrêter le buzzer si aucune touche n'est appuyée
    noTone(BROCHE_BUZZER);
    // Éteindre toutes les notes si aucune touche n'est appuyée
    envoyerMessageMIDI(NOTE_OFF, 60, 0);
    envoyerMessageMIDI(NOTE_OFF, 62, 0);
    envoyerMessageMIDI(NOTE_OFF, 64, 0);
    envoyerMessageMIDI(NOTE_OFF, 65, 0);
    envoyerMessageMIDI(NOTE_OFF, 67, 0);
    envoyerMessageMIDI(NOTE_OFF, 69, 0);
    envoyerMessageMIDI(NOTE_OFF, 71, 0);
    envoyerMessageMIDI(NOTE_OFF, 72, 0);
    envoyerMessageMIDI(NOTE_OFF, 74, 0);
    envoyerMessageMIDI(NOTE_OFF, 76, 0);
  }

  delay(100);  // Délai pour éviter les rebonds
}
 
