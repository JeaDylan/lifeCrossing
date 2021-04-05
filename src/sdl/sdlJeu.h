#ifndef _SDL_JEU
#define _SDL_JEU
#include"constantes.h"
#include <stdio.h>
#include <stdlib.h>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>



void jouer(SDL_Surface * ecran);
void deplacerJoueur(int **carte,SDL_Rect *pos,int direction);

#endif //_SDL_JEU