/*!
* @brief Module gérant un ensemble de PNJ
* @file EnsemblePnj.h
*/

#ifndef _ENSEMBLE_PNJ
#define _ENSEMBLE_PNJ
#include "Pnj.h"
#include <vector>
#include <iostream>

using namespace std;

/*! @brief EnsemblePnj : un tableau dynamique de Pnj
*/
class EnsemblePnj {

public: 
  
    vector<Pnj> tabPnj;
   

    /*! @brief Constructeur par défaut : alloue sur le tas un tableau dynamique de PNJ 
    */
    EnsemblePnj();

    /*! @brief Destructeur : supprime le tableau alloué sur le tas 
    */
    ~EnsemblePnj();
    
    /*! @brief Ajout d'un PNJ dans le tableau dynamique
        @param Pnj PNJ à ajouter au tableau 
    */ 
    void ajouterPnj(const Pnj & Pnj);

    /*! @brief Suppression d'un Pnj du tableau dynamique
        @param nomPnj nom du Pnj à supprimer du tableau 
    */
    void suppPnj(string nomPnj);

    /*! @brief Affiche les noms des Pnj présents dans le tableau 
    */
    void afficheListePnj()const;

    /*! @brief Affectation d'un EnsemblePnj à un autre
    */
    EnsemblePnj operator= (const EnsemblePnj & copiePnj);

    /*! @brief Rempli l'ensemblePnj de tout les Pnj*/
    void banqueDePnj();

    /*! @brief Test des fonctions du module
    */
    void testRegression();

};



#endif //_ENSEMBLE_PNJ
