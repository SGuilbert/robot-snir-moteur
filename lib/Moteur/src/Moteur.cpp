#include "Moteur.h"
#include "Arduino.h"
Moteur::Moteur(uint8_t pinSens, uint8_t pinPWM, float rapportReduction, bool valSensAvant) : pinSens(pinSens), pinPWM(pinPWM),
                                                                                             rapportReduction(rapportReduction), valSensAvant(valSensAvant)
{
}
/**
 * @brief   parmametrage des moteurs \n 
 *          valeur par défauts: \n   
 *          - sens : avant (0)
 *          - PWM : 0 
 * 
 */
void Moteur::setup()
{
    pinMode(pinSens, OUTPUT);
    pinMode(pinPWM, OUTPUT);
    analogWrite(pinPWM, 0);
    digitalWrite(pinSens, 0);
}
float Moteur::getRapportDeReduction()
{
    return rapportReduction;
}

/**
 * @brief fait tourner le moteur avec les valeurs des attributs de la classe
 * 
 */
void Moteur::run()
{
    analogWrite(pinPWM, pwm);
    digitalWrite(pinSens, sens);
}
/**
 * @brief Arrete le moteur
 * 
 */
void Moteur::stop()
{
    analogWrite(pinPWM, 0);
}
void Moteur::setPWM(int val)
{
    pwm = val;
}
uint8_t Moteur::getPWM()
{
    return pwm;
}
/**
 * @brief pilotage du sens de rotation
 *        évite de devoir échanger les sens de rotation en fonction de la position du moteur
 * 
 * @param val 
 */
void Moteur::setSens(SENS val)
{
    if (val == Avant)
        sens = valSensAvant;
    else
        sens = !valSensAvant;
}
Moteur::SENS Moteur::getSens()
{
    if (valSensAvant == sens)
    return Avant;
    else
    return Arriere;
}
bool Moteur::isRunning()
{
    return pwm > 0; // le moteur est "supposé" tourner si la pwm est suppérieur à un certain seuil
}
Moteur::~Moteur()
{
}