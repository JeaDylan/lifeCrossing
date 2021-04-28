#include "sdlJeu.h"





SDL_Rect position, positionJoueur,positionClic;



void jouer(SDL_Surface * ecran,Jeu & jeu,Map & map){
    
   
    
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
                teleporter(ecran,3,jeu,map);
                positionJoueur.x = 24; //on remet le perso devant la porte du magasin
                positionJoueur.y = 3;
                break;
            }
            if(positionJoueur.x == 10 && positionJoueur.y == 4){
                teleporter(ecran,4,jeu,map);
                positionJoueur.x = 10; //on remet le perso devant la porte de la maison
                positionJoueur.y = 4;
                break;

            }
            if(positionJoueur.x == 2 && positionJoueur.y == 4){
                teleporter(ecran,5,jeu,map);
                positionJoueur.x = 2; //on remet le perso devant la porte de la maison des PNJ
                positionJoueur.y = 5;
                break;

            }
            break;

            case SDLK_UP:
            persoActuel = perso[HAUT];
            deplacerJoueur(&positionJoueur,HAUT,ecran,n,1,jeu,map);
            if(n == 2){
                n = 0;
                teleporter(ecran,2,jeu,map);
                positionJoueur.x = 12;
                positionJoueur.y = 1;
                break;
            }
            break;

            case SDLK_DOWN:
            persoActuel = perso[BAS];
            deplacerJoueur(&positionJoueur,BAS,ecran,n,1,jeu,map);
            break;

            case SDLK_RIGHT:
            persoActuel = perso[DROITE];
            deplacerJoueur(&positionJoueur,DROITE,ecran,n,1,jeu,map);
            break;

            case SDLK_LEFT:
            persoActuel = perso[GAUCHE];
            deplacerJoueur(&positionJoueur,GAUCHE,ecran,n,1,jeu,map);
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
    
    affichageJauge(ecran);
    SDL_Flip(ecran);
    }

    SDL_EnableKeyRepeat(0,0); //desactive la repetition des touche
    
 



    for(i=0;i<4;i++){
        SDL_FreeSurface(perso[i]); //on libère les images du perso en memoire
    }


}





