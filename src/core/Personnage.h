/**
    @brief Module gérant un Personnage
    @file Personnage.h
*/

/*!
* \brief Personnage est une class qui contient le Personnage jouable sur les terrain.
*/

#ifndef _PERSONNAGE
#define _PERSONNAGE
#include <iostream>
#include <strings.h>
#include "Terrain.h"
#include "Point2D.h"

using namespace std;

class Personnage {
private:
    string nom;
    char avatar;
    unsigned int argent;
    //Vie vie;
    Point2D position;
    //Jauge niveau;
    //Jauge xp;
    //Inventaire inventaire;

public:
    /*! @brief Constructeur par defaut : initialise les caractéristiques d'un personnage
    */
    Personnage();

    /*! @brief Constructeur par copie : initialise les caractéristiques d'un personnage
    @param nomP nom du personnage (identifiant)
    @param sexe sexe du personnage
    @param avatar avatar du personnage
    */
    Personnage(string nomP, unsigned int argentPerso,Point2D positionPerso);
    
    /*! @brief Destructeur: suppression d'un personnage
    */
    ~Personnage();

    /*! @brief Accesseur : récupère le nom du personnage */
    string getNom() const;

    /*! @brief Accesseur : récupère l'avatar du personnage */
    char getAvatar() const;

    /*! @brief Accesseur : récupère l'argent du personnage */
    unsigned int getArgent() const;

    /*! @brief Mutateur : modifie le nom du personnage
    @param nomP nom est remplacé par nomP */
    void setNom(string nomP);

    /*! @brief Mutateur : modifie l'avatar du personnage
    @param avatarP avatar est remplacé par avatarP */
    void setAvatar(char avatarP);
    
    /*! @brief Mutateur : modifie l'argent du personnage (gain)
    @param gain argent += gain */
    void gainArgent(unsigned int gain);
    
    /*! @brief Mutateur : modifie l'argent du personnage (perte)
    @param perte argent -= perte */
    void perteArgent(unsigned int perte);

    /*! @brief Déplacement sur la gauche du personnage
    @param terrain la position2D du personnage est modifiée d'une case vers la gauche */
    void gauche (const Terrain& terrain);

    /*! @brief Déplacement sur la droite du personnage
    @param terrain la position2D du personnage est modifiée d'une case vers la droite */
    void droite (const Terrain& terrain);

    /*! @brief Déplacement vers le haut du personnage
    @param terrain la position2D du personnage est modifiée d'une case vers le haut */
    void haut (const Terrain& terrain);

    /*! @brief Déplacement vers le bas du personnage
    @param terrain la position2D du personnage est modifiée d'une case vers le bas */
    void bas (const Terrain& terrain);

    /*! @brief Choix de faire une activité
    @param terrain Le personnage peut choisir de faire une activité s'il s'approche d'une zone d'activité sur le terrain */
    bool choixActivite (Terrain terrain);

    /*! @brief Choix de discuter avec un PNJ
    @param terrain Le personnage peut choisir de discuter s'il s'approche d'un PNJ sur le terrain */
    bool choixDiscuterPnj (Terrain terrain);

    /*! @brief Choix d'aller au marché
    @param terrain Le personnage peut choisir d'aller au marché s'il s'approche d'une zone de marché sur le terrain */
    bool choixAcheterMarche (Terrain terrain);


    /*! @brief Affiche les données du personnage */
    void affichePersonnage() const;
     
    /*! @brief Test des fonctions du module*/
    void testRegression();

};

#endif