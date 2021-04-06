#include "sdlJeu.h"


SDL_Rect position, positionJoueur;

void jouer(SDL_Surface * ecran){
    SDL_Surface *perso[4] =  {NULL};
    SDL_Surface *persoActuel = NULL;

   // SDL_Surface *mur=NULL;

    SDL_Rect positionFond;
    SDL_Surface *fond=NULL;



    SDL_Event event;
    int continuer = 1;
    int i = 0, j=0;

    
int **carte=(int**)malloc(12*sizeof(int*));
for(i=0;i<12;i++){
    carte[i]=(int*)malloc(27*sizeof(int));
}

carte[0][0]=0;  //0 = Vide 1= Mur
carte[0][1]=0;
carte[0][2]=0;
carte[0][3]=0;
carte[0][4]=0;
carte[0][5]=0;
carte[0][6]=0;
carte[0][7]=0;
carte[0][8]=0;
carte[0][9]=0;
carte[0][10]=0;
carte[0][11]=0;
carte[0][12]=0;
carte[0][13]=0;
carte[0][14]=0;
carte[0][15]=0;
carte[0][16]=0;
carte[0][17]=0;
carte[0][18]=0;
carte[0][19]=0;
carte[0][20]=0;
carte[0][21]=0;
carte[0][22]=0;
carte[0][23]=0;
carte[0][24]=0;
carte[0][25]=0;

carte[1][0]=0;
carte[1][1]=0;
carte[1][2]=0;
carte[1][3]=0;
carte[1][4]=0;
carte[1][5]=0;
carte[1][6]=0;
carte[1][7]=0;
carte[1][8]=0;
carte[1][9]=0;
carte[1][10]=0;
carte[1][11]=0;
carte[1][12]=0;
carte[1][13]=0;
carte[1][14]=0;
carte[1][15]=0;
carte[1][16]=0;
carte[1][17]=0;
carte[1][18]=0;
carte[1][19]=0;
carte[1][20]=0;
carte[1][21]=0;
carte[1][22]=0;
carte[1][23]=0;
carte[1][24]=0;
carte[1][25]=0;

carte[2][0]=0;
carte[2][1]=0;
carte[2][2]=1;
carte[2][3]=1;
carte[2][4]=1;
carte[2][5]=1;
carte[2][6]=1;
carte[2][7]=1;
carte[2][8]=1;
carte[2][9]=1;
carte[2][10]=1;
carte[2][11]=1;
carte[2][12]=1;
carte[2][13]=1;
carte[2][14]=1;
carte[2][15]=1;
carte[2][16]=1;
carte[2][17]=1;
carte[2][18]=1;
carte[2][19]=1;
carte[2][20]=1;
carte[2][21]=1;
carte[2][22]=1;
carte[2][23]=1;
carte[2][24]=1;
carte[2][25]=1;

carte[3][0]=0;
carte[3][1]=0;
carte[3][2]=1;
carte[3][3]=0;
carte[3][4]=0;
carte[3][5]=0;
carte[3][6]=0;
carte[3][7]=0;
carte[3][8]=0;
carte[3][9]=0;
carte[3][10]=0;
carte[3][11]=1;
carte[3][12]=1;
carte[3][13]=0;
carte[3][14]=0;
carte[3][15]=0;
carte[3][16]=0;
carte[3][17]=0;
carte[3][18]=0;
carte[3][19]=0;
carte[3][20]=0;
carte[3][21]=0;
carte[3][22]=0;
carte[3][23]=0;
carte[3][24]=0;
carte[3][25]=1;

carte[4][0]=0;
carte[4][1]=0;
carte[4][2]=1;
carte[4][3]=0;
carte[4][4]=0;
carte[4][5]=0;
carte[4][6]=0;
carte[4][7]=0;
carte[4][8]=0;
carte[4][9]=0;
carte[4][10]=0;
carte[4][11]=1;
carte[4][12]=1;
carte[4][13]=1;
carte[4][14]=1;
carte[4][15]=1;
carte[4][16]=1;
carte[4][17]=1;
carte[4][18]=0;
carte[4][19]=0;
carte[4][20]=0;
carte[4][21]=0;
carte[4][22]=0;
carte[4][23]=0;
carte[4][24]=0;
carte[4][25]=1;

carte[5][0]=0;
carte[5][1]=0;
carte[5][2]=1;
carte[5][3]=0;
carte[5][4]=0;
carte[5][5]=0;
carte[5][6]=0;
carte[5][7]=0;
carte[5][8]=0;
carte[5][9]=0;
carte[5][10]=0;
carte[5][11]=0;
carte[5][12]=0;
carte[5][13]=0;
carte[5][14]=0;
carte[5][15]=0;
carte[5][16]=0;
carte[5][17]=0;
carte[5][18]=0;
carte[5][19]=0;
carte[5][20]=0;
carte[5][21]=0;
carte[5][22]=0;
carte[5][23]=0;
carte[5][24]=0;
carte[5][25]=1;
carte[5][25]=1;

carte[6][0]=0;
carte[6][1]=0;
carte[6][2]=0;
carte[6][3]=0;
carte[6][4]=0;
carte[6][5]=0;
carte[6][6]=0;
carte[6][7]=0;
carte[6][8]=0;
carte[6][9]=1;
carte[6][10]=1;
carte[6][11]=1;
carte[6][12]=1;
carte[6][13]=1;
carte[6][14]=1;
carte[6][15]=1;
carte[6][16]=1;
carte[6][17]=1;
carte[6][18]=1;
carte[6][19]=0;
carte[6][20]=0;
carte[6][21]=0;
carte[6][22]=0;
carte[6][23]=0;
carte[6][24]=0;
carte[6][25]=0;

carte[7][0]=0;
carte[7][1]=0;
carte[7][2]=1;
carte[7][3]=0;
carte[7][4]=0;
carte[7][5]=0;
carte[7][6]=0;
carte[7][7]=0;
carte[7][8]=0;
carte[7][9]=1;
carte[7][10]=1;
carte[7][11]=1;
carte[7][12]=1;
carte[7][13]=1;
carte[7][14]=1;
carte[7][15]=1;
carte[7][16]=1;
carte[7][17]=1;
carte[7][18]=1;
carte[7][19]=0;
carte[7][20]=0;
carte[7][21]=0;
carte[7][22]=0;
carte[7][23]=0;
carte[7][24]=0;
carte[7][25]=1;

carte[8][0]=0;
carte[8][1]=0;
carte[8][2]=1;
carte[8][3]=0;
carte[8][4]=0;
carte[8][5]=0;
carte[8][6]=0;
carte[8][7]=0;
carte[8][8]=0;
carte[8][9]=0;
carte[8][10]=0;
carte[8][11]=1;
carte[8][12]=1;
carte[8][13]=1;
carte[8][14]=1;
carte[8][15]=0;
carte[8][16]=0;
carte[8][17]=0;
carte[8][18]=0;
carte[8][19]=0;
carte[8][20]=0;
carte[8][21]=0;
carte[8][22]=0;
carte[8][23]=0;
carte[8][24]=0;
carte[8][25]=1;

carte[9][0]=0;
carte[9][1]=0;
carte[9][2]=1;
carte[9][3]=0;
carte[9][4]=0;
carte[9][5]=0;
carte[9][6]=0;
carte[9][7]=0;
carte[9][8]=0;
carte[9][9]=0;
carte[9][10]=0;
carte[9][11]=0;
carte[9][12]=0;
carte[9][13]=0;
carte[9][14]=0;
carte[9][15]=0;
carte[9][16]=0;
carte[9][17]=0;
carte[9][18]=0;
carte[9][19]=0;
carte[9][20]=0;
carte[9][21]=0;
carte[9][22]=0;
carte[9][23]=0;
carte[9][24]=0;
carte[9][25]=1;

carte[10][0]=0;
carte[10][1]=0;
carte[10][2]=1;
carte[10][3]=0;
carte[10][4]=0;
carte[10][5]=0;
carte[10][6]=0;
carte[10][7]=0;
carte[10][8]=0;
carte[10][9]=0;
carte[10][10]=0;
carte[10][11]=0;
carte[10][12]=0;
carte[10][13]=0;
carte[10][14]=0;
carte[10][15]=0;
carte[10][16]=0;
carte[10][17]=0;
carte[10][18]=0;
carte[10][19]=0;
carte[10][20]=0;
carte[10][21]=0;
carte[10][22]=0;
carte[10][23]=0;
carte[10][24]=0;
carte[10][25]=1;

carte[11][0]=1;
carte[11][1]=1;
carte[11][2]=1;
carte[11][3]=1;
carte[11][4]=1;
carte[11][5]=1;
carte[11][6]=1;
carte[11][7]=1;
carte[11][8]=1;
carte[11][9]=1;
carte[11][10]=1;
carte[11][11]=1;
carte[11][12]=1;
carte[11][13]=1;
carte[11][14]=1;
carte[11][15]=1;
carte[11][16]=1;
carte[11][17]=1;
carte[11][18]=1;
carte[11][19]=1;
carte[11][20]=1;
carte[11][21]=1;
carte[11][22]=1;
carte[11][23]=1;
carte[11][24]=1;
carte[11][25]=1;
    

   fond=IMG_Load("./data/decor2.png"); 

   // mur = IMG_Load("./data/mur.png");

    perso[BAS] = IMG_Load("./data/kirby1.png");
    perso[HAUT] = IMG_Load("./data/kirby2.png");
    perso[DROITE] = IMG_Load("./data/kirby3.png");
    perso[GAUCHE] = IMG_Load("./data/kirby4.png");
    
    

    persoActuel = perso[BAS];

    positionJoueur.x = 22;
    positionJoueur.y = 10;

    carte[10][22]=PERSO;


    SDL_EnableKeyRepeat(100,100);

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
            deplacerJoueur(carte,&positionJoueur,HAUT, ecran);
            break;

            case SDLK_DOWN:
            persoActuel = perso[BAS];
            deplacerJoueur(carte,&positionJoueur,BAS, ecran);
            break;

            case SDLK_RIGHT:
            persoActuel = perso[DROITE];
            deplacerJoueur(carte,&positionJoueur,DROITE, ecran);
            break;

            case SDLK_LEFT:
            persoActuel = perso[GAUCHE];
            deplacerJoueur(carte,&positionJoueur,GAUCHE, ecran);
            break;
        }
        break;     
        
        
        
        
        }



    SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,255,255,255));
    
    positionFond.x=0;
    positionFond.y=0;
    SDL_BlitSurface(fond,NULL,ecran,&positionFond);

  /* for(i=0;i<11;i++){
        for(j=0;j<26;j++){
            position.x=j*TAILLE_BLOC;
            position.y=i*TAILLE_BLOC;

       switch(carte[i][j]){
            case MUR:
            SDL_BlitSurface(mur,NULL,ecran,&position);
            break;
        }

        }
    }*/

    position.x = positionJoueur.x*TAILLE_BLOC;
    position.y = positionJoueur.y*TAILLE_BLOC;

    SDL_BlitSurface(persoActuel,NULL,ecran,&position);
    
    SDL_Flip(ecran);
    }

    SDL_EnableKeyRepeat(0,0); //desactive la repetition des touche
   // SDL_FreeSurface(mur);




    for(i=0;i<4;i++){
        SDL_FreeSurface(perso[i]); //on libère les images du perso en memoire
    }


}


