#include <Arduino.h>
//inclusion de notre classe
#include "Moteur.h"


//Affectation des sorties de la carte pour les moteurs d'avance
#define PIN_SENS_MOTEUR_GAUCHE 10
#define PIN_PWM_MOTEUR_GAUCHE 5

#define PIN_SENS_MOTEUR_DROITE 11
#define PIN_PWM_MOTEUR_DROITE 6

// construction des 2 moteur (droit et gauche), la réduction est considérée comme faisant partie du moteur
Moteur moteurD(PIN_SENS_MOTEUR_DROITE, PIN_PWM_MOTEUR_DROITE, (1.0 / 120.0), 0);
Moteur moteurG(PIN_SENS_MOTEUR_GAUCHE, PIN_PWM_MOTEUR_GAUCHE, (1.0 / 120.0), 1);
/**
 * @brief fonction lancée une seule fois, permet la configuration des capteurs et actionneurs
 * 
 */
void setup()
{
  Serial.begin(115200); // Démarre la communication série pour le débugage sur le moniteur série
  moteurD.setup();
  moteurG.setup();
  delay(500);
}
bool first = true;
void loop()
{
if(first)
{
  Serial.println("demarage du moteur (la pwm est à 0 par défaut, cf. constructeur)");
  // demarage du moteur (la pwm est à 0 par défaut, cf. constructeur)
  moteurD.run();
  moteurG.run();
  delay(2000);

  Serial.println("Test sens Avant pdt 2s");
  //Test sens Avant pdt 2s
  moteurD.setSens(Moteur::Avant);
  moteurD.setPWM(50);
  moteurG.setSens(Moteur::Avant);
  moteurG.setPWM(50);
  moteurD.run();
  moteurG.run();
  delay(2000);

  Serial.println("Test sens Arriere pdt 2s");
  //Test sens Arriere pdt 2s
  moteurD.setSens(Moteur::Arriere);
  moteurD.setPWM(100);
  moteurG.setSens(Moteur::Arriere);
  moteurG.setPWM(100);
  moteurD.run();
  moteurG.run();
  delay(2000);

  Serial.println("Test stop pdt 2s");
  //Test stop pdt 2s
  moteurD.setPWM(0);
  moteurG.setPWM(0);
  moteurD.run();
  moteurG.run();
  delay(2000);
  first = false; // termine le test
}

}

