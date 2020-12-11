/*
 * Programme : Deux boutons avec 6 fonctions
 * 
 * 1) Pression courte du Bouton 1. (Led Bleu BP1)
 * 2) Pression courte du Bouton 2. (Led Rouge BP2)
 * 3) Pression courte des Boutons 1 et 2. (Led Bleue)
 * 4) Pression longue du Bouton 1. (Led Verte)
 * 5) Pression longue du Bouton 2. (Led Blanche) 
 * 6) Pression longue des Boutons 1 et 2.  (Led Jaune)
 * 
 * Ici j'utilise un Arduino Nano.
 */

/* VARIABLES */
/* --------- */

// Les LEDS :
int LED2 = 3;           // Led BP1 (Bleu).  DRV-3
int LED3 = 5;           // Led Verte.       DRV-5
int LED4 = 6;           // Led BP2 (Rouge). DRV-6
int LED1 = 7;           // Led Bleu.        DRV-7
int LED5 = 8;           // Led Jaune.       DRV-8
int LED6 = 9;           // Led Blanche.     DRV-9

// Les Boutons :
int button1 = 2;        // Bouton Poussoir #1 (Led Bleu).  RCV-2
int button2 = 4;        // Bouton Poussoir #2 (Led Rouge). RCV-4

// Les Timers :
long buttonTimer = 0;   // Pour la mémorisation du Temps écoulé.
long buttonTime = 250;  // Délai pour definir la pression Courte ou Longue.

// Les Booléens :
boolean Action = false;             // Action sur un BP = Faux.
boolean longPressActive = false;    // Préssion Longue = Faux.

boolean BP1Actif = false;           // Bouton #1 Actif = Faux.
boolean BP2Actif = false;           // Bouton #2 Actif = Faux.

boolean LED1Active = false;         // LED #1 Active = Faux.
boolean LED2Active = false;         // LED #2 Active = Faux.
boolean LED3Active = false;         // LED #3 Active = Faux.
boolean LED4Active = false;         // LED #4 Active = Faux.
boolean LED5Active = false;         // LED #5 Active = Faux.
boolean LED6Active = false;         // LED #6 Active = Faux.

// The SETUP :
void setup() 
  {
    // Les Sorties :
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    pinMode(LED3, OUTPUT);
    pinMode(LED4, OUTPUT);
    pinMode(LED5, OUTPUT);
    pinMode(LED6, OUTPUT);
    // Les Entrées :
    pinMode(button1, INPUT);
    pinMode(button2, INPUT);
  }
  
// The LOOP :
void loop()
  {                                       // Début de Loop()

    // Si action sur BP #1 :
    if (digitalRead(button1) == HIGH)     // Si BP #1 = 1.
      {
        if (Action == false)              // Le BP est Inactif ?
          {
            Action = true;                // On passe le BP actif.
            buttonTimer = millis();       // Memorisation du Timer.
          }
        BP1Actif = true;                  // On passe BP #1 actif.
      }                                   // Fin Bouton 1.

    // Si action sur BP #2 :
    if (digitalRead(button2) == HIGH)     // Si BP #2 = 1. 
      {
        if (Action == false)              // Le BP est Inactif ? 
          {
            Action = true;                // On passe le BP actif.
            buttonTimer = millis();       // Memorisation du Timer.
          }

        BP2Actif = true;                  // On passe BP #2 actif.
      }                                   // Fin Bouton 2.

    // Il y a une préssion Longue ?
    if ((Action == true) && (millis() - buttonTimer > buttonTime) && (longPressActive == false)) 
      {
        longPressActive = true;                             // Oui, on la passe Actif.
        if ((BP1Actif == true) && (BP2Actif == true))       // Les 2 BP Actifs ?
          {
            LED4Active = !LED4Active;                       // Oui, on bascule LED 4.
            digitalWrite(LED4, LED4Active);                 // LED 4 Active.
          }                                                 // Fin 2 BP Actifs.
          else if((BP1Actif == true) && (BP2Actif == false))// Si non BP1 Actif et BP2 Passif ?
          {
            LED5Active = !LED5Active;                       // On bascule LED 5.
            digitalWrite(LED5, LED5Active);                 // LED 5 Active.
          } 
        else                                                // Si Non, préssion Courte :
          {
            LED6Active = !LED6Active;                       // On bascule LED 6.
            digitalWrite(LED6, LED6Active);                 // LED 6 Active.
          }
      }                                                     // Fin préssion Longue ?

    // Action sur un BP avec BP #1 = 0 ET BP #2 = 0 ?
    if ((Action == true) && (digitalRead(button1) == LOW) && (digitalRead(button2) == LOW)) 
      {
        if (longPressActive == true)                        // Longue préssion ? 
          {
            longPressActive = false;                        // Longue  préssion inactive.
          } 
        else                                                // Si non courte :
          {
            if ((BP1Actif == true) && (BP2Actif == true))   // Les 2 BP Actifs ?
              {
                LED1Active = !LED1Active;                   // On bascule LED 1.
                digitalWrite(LED1, LED1Active);             // LED 1 Active.
              }  // Si non BP1 Actif et BP2 Passif ?
            else if ((BP1Actif == true) && (BP2Actif == false))
              {
                LED2Active = !LED2Active;                   // On bascule LED 2.
                digitalWrite(LED2, LED2Active);             // LED 2 Active.
              }
            else                                            // Si non BP1 OFF ET BP2 ON :
              {
                LED3Active = !LED3Active;                   // On bascule LED 3.
                digitalWrite(LED3, LED3Active);             // LED 3 Active.
              }
          }                                                 // Fin préssion courte.
        // Remise par defaut :
        Action = false;
        BP1Actif = false;
        BP2Actif = false;
      }
  }                                                         // Fin de Loop()
  
