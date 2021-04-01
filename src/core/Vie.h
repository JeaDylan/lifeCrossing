/**
    @brief Module gérant la Vie du personnage
    @file Vie.h
*/

#ifndef _VIE
#define _VIE
#include "Jauge.h"

#include <iostream>
#include <strings.h>

using namespace std; 

/*!
* \brief Vie est une classe qui réunit les différents niveaux~(Jauge) de santé du Personnage (santé, faim,soif...) 
*/

class Vie{
private:
    Jauge ptsDeVie;
    Jauge faim;
    Jauge soif;
    Jauge fatigue;

public:
    /*! @brief Accesseur : renvoit les points de vie du Personnage
    */
    int getPtsDeVie()const;

    /*! @brief Accesseur : renvoit les points de faim du Personnage
    */
    int getFaim()const;

    /*! @brief Accesseur : renvoit les points de soif du Personnage
    */
    int getSoif()const;

    /*! @brief Accesseur : renvoit les points de fatigue du Personnage
    */
    int getFatigue()const;

    /*! @brief Mutateur : modifie les points de vie du Personnage
    */
    void setPtsDeVie(int vie);

    /*! @brief Mutateur : modifie les points de faim du Personnage
    */
    void setFaim(int faim);

    /*! @brief Mutateur : modifie les points de soif du Personnage
    */
    void setSoif(int soif);

    /*! @brief Mutateur : modifie les points de fatigue du Personnage
    */
    void setFatigue(int fatigue);

    /*! @brief Teste toutes les fonctions du module
    */
    void testRegression();


};



#endif //_VIE