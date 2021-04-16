#include "sdlJeu.h"





SDL_Rect position, positionJoueur,positionClic;

Map map;


void jouer(SDL_Surface * ecran){
    
   // Jeu jeu;
    
    
    SDL_Surface *perso[4] =  {NULL};
    SDL_Surface *persoActuel = NULL;

   

    SDL_Rect positionFond;
    SDL_Surface *fond=NULL;



    SDL_Event event;
    int continuer = 1;
    int i = 0, j=0;

    


   fond=IMG_Load("./data/carte1.png"); 
  

  

    perso[BAS] = IMG_Load("./data/kirby1.png");
    perso[HAUT] = IMG_Load("./data/kirby2.png");
    perso[DROITE] = IMG_Load("./data/kirby3.png");
    perso[GAUCHE] = IMG_Load("./data/kirby4.png");
    
    

    persoActuel = perso[BAS];

    positionJoueur.x = 12;
    positionJoueur.y = 5;

    map.carte1[5][12]=PERSO;


    SDL_EnableKeyRepeat(100,100);
    int n;

    while(continuer){
        SDL_WaitEvent(&event);
        switch(event.type){
            case SDL_QUIT:
            continuer = 0;
            break;

            case SDL_KEYDOWN:
            switch(event.key.keysym.sym){

            case  SDLK_ESCAPE:
            continuer = 0;
            break;
             
            case SDLK_RETURN:
            if(positionJoueur.x == 24 && positionJoueur.y == 3){
                teleporter(ecran,3);
                positionJoueur.x = 24; //on remet le perso devant la porte du magasin
                positionJoueur.y = 3;
                break;
            }
            if(positionJoueur.x == 10 && positionJoueur.y == 4){
                teleporter(ecran,4);
                positionJoueur.x = 10; //on remet le perso devant la porte de la maison
                positionJoueur.y = 4;
                break;

            }
            if(positionJoueur.x == 2 && positionJoueur.y == 4){
                teleporter(ecran,5);
                positionJoueur.x = 2; //on remet le perso devant la porte de la maison des PNJ
                positionJoueur.y = 5;
                break;

            }
            break;

            case SDLK_UP:
            persoActuel = perso[HAUT];
            deplacerJoueur(&positionJoueur,HAUT,ecran,n,1);
            if(n == 2){
                n = 0;
                teleporter(ecran,2);
                positionJoueur.x = 12;
                positionJoueur.y = 1;
                break;
            }
            break;

            case SDLK_DOWN:
            persoActuel = perso[BAS];
            deplacerJoueur(&positionJoueur,BAS,ecran,n,1);
            break;

            case SDLK_RIGHT:
            persoActuel = perso[DROITE];
            deplacerJoueur(&positionJoueur,DROITE,ecran,n,1);
            break;

            case SDLK_LEFT:
            persoActuel = perso[GAUCHE];
            deplacerJoueur(&positionJoueur,GAUCHE,ecran,n,1);
            break;
        }
        break;     

       
        
        
        }



    SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,255,255,255));
    
    positionFond.x=0;
    positionFond.y=0;
    SDL_BlitSurface(fond,NULL,ecran,&positionFond);
    

     

    position.x = positionJoueur.x*TAILLE_BLOC;
    position.y = positionJoueur.y*TAILLE_BLOC;

    SDL_BlitSurface(persoActuel,NULL,ecran,&position);
    
    SDL_Flip(ecran);
    }

    SDL_EnableKeyRepeat(0,0); //desactive la repetition des touche
    
 



    for(i=0;i<4;i++){
        SDL_FreeSurface(perso[i]); //on libère les images du perso en memoire
    }


}





