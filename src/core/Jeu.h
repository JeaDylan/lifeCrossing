/**
    @brief Module gérant un Jeu (Crossing Life)

    @file Jeu.h
   
*/

#ifndef _JEU_H
#define _JEU_H

#include <time.h>
#include <unistd.h>

#include "Personnage.h"
#include "EnsembleTerrain.h"
#include "EnsembleJardin.h"
#include "EnsemblePnj.h"
#include "EnsembleActivite.h"


/**
    @brief Un jeu  = un terrain, un personnage et un jardin
*/
class Jeu {

private :

	EnsembleTerrain ter;
	Personnage perso;
	EnsembleJardin jardin;
    EnsemblePnj pnjs;
    EnsembleActivite activites;
    //EnsembleMission mission;

public :

    Jeu ();

    EnsembleTerrain& getTerrain ();
    Personnage& getPersonnage ();
    EnsembleJardin& getJardin();
    EnsemblePnj& getPnjs();
    EnsembleActivite& getActivites();


    const EnsembleTerrain& getConstTerrain () const;
    const Personnage& getConstPersonnage () const;
    const EnsembleJardin& getConstJardin() const;
    const EnsemblePnj& getConstPnjs() const;
    const EnsembleActivite& getConstActivites() const;

    /*! @brief Recolter range un FruitLegume dans l'inventaire du perso
    */
        
    bool planter(string nom,unsigned int nx, unsigned int ny);

    void recolter();

    //void actionsAutomatiques ();
    
    void actionClavier(const char touche); 

    void testRegression();

};

#endif
