/*!
* \brief sdlJeu Moteur de jeu gérant la version graphique
*/

#ifndef _SDL_JEU
#define _SDL_JEU
#include"constantes.h"
#include "map.h"
#include "../core/Jeu.h"
#include <stdio.h>
#include <stdlib.h>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

/*! @brief Moteur de jeu graphique, charge toutes les cartes disponibles 
    @param ecran fenêtre gérée par SDL
    @param jeu moteur de jeu
    @param map réunit toutes les cartes du jeu
*/
void jouer(SDL_Surface * ecran,Jeu & jeu,Map & map);

/*! @brief Permet au personnage de se déplacer d'une carte à une autre
    @param ecran fenêtre gérée par SDL
    @param nb_carte indique la carte à utiliser
    @param jeu moteur de jeu
    @param map réunit toutes les cartes du jeu
*/
void teleporter(SDL_Surface * ecran,int nb_carte,Jeu & jeu,Map & map);

/*! @brief Gère les téléportations et position du personnage
    @param pos position du joueur
    @param direction HAUT,BAS,DROITE,GAUCHE
    @param ecran fenêtre gérée par SDL
    @param n permet de quitter une carte
    @param nb_carte indique la carte à utiliser
    @param jeu moteur de jeu
    @param map réunit toutes les cartes du jeu
*/
void deplacerJoueur(SDL_Rect *pos,int direction,SDL_Surface *ecran,int & n,int nb_carte,Jeu & jeu,Map & map);


/*!
    @brief Plante une graine en version graphique
    @param ecran fenêtre du jeu
    @param position de la fenêtre
    @param b est égal à true si une graine a été plantée avec succes
    @param jeu moteur de jeu
    @param map réunit toutes les cartes du jeu
*/
void sdlPlanter(SDL_Surface *ecran,const SDL_Rect *pos,bool &b,Jeu & jeu,Map & map);

/*! 
    @brief Renvoit la chaîne de char correspondant au fruitLeg à partir d'un nombre
    @param n nombre correspondant à une constante dans le fichier constantes.h
*/
string transformeConstantes(int n);



#endif //_SDL_JEU