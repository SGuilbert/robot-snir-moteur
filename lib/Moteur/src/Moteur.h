#ifndef MOTEUR_H
#define MOTEUR_H
#include <stdint.h>
/**
 * @brief permet de piloter un moteur
 * gestion de la pwm et du sens
 * 
 */
class Moteur
{
private:
    uint8_t pinSens;
    uint8_t pinPWM;
    uint8_t pwm;
    const float rapportReduction;
    bool sens; //valeur pin de sens
    
    bool valSensAvant;

public:

    /**
     * @brief permet de donner uniquement le sens avant ou arriere cf: setSens()
     * Avant: le robot avance Arriere : le robot recul
     * 
     */
    typedef enum {
        Avant,Arriere
    } SENS;
    /**
     * @brief Construit/instancie un nouvel objet moteur
     * 
     * @param pinSens pin de gestion du sens de rotation
     * @param pinPWM  pin de gestion de la pwm (0-255)
     * @param rapportReduction le rapport de réduction
     * @param valSensAvant valeur que le pin sens doit prendre pour que le robot avance
     */
    Moteur(uint8_t pinSens, uint8_t pinPWM, float rapportReduction,bool valSensAvant);
    /**
     * @brief configuration des pin en sortie (actionneur)
     * 
     */
    void setup();
    /**
     * @brief fait tourner le moteur en fonction des valeurs des attributs sens et pwm
     * Doit être appelé pour que les changement de valeurs de pwm et sens soient prises en compte
     * 
     */
    void run();
    /**
     * @brief Arrête le moteur : pwm = 0;
     * 
     */
    void stop();
    /**
     * @brief permet de savoir si le moteur tourne (pwm > 0)
     * 
     * @return true pwm > 0
     * @return false pwm == 0
     */
    bool isRunning();

    /**
     * @brief retourne la valeur de l'attribut privé pwm (getter/accesseur)
     * 
     * @return uint8_t 
     */
    uint8_t getPWM();
    /**
     * @brief change la valeur du pwm (setter/mutateur)
     * 
     * @param val la nouvelle valeur
     */
    void setPWM(int val);
    /**
     * @brief retourne la valeur de l'attribut privé sens (getter/accesseur)
     * 
     * @return SENS Moteur::Avant ou Moteur::Arriere
     */
    
    SENS getSens();
    /**
     * @brief change la valeur de l'attribut privé sens (getter/accesseur)
     * 
     * @param sens SENS (Moteur::Avant ou Moteur::Arriere)
     */
    void setSens(SENS sens);

    /**
     * @brief retourne la valeur de l'attribut privé rapportDeReduction (getter/accesseur)
     * 
     * @return SENS Moteur::Avant ou Moteur::Arriere
     */
    float getRapportDeReduction();
    /**
     * @brief Destroy the Moteur object (unused)
     * 
     */
    ~Moteur();
};
#endif