void teleporter(SDL_Surface * ecran,int nb_carte,Jeu & jeu,Map &  map) {

    SDL_Surface *perso[4] =  {NULL};
    SDL_Surface *persoActuel = NULL;
    SDL_Surface *plant = NULL;
    SDL_Surface *plant2= NULL;
    SDL_Surface *inventaire=NULL;


    SDL_Rect positionFond;
    SDL_Surface *fond=NULL;
    



    SDL_Event event;
    bool continuer = 1;
    int i = 0, j=0;
    int posX,posY;

    
    
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

        case 7:
        fond=IMG_Load("./data/interfaceInventaire.png");
        break;

        case 8:
        fond=IMG_Load("./data/interfaceMarcheAchat.png");
        break;

        case 9:
        fond=IMG_Load("./data/interfaceMarcheVente.png");
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

        case 7:
        map.interfaceInventaire[3][12]=PERSO;
        positionJoueur.x= 12;
        positionJoueur.y = 3;

    }

    


    SDL_EnableKeyRepeat(100,100);
    int n;
    bool b; //renvoit true si une graine a été plantée avec succes
    string reponse; //resultat de transformeConstantes(n) -> nom d'un fruitLeg

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
            deplacerJoueur(&positionJoueur,HAUT, ecran,n,nb_carte,jeu,map);
            break;

            case SDLK_DOWN:
            persoActuel = perso[BAS];
            deplacerJoueur(&positionJoueur,BAS, ecran,n,nb_carte,jeu,map);
            if(n == 1){
                n = 0;
                continuer = 0;
            }
            break;

            case SDLK_RIGHT:
            persoActuel = perso[DROITE];
            deplacerJoueur(&positionJoueur,DROITE, ecran,n,nb_carte,jeu,map);
            if(n == 1){
                n = 0;
                continuer = 0;
            }            
            break;

            case SDLK_LEFT:
            persoActuel = perso[GAUCHE];
            deplacerJoueur(&positionJoueur,GAUCHE, ecran,n,nb_carte,jeu,map);
            break;


            case SDLK_RETURN:
            if(nb_carte == 5){
                //le joueur presse ENTRER à proximité du PNJ4
                if (positionJoueur.x==15 && positionJoueur.y==9) {
                    dialoguePNJ(ecran, &positionJoueur, map);
                }
                if (positionJoueur.x==15 && positionJoueur.y==10) {
                    dialoguePNJ(ecran, &positionJoueur, map);
                }
                //le joueur presse ENTRER à proximité du PNJ3
                if (positionJoueur.x==9 && positionJoueur.y==8) {
                    dialoguePNJ(ecran, &positionJoueur, map);
                }
                //le joueur presse ENTRER à proximité du PNJ2
                if (positionJoueur.x==10 && positionJoueur.y==5) {
                    dialoguePNJ(ecran, &positionJoueur, map);
                }
                if (positionJoueur.x==10 && positionJoueur.y==6) {
                    dialoguePNJ(ecran, &positionJoueur, map);
                }
                //le joueur presse ENTRER à proximité du PNJ1
                if (positionJoueur.x==15 && positionJoueur.y==4) {
                    dialoguePNJ(ecran, &positionJoueur, map);
                }
            }
            if(positionJoueur.x == 9 || positionJoueur.x == 11 || positionJoueur.x == 13 || positionJoueur.x == 15){
                if(positionJoueur.y == 8 || positionJoueur.y == 10){
                    teleporter(ecran,8,jeu,map);
                }
            }
            if((positionJoueur.x == 14 || positionJoueur.x == 15 || positionJoueur.x == 16) && positionJoueur.y == 4){
                    teleporter(ecran,9,jeu,map);
                }
            }
            if((positionJoueur.x == 9 || positionJoueur.x == 10) && positionJoueur.y == 3){
                jeu.getPersonnage().inventaire.setEau(1,true);
                jeu.getPersonnage().perteArgent(10);
                cout<<"-10$"<<endl;
                cout <<"Une bouteille d'eau a été ajoutée à votre inventaire"<<endl;

            }
            break;
         
            
            

            case SDL_MOUSEBUTTONUP:        
            switch(event.button.button){
                case SDL_BUTTON_LEFT:                   
                    positionClic.x = event.button.x/34 ;
                    positionClic.y = event.button.y/34 ;
                    if(nb_carte == 2){
                        if(map.carte2[positionClic.y][positionClic.x] == 3 ){
                            posX = positionClic.x;
                            posY = positionClic.y;
                            sdlPlanter(ecran,&positionClic,b,jeu,map);
                            if(b == true)  
                                                          
                                map.carte2[posY][posX] = 4 ;

                        }
                    }
                    if(nb_carte == 4){
                            posX = positionClic.x;
                            posY = positionClic.y;
                            cout<<"posX = "<<posX<<" et posY = "<<posY<<endl;
                         if(positionClic.y == 4 && positionClic.x == 11){
                             teleporter(ecran,7,jeu,map);
                         }
                    }
                    if(nb_carte == 8){
                        posX = positionClic.x;
                        posY = positionClic.y;
                        cout<<"posX = "<<posX<<" et posY = "<<posY<<endl;
                        reponse = transformeConstantes(map.interfaceJardin[positionClic.y][positionClic.x]);
                        if(reponse != ""){
                            jeu.acheter(reponse);                            
                        }

                    }

                    if(nb_carte == 9){
                        posX = positionClic.x;
                        posY = positionClic.y;
                        cout<<"posX = "<<posX<<" et posY = "<<posY<<endl;
                        reponse = transformeConstantes(map.interfaceJardin[positionClic.y][positionClic.x]);
                        if(reponse != ""){
                            jeu.vendre(reponse);                            
                        }

                    }
            
           
                break;

                case SDL_BUTTON_RIGHT:
                positionClic.x = event.button.x / 34;
                    positionClic.y = event.button.y / 34;
                        if(map.carte2[positionClic.y][positionClic.x] == 4 ){
                            jeu.recolter(positionClic.x,positionClic.y);
                            map.carte2[positionClic.y][positionClic.x] = 3 ;
                        }
                break;
        
        
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
    if(nb_carte == 7){
        int k = 0;
        int taille = jeu.getPersonnage().inventaire.inventaireFruitLeg.tabFruitLeg->size();
        while(k < taille){
            for(i=0;i<11;i++){
                for(j=0;j<26;j++){

                    if(k != taille){   
                        if(map.interfaceInventaire[i][j] == 1){
                            string rep;                            
                            position.x=j*TAILLE_BLOC;
                            position.y=i*TAILLE_BLOC;
                            string fruitLeg = jeu.getPersonnage().inventaire.inventaireFruitLeg.tabFruitLeg->at(k).getNomGraine();
                            string type = jeu.getPersonnage().inventaire.inventaireFruitLeg.tabFruitLeg->at(k).getTypeGraine();
                            if(type == "graine"){
                                rep = "./data/fruitLeg/graine/"+fruitLeg+"G.png";
                            }else{
                                rep = "./data/fruitLeg/"+fruitLeg+".png";
                            }
                            inventaire = IMG_Load(rep.c_str());                        
                            SDL_BlitSurface(inventaire,NULL,ecran,&position);
                            k++;
                        
                        }
                        
                    }
                }
            }
        }
    }

    

 
    if(nb_carte != 8 && nb_carte != 9){ 
        position.x = positionJoueur.x*TAILLE_BLOC;
        position.y = positionJoueur.y*TAILLE_BLOC;

        SDL_BlitSurface(persoActuel,NULL,ecran,&position);
    }
    
    
    affichageJauge(ecran);
    SDL_Flip(ecran);

   
    
    
    }

   

    SDL_FreeSurface(plant);
    SDL_FreeSurface(plant2);
 

    SDL_FreeSurface(fond);
    SDL_FreeSurface(inventaire);


    for(i=0;i<4;i++){
        SDL_FreeSurface(perso[i]); //on libère les images du perso en memoire
    }


}