void marche(SDL_Surface * ecran) {

    SDL_Surface *perso[4] =  {NULL};
    SDL_Surface *persoActuel = NULL;

   // SDL_Surface *mur=NULL;

    SDL_Rect positionFond;
    SDL_Surface *fond=NULL;



    SDL_Event event;
    int continuer = 1;
    int i = 0, j=0;

    
int **carte=(int**)malloc(12*sizeof(int*));
for(i=0;i<12;i++){
    carte[i]=(int*)malloc(27*sizeof(int));
}

carte[0][0]=0;  //0 = Vide 1= Mur
carte[0][1]=0;
carte[0][2]=0;
carte[0][3]=0;
carte[0][4]=0;
carte[0][5]=0;
carte[0][6]=0;
carte[0][7]=0;
carte[0][8]=0;
carte[0][9]=0;
carte[0][10]=0;
carte[0][11]=0;
carte[0][12]=0;
carte[0][13]=0;
carte[0][14]=0;
carte[0][15]=0;
carte[0][16]=0;
carte[0][17]=0;
carte[0][18]=0;
carte[0][19]=0;
carte[0][20]=0;
carte[0][21]=0;
carte[0][22]=0;
carte[0][23]=0;
carte[0][24]=0;
carte[0][25]=0;

carte[1][0]=0;
carte[1][1]=0;
carte[1][2]=0;
carte[1][3]=0;
carte[1][4]=0;
carte[1][5]=0;
carte[1][6]=0;
carte[1][7]=0;
carte[1][8]=0;
carte[1][9]=0;
carte[1][10]=0;
carte[1][11]=0;
carte[1][12]=0;
carte[1][13]=0;
carte[1][14]=0;
carte[1][15]=0;
carte[1][16]=0;
carte[1][17]=0;
carte[1][18]=0;
carte[1][19]=0;
carte[1][20]=0;
carte[1][21]=0;
carte[1][22]=0;
carte[1][23]=0;
carte[1][24]=0;
carte[1][25]=0;

carte[2][0]=0;
carte[2][1]=0;
carte[2][2]=1;
carte[2][3]=1;
carte[2][4]=1;
carte[2][5]=1;
carte[2][6]=1;
carte[2][7]=1;
carte[2][8]=1;
carte[2][9]=1;
carte[2][10]=1;
carte[2][11]=1;
carte[2][12]=1;
carte[2][13]=1;
carte[2][14]=1;
carte[2][15]=1;
carte[2][16]=1;
carte[2][17]=1;
carte[2][18]=1;
carte[2][19]=1;
carte[2][20]=1;
carte[2][21]=1;
carte[2][22]=1;
carte[2][23]=1;
carte[2][24]=1;
carte[2][25]=1;

carte[3][0]=0;
carte[3][1]=0;
carte[3][2]=1;
carte[3][3]=0;
carte[3][4]=0;
carte[3][5]=0;
carte[3][6]=0;
carte[3][7]=0;
carte[3][8]=0;
carte[3][9]=0;
carte[3][10]=0;
carte[3][11]=1;
carte[3][12]=1;
carte[3][13]=0;
carte[3][14]=0;
carte[3][15]=0;
carte[3][16]=0;
carte[3][17]=0;
carte[3][18]=0;
carte[3][19]=0;
carte[3][20]=0;
carte[3][21]=0;
carte[3][22]=0;
carte[3][23]=0;
carte[3][24]=0;
carte[3][25]=1;

carte[4][0]=0;
carte[4][1]=0;
carte[4][2]=1;
carte[4][3]=0;
carte[4][4]=0;
carte[4][5]=0;
carte[4][6]=0;
carte[4][7]=0;
carte[4][8]=0;
carte[4][9]=0;
carte[4][10]=0;
carte[4][11]=1;
carte[4][12]=1;
carte[4][13]=1;
carte[4][14]=1;
carte[4][15]=1;
carte[4][16]=1;
carte[4][17]=1;
carte[4][18]=0;
carte[4][19]=0;
carte[4][20]=0;
carte[4][21]=0;
carte[4][22]=0;
carte[4][23]=0;
carte[4][24]=0;
carte[4][25]=1;

carte[5][0]=0;
carte[5][1]=0;
carte[5][2]=1;
carte[5][3]=0;
carte[5][4]=0;
carte[5][5]=0;
carte[5][6]=0;
carte[5][7]=0;
carte[5][8]=0;
carte[5][9]=0;
carte[5][10]=0;
carte[5][11]=0;
carte[5][12]=0;
carte[5][13]=0;
carte[5][14]=0;
carte[5][15]=0;
carte[5][16]=0;
carte[5][17]=0;
carte[5][18]=0;
carte[5][19]=0;
carte[5][20]=0;
carte[5][21]=0;
carte[5][22]=0;
carte[5][23]=0;
carte[5][24]=0;
carte[5][25]=1;
carte[5][25]=1;

carte[6][0]=0;
carte[6][1]=0;
carte[6][2]=0;
carte[6][3]=0;
carte[6][4]=0;
carte[6][5]=0;
carte[6][6]=0;
carte[6][7]=0;
carte[6][8]=0;
carte[6][9]=1;
carte[6][10]=1;
carte[6][11]=1;
carte[6][12]=1;
carte[6][13]=1;
carte[6][14]=1;
carte[6][15]=1;
carte[6][16]=1;
carte[6][17]=1;
carte[6][18]=1;
carte[6][19]=0;
carte[6][20]=0;
carte[6][21]=0;
carte[6][22]=0;
carte[6][23]=0;
carte[6][24]=0;
carte[6][25]=0;

carte[7][0]=0;
carte[7][1]=0;
carte[7][2]=1;
carte[7][3]=0;
carte[7][4]=0;
carte[7][5]=0;
carte[7][6]=0;
carte[7][7]=0;
carte[7][8]=0;
carte[7][9]=1;
carte[7][10]=1;
carte[7][11]=1;
carte[7][12]=1;
carte[7][13]=1;
carte[7][14]=1;
carte[7][15]=1;
carte[7][16]=1;
carte[7][17]=1;
carte[7][18]=1;
carte[7][19]=0;
carte[7][20]=0;
carte[7][21]=0;
carte[7][22]=0;
carte[7][23]=0;
carte[7][24]=0;
carte[7][25]=1;

carte[8][0]=0;
carte[8][1]=0;
carte[8][2]=1;
carte[8][3]=0;
carte[8][4]=0;
carte[8][5]=0;
carte[8][6]=0;
carte[8][7]=0;
carte[8][8]=0;
carte[8][9]=0;
carte[8][10]=0;
carte[8][11]=1;
carte[8][12]=1;
carte[8][13]=1;
carte[8][14]=1;
carte[8][15]=0;
carte[8][16]=0;
carte[8][17]=0;
carte[8][18]=0;
carte[8][19]=0;
carte[8][20]=0;
carte[8][21]=0;
carte[8][22]=0;
carte[8][23]=0;
carte[8][24]=0;
carte[8][25]=1;

carte[9][0]=0;
carte[9][1]=0;
carte[9][2]=1;
carte[9][3]=0;
carte[9][4]=0;
carte[9][5]=0;
carte[9][6]=0;
carte[9][7]=0;
carte[9][8]=0;
carte[9][9]=0;
carte[9][10]=0;
carte[9][11]=0;
carte[9][12]=0;
carte[9][13]=0;
carte[9][14]=0;
carte[9][15]=0;
carte[9][16]=0;
carte[9][17]=0;
carte[9][18]=0;
carte[9][19]=0;
carte[9][20]=0;
carte[9][21]=0;
carte[9][22]=0;
carte[9][23]=0;
carte[9][24]=0;
carte[9][25]=1;

carte[10][0]=0;
carte[10][1]=0;
carte[10][2]=1;
carte[10][3]=0;
carte[10][4]=0;
carte[10][5]=0;
carte[10][6]=0;
carte[10][7]=0;
carte[10][8]=0;
carte[10][9]=0;
carte[10][10]=0;
carte[10][11]=0;
carte[10][12]=0;
carte[10][13]=0;
carte[10][14]=0;
carte[10][15]=0;
carte[10][16]=0;
carte[10][17]=0;
carte[10][18]=0;
carte[10][19]=0;
carte[10][20]=0;
carte[10][21]=0;
carte[10][22]=0;
carte[10][23]=0;
carte[10][24]=0;
carte[10][25]=1;

carte[11][0]=1;
carte[11][1]=1;
carte[11][2]=1;
carte[11][3]=1;
carte[11][4]=1;
carte[11][5]=1;
carte[11][6]=1;
carte[11][7]=1;
carte[11][8]=1;
carte[11][9]=1;
carte[11][10]=1;
carte[11][11]=1;
carte[11][12]=1;
carte[11][13]=1;
carte[11][14]=1;
carte[11][15]=1;
carte[11][16]=1;
carte[11][17]=1;
carte[11][18]=1;
carte[11][19]=1;
carte[11][20]=1;
carte[11][21]=1;
carte[11][22]=1;
carte[11][23]=1;
carte[11][24]=1;
carte[11][25]=1;
    

   fond=IMG_Load("./data/decor.png"); 

   // mur = IMG_Load("./data/mur.png");

    perso[BAS] = IMG_Load("./data/kirby1.png");
    perso[HAUT] = IMG_Load("./data/kirby2.png");
    perso[DROITE] = IMG_Load("./data/kirby3.png");
    perso[GAUCHE] = IMG_Load("./data/kirby4.png");
    
    

    persoActuel = perso[BAS];

    positionJoueur.x = 22;
    positionJoueur.y = 10;

    carte[10][22]=PERSO;


    SDL_EnableKeyRepeat(100,100);

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
            deplacerMarche(carte,&positionJoueur,HAUT, ecran);
            break;

            case SDLK_DOWN:
            persoActuel = perso[BAS];
            deplacerMarche(carte,&positionJoueur,BAS, ecran);
            break;

            case SDLK_RIGHT:
            persoActuel = perso[DROITE];
            deplacerMarche(carte,&positionJoueur,DROITE, ecran);
            break;

            case SDLK_LEFT:
            persoActuel = perso[GAUCHE];
            deplacerMarche(carte,&positionJoueur,GAUCHE, ecran);
            break;
        }
        break;     
        
        
        
        
        }



    SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,255,255,255));
    
    positionFond.x=0;
    positionFond.y=0;
    SDL_BlitSurface(fond,NULL,ecran,&positionFond);

  /* for(i=0;i<11;i++){
        for(j=0;j<26;j++){
            position.x=j*TAILLE_BLOC;
            position.y=i*TAILLE_BLOC;

       switch(carte[i][j]){
            case MUR:
            SDL_BlitSurface(mur,NULL,ecran,&position);
            break;
        }

        }
    }*/

    position.x = positionJoueur.x*TAILLE_BLOC;
    position.y = positionJoueur.y*TAILLE_BLOC;

    SDL_BlitSurface(persoActuel,NULL,ecran,&position);
    
    SDL_Flip(ecran);
    }

    SDL_EnableKeyRepeat(0,0); //desactive la repetition des touche
   // SDL_FreeSurface(mur);




    for(i=0;i<4;i++){
        SDL_FreeSurface(perso[i]); //on libère les images du perso en memoire
    }


}

