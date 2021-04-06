/**
    @brief Module gérant un ensemble d'Activites
    @file EnsembleActivite.h

*/

#ifndef _ENSEMBLE_ACTIVITE
#define _ENSEMBLE_ACTIVITE
#include "Activite.h"
#include <vector>
#include <iostream>

using namespace std;

/*! @class un EnsembleActivite = un tableau dynamique d'Activites
*/
class EnsembleActivite {

public: 
  
    vector<Activite> tabActivite;
   

    /*! @brief Constructeur par défaut : alloue sur le tas un tableau dynamique d'activites 
    */
    EnsembleActivite();

    /*! @brief Destructeur : supprime le tableau alloué sur le tas 
    */
    ~EnsembleActivite();
    
    /*! @brief Ajout d'une activite dans le tableau dynamique
        @param Activite Activite à ajouter au tableau 
    */ 
    void ajouterActivite(const Activite & Activite);

    /*! @brief Suppression d'une activite du tableau dynamique
        @param nomActivite nom de l'activite à supprimer du tableau 
    */
    void suppActivite(string nomActivite);

    /*! @brief Affiche les noms des activites présentes dans le tableau 
    */
    void afficheListeActivite()const;

    /*! @brief Affectation d'un EnsembleActivite à un autre
    */
    EnsembleActivite operator= (const EnsembleActivite & copieActivite);

    /*! @brief Rempli l'ensembleActivite de tout les Activite*/
    void banqueDeActivite();

    /*! @brief Test des fonctions du module
    */
    void testRegression();

};



#endif //_ENSEMBLE_ACTIVITE
