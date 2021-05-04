/*!
* @brief Module gérant un ensemble de Portails
* @file EnsemblePortail.h
*/

#ifndef _ENSEMBLE_PORTAIL
#define _ENSEMBLE_PORTAIL
#include "Portail.h"
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

/*! @brief EnsemblePortail : un tableau dynamique de Portail
*/
class EnsemblePortail {

public: 
  
    vector<Portail> tabPortail;
   

    /*! @brief Constructeur par défaut : alloue sur le tas un tableau dynamique de Portail 
    */
    EnsemblePortail();

    /*! @brief Destructeur : supprime le tableau alloué sur le tas 
    */
    ~EnsemblePortail();
    
    /*! @brief Ajout d'un Portail dans le tableau dynamique
        @param Portail Portail à ajouter au tableau 
    */ 
    void ajouterPortail(const Portail & Portail);

    /*! @brief Suppression d'un Portail du tableau dynamique
        @param nomPortail nom du Portail à supprimer du tableau 
    */
    void suppPortail(string nomPortail);

    /*! @brief Affiche les noms des Portails présents dans le tableau 
    */
    void afficheListePortail()const;

    /*! @brief Affectation d'un EnsemblePortail à un autre
    */
    EnsemblePortail operator= (const EnsemblePortail & copiePortails);

    void banqueDePortailQuartierFichier(string nom_fichier);

    /*! @brief Test des fonctions du module
    */
    void testRegression();

};



#endif //_ENSEMBLE_PORTAIL
