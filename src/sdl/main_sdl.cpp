#include "sdlJeu.h"


int main(int argc, char *argv[]){

    SDL_Surface * ecran = NULL;
    SDL_Surface * menu = NULL;

    SDL_Rect positionMenu;

    SDL_Init(SDL_INIT_VIDEO);

    SDL_Event event;

    SDL_WM_SetIcon(IMG_Load("./data/kirby1.png"), NULL);
    
    ecran = SDL_SetVideoMode(952,442,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Crossing Life 1.0",NULL);

    menu = IMG_Load("./data/menu2.png");

     positionMenu.x = 0;
     positionMenu.y = 0;
     int continuer = 3;
     while(continuer){
         
         SDL_WaitEvent(&event);
         switch(event.type){

             case SDL_QUIT:
             continuer = 0;
             break;

             

             case SDL_KEYDOWN:
             switch(event.key.keysym.sym){
                case SDLK_ESCAPE:
                continuer = 0;
                break;    

                case SDLK_p:
                jouer(ecran);
                break;   

                     
             }
             break;

             

         }
         SDL_BlitSurface(menu,NULL,ecran,&positionMenu);
         SDL_Flip(ecran);
     }

     SDL_FreeSurface(menu);
     SDL_Quit();
     return EXIT_SUCCESS;

    
}