void deplacerJoueur(SDL_Rect *pos,int direction, SDL_Surface *ecran,int &n,int nb_carte,Jeu & jeu,Map & map){

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

        if(nb_carte == 7){
        
            if(map.interfaceInventaire[pos->y-1][pos->x] == MURI) //on verifie que la case en haut n'est pas un mur pour la carte 7
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
            if(map.carte5[pos->y+1][pos->x] == MUR) //on verifie que la case en bas n'est pas un mur pour la carte 5
                break;
        }

        if(nb_carte == 7){
            if(map.interfaceInventaire[pos->y+1][pos->x] == MURI) //on verifie que la case en bas n'est pas un mur pour la carte 7
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

        if(nb_carte == 7){
            if(map.interfaceInventaire[pos->y][pos->x-1] == MURI) //on verifie que la case a gauche n'est pas un mur pour la carte 7
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

        if(nb_carte == 7){
            if(map.interfaceInventaire[pos->y][pos->x+1] == MURI) //on verifie que la case à doroite n'est pas un mur pour la carte 7
                break;
        }
        pos->x++;
        break;


    }

}


void sdlPlanter(SDL_Surface *ecran,const SDL_Rect *pos,bool &succes,Jeu & jeu,Map & map){
    
    SDL_Event event;
    bool continuer = 1;
    succes = false;
    SDL_Rect positionInterface;
    SDL_Surface *interface = NULL;

    interface = IMG_Load("./data/interface_jardin.png");
    //a et b enregistrent la position du clic sur le jardin où a cliqué le joueur
    unsigned int a = pos->x;
    unsigned int b = pos->y;
    string reponse;

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
            }
            break; 


            case SDL_MOUSEBUTTONUP:
            switch(event.button.button){
                case SDL_BUTTON_LEFT:
                positionClic.x = event.button.x / 34;
                positionClic.y = event.button.y / 34;
                reponse = transformeConstantes(map.interfaceJardin[positionClic.y][positionClic.x]);
                succes = jeu.planter(reponse,a,b);  
                continuer = 0;              
                   
                break; 

            }//fin switch 2


        }//fin switch 1  

        SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,255,255,255));
    
        positionInterface.x=0;
        positionInterface.y=0;
        SDL_BlitSurface(interface,NULL,ecran,&positionInterface);  
        
        affichageJauge(ecran);
        SDL_Flip(ecran);
        
    
    
    }//fin while


    SDL_FreeSurface(interface);

}