void deplacerJoueur(int **carte,SDL_Rect *pos,int direction, SDL_Surface *ecran){
    switch(direction){
        case HAUT:
        if(carte[pos->y-1][pos->x] == MUR)//on verifie que la case en haut n'est pas un mur
            break;
        pos->y--;
        break;

        case BAS:
        if(carte[pos->y+1][pos->x] == MUR)//on verifie que la case en bas n'est pas un mur
            break;
        pos->y++;
        break;

        case GAUCHE:
        if(positionJoueur.x == 2 && positionJoueur.y == 6){//si le joueur se trouve a la 2e col et la 6e ligne
                                                           //alors le joueur se teleporte au marché
            marche(ecran);
            break;                                            
        }
        
        if(carte[pos->y][pos->x-1] == MUR)//on verifie que la case a gauche n'est pas un mur
            break;
        pos->x--;
        break;

        case DROITE:
        if(positionJoueur.x == 25 && positionJoueur.y == 6){//pareil que gauche
            marche(ecran);
            break;
        }
        
        if(carte[pos->y][pos->x+1] == MUR)//on verifie que la case a droite n'est pas un mur
            break;
        pos->x++;
        break;


    }
}

void deplacerMarche(int **carte,SDL_Rect *pos,int direction, SDL_Surface *ecran){
    switch(direction){
        case HAUT:
        if(carte[pos->y-1][pos->x] == MUR)//on verifie que la case en haut n'est pas un mur
            break;
        pos->y--;
        break;

        case BAS:
        if(carte[pos->y+1][pos->x] == MUR)//on verifie que la case en bas n'est pas un mur
            break;
        pos->y++;
        break;

        case GAUCHE:
        if(positionJoueur.x == 2 && positionJoueur.y == 6){//si le joueur se trouve a la 2e col et la 6e ligne
                                                          //alors le joueur se teleporte dans le terrain principal
            jouer(ecran);
            break;                                            
        }
        
        if(carte[pos->y][pos->x-1] == MUR)//on verifie que la case a gauche n'est pas un mur
            break;
        pos->x--;
        break;

        case DROITE:
        if(positionJoueur.x == 25 && positionJoueur.y == 6){//pareil que gauche
            jouer(ecran);
            break;
        }
        
        if(carte[pos->y][pos->x+1] == MUR)//on verifie que la case a droite n'est pas un mur
            break;
        pos->x++;
        break;


    }
}