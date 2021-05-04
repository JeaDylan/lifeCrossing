/**
    @brief Module gérant un Pnj (Personnage Non Joueur)
    @file Pnj.h

*/
#ifndef _PNJ
#define _PNJ
#include <strings.h>
#include "Point2D.h"
#include "Mission.h"
#include <iostream>
using namespace std;

/*! @brief Pnj : un personnage non jouable, défini par un nom, une position, une phrase de dialogue, 
    et une mission 
*/
class Pnj {
private:
    string nom;
    string dialogue;
    //Mission mission;
    Point2D position;
    

public:
    /*! @brief Constructeur par défaut : valeur par défaut d'un PNJ 
    */
    Pnj();

    /*! @brief Constructeur par copie : initialise les caractéristiques d'un PNJ
    @param nomPNJ nom du PNJ
    @param dialoguePNJ phrase de dialogue du PNJ lorsque le joueur interagit avec 
    @param mission mission donnée par le PNJ au joueur
    @param position position du PNJ dans le terrain
    */
    Pnj(string nomPNJ, string dialoguePNJ, /*Mission mission,*/ Point2D position);
    
    /*! @brief Destructeur : suppression d'un PNJ
    */
    ~Pnj();
  
    /*! @brief Accesseur : récupère le nom d'un PNJ */
    string getNom() const;
    
    /*! @brief Accesseur : récupère la phrase de dialogue d'un PNJ */
    string getDialogue() const;
    
    /*! @brief Accesseur : récupère la position d'un PNJ */
    Point2D getPosition() const;
    
    /*! @brief Accesseur : récupère la mission d'un PNJ */
    //Mission getMission() const;

    /*! @brief Mutateur : modifie le nom du PNJ
        @param nomPNJ nom est remplacé par nomPNJ */
    void setNom(string nomPNJ);

    /*! @brief Mutateur : modifie la phrase de dialogue du PNJ
        @param dialoguePNJ dialogue est remplacé par dialoguePNJ */ 
    void setDialogue(string dialoguePNJ);


    /*! @brief Affiche le PNJ*/
    void affichePNJ() const;
    
    /*! @brief Test des fonctions du module*/
    void testRegression();
};

#endif //_PNJ