string transformeConstantes(int n){
    string reponse;
    switch(n){
    case BANANE:                   
    reponse = "banane";                   
    break;

    case COCO:
    reponse = "coco";
    break;                

    case FRAISE:
    reponse = "fraise";
    break;  

    case FRAMBOISE:
    reponse = "framboise";
    break;  
              
    case ORANGE:
    reponse = "orange";
    break;
                    
    case PAMPLEMOUSSE:
    reponse = "pamplemousse";
    break;
                    
    case POIRE:
    reponse = "poire";
    break;
                    
    case POMME:
    reponse = "pomme";
    break;
                    
    case MURE:
    reponse = "mure";
    break;
                    
    case TOMATE:
    reponse = "tomate";
    break;
                    

    case PASTEQUE:
    reponse = "pasteque";
    break;
                    

    case RAISIN:
    reponse = "raisin";
    break;              

    case AUBERGINE:
    reponse = "aubergine";
    break;                

    case BROCOLLI:
    reponse = "brocolli";
    break; 

    case CAROTTE:
    reponse = "carotte";
    break;             

    case CHAMPIGNON:
    reponse = "champignon";
    break; 
                
    case CHOU:
    reponse = "chou";
    break;                

    case FENOUIL:
    reponse = "fenouil";
    break;                  

    case POIVRON:
    reponse = "poivron";
    break;                  
              
    case MAIS:
    reponse = "mais";
    break;  
                    

    case PATATE:
    reponse = "patate";
    break;                

    case SALADE:
    reponse = "salade";
    break;                 

    case RADIS:
    reponse = "radis";
    break;                

    case PIMENT:
    reponse = "piment";
    break;      

    default:
    reponse = "";

    }
    return reponse;
}

void dialoguePNJ(SDL_Surface * ecran, SDL_Rect *pos,Map & map){
    SDL_Surface *dialPNJ1= NULL;
    dialPNJ1 = IMG_Load("./data/dialPNJ1.png");

    int continuer=1;
    SDL_Event event;
    SDL_Rect positionFond;
    positionFond.x=0;
    positionFond.y=50;
    SDL_BlitSurface(dialPNJ1,NULL,ecran,&positionFond);
    
    affichageJauge(ecran);
    SDL_Flip(ecran);
    cout << "DialoguePNJ";
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
                
                case SDLK_o:
                SDL_FreeSurface(dialPNJ1);
                map.carte5[pos->y][pos->x]=0;
                continuer = 0;
                break;
                
                case SDLK_n:
                SDL_FreeSurface(dialPNJ1);
                map.carte5[pos->y][pos->x]=0;
                continuer = 0;
                break;
            }
        }
    }
}