void teleporter(SDL_Surface * ecran,int nb_carte) {

    SDL_Surface *perso[4] =  {NULL};
    SDL_Surface *persoActuel = NULL;
    SDL_Surface *plant = NULL;
    SDL_Surface *plant2= NULL;


    SDL_Rect positionFond;
    SDL_Surface *fond=NULL;
    



    SDL_Event event;
    int continuer = 1;
    int i = 0, j=0;

    
    
    switch(nb_carte){
        case 2:
        fond=IMG_Load("./data/carte2.png"); 
        break;

        case 3:
        fond=IMG_Load("./data/carte3.png"); 
        break;

        case 4:
        fond=IMG_Load("./data/carte4.png"); 
        break;


        case 5:
        fond=IMG_Load("./data/carte5.png"); 
        break;

    }



   plant = IMG_Load("./data/plant2.png");
   plant2 = IMG_Load("./data/plant5.png");

 

    perso[BAS] = IMG_Load("./data/kirby1.png");
    perso[HAUT] = IMG_Load("./data/kirby2.png");
    perso[DROITE] = IMG_Load("./data/kirby3.png");
    perso[GAUCHE] = IMG_Load("./data/kirby4.png");
    
    

    persoActuel = perso[BAS];

  

    switch(nb_carte){
        case 2:
        map.carte2[10][12]=PERSO;
        positionJoueur.x = 12;
        positionJoueur.y = 10;
        break;

        case 3:
        map.carte3[7][17]=PERSO;
        positionJoueur.x = 17;
        positionJoueur.y = 7;
        break;

        case 4:
        map.carte4[10][15]=PERSO;
        positionJoueur.x = 15;
        positionJoueur.y = 10;
        break;


        case 5:
        map.carte5[11][15]=PERSO;
        positionJoueur.x = 15;
        positionJoueur.y = 11;
        break;

    }

    


    SDL_EnableKeyRepeat(100,100);
    int n;

    while(continuer){
        SDL_WaitEvent(&event);
        switch(event.type){
            case SDL_QUIT:
            continuer = 0;
            break;

            case SDL_KEYDOWN:
            switch(event.key.keysym.sym){

            case  SDLK_ESCAPE:
            continuer = 0;
            break;


            case SDLK_UP:
            persoActuel = perso[HAUT];
            deplacerJoueur(&positionJoueur,HAUT, ecran,n,nb_carte);
            break;

            case SDLK_DOWN:
            persoActuel = perso[BAS];
            deplacerJoueur(&positionJoueur,BAS, ecran,n,nb_carte);
            if(n == 1){
                n = 0;
                continuer = 0;
            }
            break;

            case SDLK_RIGHT:
            persoActuel = perso[DROITE];
            deplacerJoueur(&positionJoueur,DROITE, ecran,n,nb_carte);
            if(n == 1){
                n = 0;
                continuer = 0;
            }            
            break;

            case SDLK_LEFT:
            persoActuel = perso[GAUCHE];
            deplacerJoueur(&positionJoueur,GAUCHE, ecran,n,nb_carte);
            break;

            } 
            break;

            case SDL_MOUSEBUTTONUP:
            //prendre en compte le choix du joueur
            if(nb_carte == 2){
            switch(event.button.button){
                case SDL_BUTTON_LEFT:
                    positionClic.x = event.button.x / 34;
                    positionClic.y = event.button.y / 34;
                        if(map.carte2[positionClic.y][positionClic.x] == 3 ){
                            //ajout de la fonction planter 
                        map.carte2[positionClic.y][positionClic.x] = 4 ;
                        }
                break;

                case SDL_BUTTON_RIGHT:
                positionClic.x = event.button.x / 34;
                    positionClic.y = event.button.y / 34;
                        if(map.carte2[positionClic.y][positionClic.x] == 4 ){
                        map.carte2[positionClic.y][positionClic.x] = 3 ;
                        }
                break;
        
        
            }
            }
            break;     
        
        
        
        
        }

    

    SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,255,255,255));
    
    positionFond.x=0;
    positionFond.y=0;
    SDL_BlitSurface(fond,NULL,ecran,&positionFond);

    if(nb_carte == 2){
    for(i=0;i<11;i++){
        for(j=0;j<26;j++){
            position.x=j*TAILLE_BLOC;
            position.y=i*TAILLE_BLOC;

       switch(map.carte2[i][j]){
            case PLANT:
            SDL_BlitSurface(plant,NULL,ecran,&position);
            break;

            case PLANT2:
            SDL_BlitSurface(plant2,NULL,ecran,&position);
            break;
        }

        }
    }
    }

 

    position.x = positionJoueur.x*TAILLE_BLOC;
    position.y = positionJoueur.y*TAILLE_BLOC;

    SDL_BlitSurface(persoActuel,NULL,ecran,&position);
    
    SDL_Flip(ecran);

   
    
    
    }

    SDL_EnableKeyRepeat(0,0); //desactive la repetition des touche

    SDL_FreeSurface(plant);
    SDL_FreeSurface(plant2);
 

    SDL_FreeSurface(fond);


    for(i=0;i<4;i++){
        SDL_FreeSurface(perso[i]); //on libère les images du perso en memoire
    }


}

