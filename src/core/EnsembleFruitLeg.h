#ifndef _ENSEMBLE_FRUIT_LEG
#define _ENSEMBLE_FRUIT_LEG
#include "FruitLegume.h"
#include <vector>
#include <iostream>
#include <stdlib.h>

using namespace std;

class EnsembleFruitLeg {

private:
    /*! @param tabFruitLeg pointeur sur un tableau dynamique de FruitLegume */
    vector<FruitLegume> * tabFruitLeg;
   
public: 
    /*! @brief Constructeur : alloue sur le tas un tableau dynamique de FruitLegume 
    */
    EnsembleFruitLeg();

    /*! @brief Destructeur : supprime le tableau alloué sur le tas 
    */
    ~EnsembleFruitLeg();
    
    /*! @brief Ajout d'un FruitLegume dans le tableau dynamique
        @param fruitLeg nom du FruitLegume à ajouter au tableau 
    */ 
    void addFruitLeg(const FruitLegume & fruitLeg);

    /*! @brief Suppression d'un FruitLegume du tableau dynamique
        @param nomFruitLeg nom du FruitLegume à supprimer du tableau 
    */
    void suppFruitLeg(string nomFruitLeg);

    /*! @brief Donne des informations sur un FruitLegume
        @param nomFruitLeg nom du FruitLegume à rechercher 
    */
    void chercherFruitLeg(string nomFruitLeg);

    /*! @brief Affiche les noms des FruitLegume présents dans le tableau 
    */
    void afficheListeFruitLeg()const;

    /*! @brief Rassemble tous les FruitLegume du jeu disponible au marché 
    */
    void banqueDeFruitLeg(); //utilisé pour le marché

    /*! @brief Test des fonctions du module
    */
    void testRegression()const;


};



#endif //_ENSEMBLE_FRUIT_LEG