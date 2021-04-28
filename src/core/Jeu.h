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
#include "EnsembleMission.h"



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
    EnsembleFruitLeg fruitsLeg;
    EnsembleMission mission;

public :

    Jeu ();

    EnsembleTerrain& getTerrain ();
    Personnage& getPersonnage ();
    EnsembleJardin& getJardin();
    EnsemblePnj& getPnjs();
    EnsembleActivite& getActivites();
    EnsembleFruitLeg& getFruitLeg();
    EnsembleMission& getMissions();

    const EnsembleTerrain& getConstTerrain () const;
    const Personnage& getConstPersonnage () const;
    const EnsembleJardin& getConstJardin() const;
    const EnsemblePnj& getConstPnjs() const;
    const EnsembleActivite& getConstActivites() const;
    const EnsembleFruitLeg& getConstFruitLeg() const;
    const EnsembleMission& getConstMissions() const;

   

    /*! @brief Plante une graine. Renvoit true si la graine a été plantée avec succes
        @param nom nom de la graineà planter
        @param nx position en x du jardin où il faut planter la graine
        @param ny position en y du jardin où il faut planter la graine
    */        
    bool planter(string nom,unsigned int nx, unsigned int ny);


    /*!
        @brief Recolte une graine et place son fruit dans l'inventaire du perso
        @param nx position en x du jardin où il faut planter la graine
        @param ny position en y du jardin où il faut planter la graine
    */ 
    void recolter(unsigned int nx,unsigned int ny);

    /*!
        @brief Achete une graine de fruitLeg au marché 
        @param reponse nom de la graine où le perso a cliqué
    */ 
    void acheter(string reponse);

    /*!
        @brief Vend une graine de fruitLeg au marché 
        @param reponse nom de la graine où le perso a cliqué
    */ 
    void vendre(string reponse);
    
    bool posJardinValide();

    void actionsAutomatiques ();
    
    void actionClavier(const char touche); 

    void testRegression();

};

#endif
