/**
    @brief Module gérant un ensemble de Terrain
    @file EnsembleTerrain.h

*/

#ifndef _ENSEMBLE_TERRAIN
#define _ENSEMBLE_TERRAIN
#include "Terrain.h"
#include <vector>
#include <iostream>


/*! @brief un EnsembleTerrain = un tableau dynamique de Terrain
*/
class EnsembleTerrain {

public: 
  
    vector<Terrain> tabTerrain;
    Terrain * terrCourant;
   

    /*! @brief Constructeur par défaut : alloue sur le tas un tableau dynamique de Terrain 
    */
    EnsembleTerrain();

    /*! @brief Destructeur : supprime le tableau alloué sur le tas 
    */
    ~EnsembleTerrain();
    
    /*! @brief Ajout d'un Terrain dans le tableau dynamique
        @param terrain Terrain à ajouter au tableau 
    */ 
    void ajouterMeuble(const Terrain & terrain);

    /*! @brief Suppression d'un Meuble du tableau dynamique
        @param nomMeuble nom du Meuble à supprimer du tableau 
    */
    void suppTerrain(string nomTerrain);

    /*! @brief Affiche les Terrains présents dans le tableau 
    */
    void afficheTerrains();

    /*! @brief Remplie l'ensembleTerrain de tout les Terrain du Jeu */
    void banqueDeTerrain();

    /*! @brief Test des fonctions du module
    */
    void testRegression();

};

#endif //_ENSEMBLE_TERRAIN
