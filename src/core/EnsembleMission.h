/*!
* @brief Module gérant un ensemble de missions
* @file EnsembleMission.h
*/

#ifndef _ENSEMBLE_MISSION
#define _ENSEMBLE_MISSION

#include "Mission.h"
#include <vector>
#include <iostream>

using namespace std;

/*! @brief EnsembleActivite : un tableau dynamique d'Activites
*/
class EnsembleMission {
public:

    vector<Mission> * tabMission;

    /*! @brief Constructeur par défaut : alloue sur le tas 
    *   un tableau dynamique de missions
    */
    EnsembleMission();

    /*! @brief Destructeur : supprime le tableau alloué sur le tas 
    */
    ~EnsembleMission();

    /*! @brief Ajout d'une activite dans le tableau dynamique
        @param mission Mission à ajouter au tableau 
    */ 
    void ajouterMission(const Mission & mission);

    /*! @brief Rempli l'ensembleMission de toutes les missions*/
    void banqueMission();

    /*! @brief Test des fonctions du module
    */
    void testRegression();

};

#endif //_ENSEMBLE_MISSION