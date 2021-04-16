/*!
* \brief sdlJeu Moteur de jeu gérant la version graphique
*/

#ifndef _SDL_JEU
#define _SDL_JEU
#include"constantes.h"
#include "map.h"
//#include "Jeu.h"
#include <stdio.h>
#include <stdlib.h>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

/*! @brief Moteur de jeu graphique, charge toutes les cartes disponibles 
    @param ecran fenêtre gérée par SDL
*/
void jouer(SDL_Surface * ecran);

/*! @brief Permet au personnage de se déplacer d'une carte à une autre
    @param ecran fenêtre gérée par SDL
    @param nb_carte indique la carte à utiliser
*/
void teleporter(SDL_Surface * ecran,int nb_carte);

/*! @brief Gère les téléportations et position du personnage
    @param pos position du joueur
    @param direction HAUT,BAS,DROITE,GAUCHE
    @param ecran fenêtre gérée par SDL
    @param n permet de quitter une carte
    @param nb_carte indique la carte à utiliser
*/
void deplacerJoueur(SDL_Rect *pos,int direction,SDL_Surface *ecran,int & n,int nb_carte);



#endif //_SDL_JEU