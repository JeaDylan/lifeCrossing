#include <iostream>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // WIN32
#include "txtJeu.h"
#include "../core/Jeu.h"

void draw_borders(WINDOW * screen) { 
		int x, y, i; 
		getmaxyx(screen, y, x);
		 // 4 corners 
		 mvwprintw(screen, 0, 0, "+"); 
		 mvwprintw(screen, y - 1, 0, "+"); 
		 mvwprintw(screen, 0, x - 1, "+"); 
		 mvwprintw(screen, y - 1, x - 1, "+"); 
		 // sides 
		 for (i = 1; i < (y - 1); i++) { 
			 mvwprintw(screen, i, 0, "|"); 
			 mvwprintw(screen, i, x - 1, "|"); 
			 } // top and bottom 
			 for (i = 1; i < (x - 1); i++) { 
				 mvwprintw(screen, 0, i, "-"); 
				 mvwprintw(screen, y - 1, i, "-"); 
				 } 
	}


void txtAff(WINDOW * winTerrain,WINDOW * winDialogue, Jeu & jeu) {
	
	const EnsembleTerrain& ter = jeu.getConstTerrain();
	const Personnage& perso = jeu.getConstPersonnage();
  	const EnsembleJardin& jardin = jeu.getConstJardin();
	
	int y,x,yDeb,xDeb,yMax,xMax;

	getyx(stdscr,y,x);
	getbegyx(stdscr,yDeb,xDeb);
	getmaxyx(stdscr,yMax,xMax);	

	for(unsigned int i=0;i<ter.tabTerrain[1].getdimX();++i) {
        for(unsigned int j=0;j<ter.tabTerrain[1].getdimY();++j) {
			wmove(winTerrain,j,i);
			waddch(winTerrain,ter.tabTerrain[1].getXY(i,j));
        }
    }
	for(unsigned int k=0; k<3; k++){
		if(jardin.tabJardin->at(k).getOccupe() == true){
			wmove(winTerrain,jardin.tabJardin->at(k).getPosX(),jardin.tabJardin->at(k).getPosY());
			waddch(winTerrain, 'o');
			wgetch(winTerrain);
		}
	}
	wmove(winTerrain,perso.getPosX(),perso.getPosY());
	waddch(winTerrain,'P');
	wgetch(winTerrain);

	box(winDialogue,0,0);
	wrefresh(winTerrain);
	wrefresh(winDialogue);


}




string txtChoixGraine(int choix){
	string rep;
	switch(choix){
		case 48://0
			rep = "banane";
			assert(rep == "banane");
			break;
		case 49: //1
			rep = "coco";
			assert(rep == "coco");
			break;
		case 50: //2
			rep= "fraise";
			assert(rep == "fraise");
			break;
		case 51: //3
			rep= "framboise";
			assert(rep == "framboise");
			break;

	}
	return rep;
}

void txtAffPlant(WINDOW * winDialogue, Jeu & jeu){
	int c;
	string reponse;
	mvwprintw(winDialogue,1,1,"Voulez-vous planter une graine? (y/n) "); 
	c = wgetch(winDialogue); 
	if(c == 'y'){
	mvwprintw(winDialogue,3,1,"Quelle graine voulez-vous planter? (Entrez un nombre)");
	c = wgetch(winDialogue);
	reponse = txtChoixGraine(c);								
	while(1){
		if(jeu.planter(reponse,jeu.getPersonnage().getPosX(),jeu.getPersonnage().getPosY()) == true){
			mvwprintw(winDialogue,5,1,"Bravo! Vous avez planter une graine, recoltez la..");
			wrefresh(winDialogue);
			werase(winDialogue);
			break;
		}
		else{ printw(".");}	
	}
	}	
	else{ 
		mvwprintw(winDialogue,3,1," Dommage :( ");
		werase(winDialogue);
	}	

}

void txtBoucle (Jeu & jeu) {
	// Creation d'une nouvelle fenetre en mode texte
	// => fenetre de dimension et position (WIDTH,HEIGHT,STARTX,STARTY)
	WINDOW * winTerrain = newwin(jeu.getConstTerrain().tabTerrain[1].getdimX(),jeu.getConstTerrain().tabTerrain[1].getdimY(),0,0);
	WINDOW * winDialogue = newwin(20,70,jeu.getConstTerrain().tabTerrain[1].getdimX(),0);
	int winDiaDebx,winDiaDeby;
	getbegyx(winDialogue,winDiaDebx,winDiaDeby);

	bool ok = true;
	int c,d;
	string reponse;
	

	keypad(winTerrain,true);
	noecho();
	cbreak();


	do {
	    txtAff(winTerrain,winDialogue,jeu);

        #ifdef _WIN32
        Sleep(100);
		#else
		usleep(100000);
        #endif // WIN32

		//jeu.actionsAutomatiques();	
		timeout(500);
		c = wgetch(winTerrain);
		switch (c) {
			case 'k':
				jeu.actionClavier('g');
				break;
			case 'm':
				jeu.actionClavier('d');
				break;
			case 'l':
				jeu.actionClavier('h');
				break;
			case 'o':
				jeu.actionClavier('b');
				break;
			case 'p':	
				txtAffPlant(winDialogue,jeu);
				break;
			case 'q':
				ok = false;
				break;
		}
	} while (ok);

}