void deplacerJoueur(SDL_Rect *pos,int direction, SDL_Surface *ecran,int &n,int nb_carte){
    switch(direction){
        case HAUT:
        
        if(nb_carte == 1){
            if(positionJoueur.x == 12 && positionJoueur.y == 1 ){
                n = 2;                                                         //alors le joueur se teleporte au jardin
                break; 
            }
            if(map.carte1[pos->y-1][pos->x] == MUR) //on verifie que la case en haut n'est pas un mur pour la carte 1
                break;
        }

        if(nb_carte == 2){
            
            if(map.carte2[pos->y-1][pos->x] == MUR) //on verifie que la case en haut n'est pas un mur pour la carte 2
                break;
        }
        
        if(nb_carte == 3){
            if(map.carte3[pos->y-1][pos->x] == MUR) //on verifie que la case en haut n'est pas un mur pour la carte 3
                break;
        }
            
        if(nb_carte == 4){
            if(map.carte4[pos->y-1][pos->x] == MUR) //on verifie que la case en haut n'est pas un mur pour la carte 4
                break;
        }

        if(nb_carte == 5){
        
            if(map.carte5[pos->y-1][pos->x] == MUR) //on verifie que la case en haut n'est pas un mur pour la carte 5
                break;
        }

        
        pos->y--;
        break;

        case BAS:
      
        if(nb_carte == 1){
            if(map.carte1[pos->y+1][pos->x] == MUR)//on verifie que la case en bas n'est pas un mur pour la carte 1
                break;
        }
        
        if(nb_carte == 2){
            if(positionJoueur.x == 13 && positionJoueur.y == 11 ){
                n = 1;                                                         //alors le joueur se teleporte au a la plage
                break; 
            }
            if(map.carte2[pos->y+1][pos->x] == MUR)//on verifie que la case en bas n'est pas un mur pour la carte 2
                break;
        }
        
        if(nb_carte == 3){
            if(map.carte3[pos->y+1][pos->x] == MUR) //on verifie que la case en bas n'est pas un mur pour la carte 3
                break;
        }
        
        if(nb_carte == 4){
            if(map.carte4[pos->y+1][pos->x] == MUR) //on verifie que la case en bas n'est pas un mur pour la carte 4
                break;
        }

        if(nb_carte == 5){
            if(positionJoueur.x == 15 && positionJoueur.y == 11){
                n = 1;
                break;
            }
            if(map.carte5[pos->y+1][pos->x] == MUR) //on verifie que la case en bas n'est pas un mur pour la carte 4
                break;
        }

        pos->y++;
        break;

        case GAUCHE:
        if(nb_carte == 1){
            if(map.carte1[pos->y][pos->x-1] == MUR )//on verifie que la case a gauche n'est pas un mur pour la carte 1
                break;
        }

        if(nb_carte == 2){
            if(map.carte2[pos->y][pos->x-1] == MUR )//on verifie que la case a gauche n'est pas un mur pour la carte 2
                break;
        }

        if(nb_carte == 3){
            if(map.carte3[pos->y][pos->x-1] == MUR) //on verifie que la case a gauche n'est pas un mur pour la carte 3
                break;
        }

        if(nb_carte == 4){
            if(map.carte4[pos->y][pos->x-1] == MUR) //on verifie que la case a gauche n'est pas un mur pour la carte 4
                break;
        }

        if(nb_carte == 5){
            if(map.carte5[pos->y][pos->x-1] == MUR) //on verifie que la case a gauche n'est pas un mur pour la carte 5
                break;
        }
            
        
        pos->x--;
        break;

        case DROITE:

        if(nb_carte == 1){
            if(map.carte1[pos->y][pos->x+1] == MUR )//on verifie que la case a droite n'est pas un mur pour la carte 1
                break;
        }
        
        if(nb_carte == 2){
            if(map.carte2[pos->y][pos->x+1] == MUR )//on verifie que la case a droite n'est pas un mur pour la carte 2
                break;
        }
        
        if(nb_carte == 3){
            if(positionJoueur.x == 18 && positionJoueur.y == 3){
                n = 1;
                break;
            }
            if(map.carte3[pos->y][pos->x+1] == MUR) //on verifie que la case à doroite n'est pas un mur pour la carte 3
                 break;
        }
        
        if(nb_carte == 4){
            if(map.carte4[pos->y][pos->x+1] == MUR) //on verifie que la case à doroite n'est pas un mur pour la carte 4
                break;
        }

        if(nb_carte == 5){
            if(map.carte5[pos->y][pos->x+1] == MUR) //on verifie que la case à doroite n'est pas un mur pour la carte 5
                break;
        }

        pos->x++;
        break;


    }

}

