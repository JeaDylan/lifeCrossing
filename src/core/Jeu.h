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


/**
    @brief Un jeu  = un terrain, un personnage et un jardin
*/
class Jeu {

private :

	EnsembleTerrain ter;
	Personnage perso;
	EnsembleJardin jardin;
    //EnsembleMission mission;

public :

    Jeu ();

    EnsembleTerrain& getTerrain ();
    Personnage& getPersonnage ();
    EnsembleJardin& getJardin();

    const EnsembleTerrain& getConstTerrain () const;
    const Personnage& getConstPersonnage () const;
    const EnsembleJardin& getConstJardin() const;

    /*! @brief Recolter range un FruitLegume dans l'inventaire du perso
    */
        
    bool planter(string nom,unsigned int nx, unsigned int ny);

    void recolter();

    //void actionsAutomatiques ();
    
    void actionClavier(const char touche); 

    void testRegression();

};

#endif
