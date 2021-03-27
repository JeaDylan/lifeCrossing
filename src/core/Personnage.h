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
    float argent;
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
    Personnage(string nomP, float argentPerso,Point2D positionPerso);
    
    /*! @brief Destructeur: suppression d'un personnage
    */
    ~Personnage();

    /*! @brief Accesseur : récupère le nom du personnage */
    string getNom() const;

    /*! @brief Accesseur : récupère l'avatar du personnage */
    char getAvatar() const;

    /*! @brief Accesseur : récupère l'argent du personnage */
    float getArgent() const;
    
    /*! @brief Accesseur : récupère la position en X du personnage */
    unsigned int getPosX() const;

    /*! @brief Accesseur : récupère la position en Y du personnage */
    unsigned int getPosY() const;
    
    /*! @brief Mutateur : modifie le nom du personnage
    @param nomP nom est remplacé par nomP */
    void setNom(string nomP);

    /*! @brief Mutateur : modifie l'avatar du personnage
    @param avatarP avatar est remplacé par avatarP */
    void setAvatar(char avatarP);
    
    /*! @brief Mutateur : modifie l'argent du personnage (gain)
    @param gain argent += gain */
    void gainArgent(float gain);
    
    /*! @brief Mutateur : modifie l'argent du personnage (perte)
    @param perte argent -= perte */
    void perteArgent(float perte);

    /*! @brief Mutateur : modifie la position en X du personnage 
    @param posX position.X devient posX */
    void setPosX(unsigned int posX);
    
    /*! @brief Mutateur : modifie la position en Y du personnage 
    @param posY position.Y devient posY */
    void setPosY(unsigned int posY);
    
    /*! @brief Déplacement sur la gauche du personnage
    @param terrain la position2D du personnage est modifiée d'une case vers la gauche */
    void gauche (Terrain& terrain);

    /*! @brief Déplacement sur la droite du personnage
    @param terrain la position2D du personnage est modifiée d'une case vers la droite */
    void droite (Terrain& terrain);

    /*! @brief Déplacement vers le haut du personnage
    @param terrain la position2D du personnage est modifiée d'une case vers le haut */
    void haut (Terrain& terrain);

    /*! @brief Déplacement vers le bas du personnage
    @param terrain la position2D du personnage est modifiée d'une case vers le bas */
    void bas (Terrain& terrain);

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