void affichageJauge(SDL_Surface * ecran) {
    SDL_Surface *imFaim= NULL;
    SDL_Surface *imSoif= NULL;
    SDL_Surface *imFatigue= NULL;
    SDL_Surface *imVie= NULL;
    SDL_Surface *jauge= NULL;
    SDL_Surface *niveau= NULL;

    SDL_FreeSurface(imFaim);
    SDL_FreeSurface(imSoif);
    SDL_FreeSurface(imFatigue);
    SDL_FreeSurface(imVie);
    SDL_FreeSurface(jauge);
    SDL_FreeSurface(niveau);
    
    imFaim = IMG_Load("./data/faim.png");
    imSoif = IMG_Load("./data/soif.png");
    imFatigue = IMG_Load("./data/fatigue.png");
    imVie = IMG_Load("./data/vie.png");
    jauge = IMG_Load("./data/jauge.png");
    niveau = IMG_Load("./data/niveau.png");
    SDL_Rect positionJauge;
    positionJauge.x=5;
    positionJauge.y=5;
    SDL_Rect vie;
    vie.x=0;
    vie.y=0;
    vie.h=20;
    vie.w=100; // varie en fonction de la vie du perso
    SDL_Rect faim;
    faim.x=0;
    faim.y=0;
    faim.h=20;
    faim.w=80;// varie en fonction de la faim du perso
    SDL_Rect soif;
    soif.x=0;
    soif.y=0;
    soif.h=20;
    soif.w=50;// varie en fonction de la soif du perso
    SDL_Rect fatigue;
    fatigue.x=0;
    fatigue.y=0;
    fatigue.h=20;
    fatigue.w=20;// varie en fonction de la fatigue du perso
    SDL_Rect xp;
    xp.x=0;
    xp.y=0;
    xp.h=20;
    xp.w=50;

//affichage niveau + xp
    SDL_BlitSurface(niveau, NULL, ecran, &positionJauge);
    positionJauge.x+=20;
    jauge = IMG_Load("./data/jauge0.png");
    SDL_BlitSurface(jauge, NULL, ecran, &positionJauge);
    jauge = IMG_Load("./data/jauge3.png");
    SDL_BlitSurface(jauge, &xp, ecran, &positionJauge);
//affichage vie
    positionJauge.x=0;
    positionJauge.y=300;
    SDL_BlitSurface(imVie,NULL,ecran,&positionJauge);
    positionJauge.x+=20;
    if (vie.w > 70) jauge = IMG_Load("./data/jauge.png");
    if (vie.w <= 70) jauge = IMG_Load("./data/jauge1.png");    
    if (vie.w <= 30) jauge = IMG_Load("./data/jauge2.png");
    SDL_BlitSurface(jauge, &vie, ecran, &positionJauge);
//affichage faim
    positionJauge.x-=20;
    positionJauge.y+=25;
    SDL_BlitSurface(imFaim,NULL,ecran,&positionJauge);
    positionJauge.x+=20;
    if (faim.w > 70) jauge = IMG_Load("./data/jauge.png");
    if (faim.w <= 70) jauge = IMG_Load("./data/jauge1.png");    
    if (faim.w <= 30) jauge = IMG_Load("./data/jauge2.png");
    SDL_BlitSurface(jauge, &faim, ecran, &positionJauge);
//affichage soif
    positionJauge.x-=20;
    positionJauge.y+=25;
    SDL_BlitSurface(imSoif,NULL,ecran,&positionJauge);
    positionJauge.x+=20;   
    if (soif.w > 70) jauge = IMG_Load("./data/jauge.png"); 
    if (soif.w <= 70) jauge = IMG_Load("./data/jauge1.png");    
    if (soif.w <= 30) jauge = IMG_Load("./data/jauge2.png");
    SDL_BlitSurface(jauge, &soif, ecran, &positionJauge);
//affichage faim
    positionJauge.x-=20;
    positionJauge.y+=25;
    SDL_BlitSurface(imFatigue,NULL,ecran,&positionJauge);
    positionJauge.x+=20;   
    if (fatigue.w > 70) jauge = IMG_Load("./data/jauge.png");
    if (fatigue.w <= 70) jauge = IMG_Load("./data/jauge1.png");    
    if (fatigue.w <= 30) jauge = IMG_Load("./data/jauge2.png");
    SDL_BlitSurface(jauge, &fatigue, ecran, &positionJauge);

    

    
}