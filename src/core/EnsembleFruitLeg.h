/*!
* @brief Module gérant un ensemble de FruitLegume
* @file EnsembleFruitLeg.h
*/

#ifndef _ENSEMBLE_FRUIT_LEG
#define _ENSEMBLE_FRUIT_LEG
#include "FruitLegume.h"
#include <vector>
#include <iostream>
#include <stdlib.h>

using namespace std;

/*! @brief EnsembleFruitLeg : un tableau dynamique de FruitLegume
*/
class EnsembleFruitLeg {

public: 
  
    vector<FruitLegume> * tabFruitLeg;
   

    /*! @brief Constructeur par défaut : alloue sur le tas un tableau dynamique de FruitLegume 
    */
    EnsembleFruitLeg();

    /*! @brief Destructeur : supprime le tableau alloué sur le tas 
    */
    ~EnsembleFruitLeg();
    
    /*! @brief Ajout d'un FruitLegume dans le tableau dynamique
        @param fruitLeg nom du FruitLegume à ajouter au tableau 
    */ 
    void ajouterFruitLeg(const FruitLegume & fruitLeg);

    /*! @brief Suppression d'un FruitLegume du tableau dynamique
        @param nomFruitLeg nom du FruitLegume à supprimer du tableau 
        @param type (fruit/legume/graine)
    */
    void suppFruitLeg(string nomFruitLeg,string type);


    /*! @brief Donne des informations sur un FruitLegume
        @param nomFruitLeg nom du FruitLegume à rechercher 
    */
    FruitLegume chercherFruitLeg(string nomFruitLeg)const;

    /*! @brief Affiche les noms des FruitLegume présents dans le tableau 
    */
    void afficheListeFruitLeg()const;

    /*! @brief Rassemble tous les FruitLegume du jeu disponible au marché 
    */
    void banqueDeFruitLeg(); //utilisé pour le marché

    /*! @brief Test des fonctions du module
    */
    void testRegression();


};



#endif //_ENSEMBLE_FRUIT_LEG