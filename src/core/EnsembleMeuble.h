/**
    @brief Module gérant un ensemble de Meuble
    @file EnsembleMeuble.h

*/

#ifndef _ENSEMBLE_MEUBLE
#define _ENSEMBLE_MEUBLE
#include "Meuble.h"
#include <vector>
#include <iostream>

using namespace std;

/*! @class un EnsembleMeuble = un tableau dynamique de Meuble
*/
class EnsembleMeuble {

public: 
  
    vector<Meuble> * tabMeuble;
   

    /*! @brief Constructeur par défaut : alloue sur le tas un tableau dynamique de Meuble 
    */
    EnsembleMeuble();

    /*! @brief Destructeur : supprime le tableau alloué sur le tas 
    */
    ~EnsembleMeuble();
    
    /*! @brief Ajout d'un Meuble dans le tableau dynamique
        @param meuble Meuble à ajouter au tableau 
    */ 
    void ajouterMeuble(const Meuble & meuble);

    /*! @brief Suppression d'un Meuble du tableau dynamique
        @param nomMeuble nom du Meuble à supprimer du tableau 
    */
    void suppMeuble(string nomMeuble);

    /*! @brief Affiche les noms des Meubles présents dans le tableau 
    */
    void afficheListeMeuble()const;

    /*! @brief Test des fonctions du module
    */
    void testRegression();

};



#endif //_ENSEMBLE_MEUBLE