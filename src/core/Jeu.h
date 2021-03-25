/**
    @brief Module gérant un Jeu (Crossing Life)

    @file Jeu.h
   
*/

#ifndef _JEU_H
#define _JEU_H

#include "Personnage.h"
#include "Terrain.h"
#include "EnsembleJardin.h"

/**
    @brief Un jeu  = un terrain, un personnage et un jardin
*/
class Jeu {

private :

	Terrain ter;
	Personnage perso;
	EnsembleJardin jardin;

public :

    Jeu ();

    EnsembleTerrain& getTerrain ();
    Personnage& getPersonnage ();
    EnsembleJardin& getJardin();

    const Terrain& getConstTerrain () const;
    const Personnage& getConstPersonnage () const;
    const EnsembleJardin& getConstJardin() const;


    //void actionsAutomatiques ();
    
    void actionClavier(const char touche); 

};

#endif
