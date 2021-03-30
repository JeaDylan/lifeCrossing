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
	wmove(winTerrain,perso.getPosX(),perso.getPosY());
	waddch(winTerrain,'P');
	wgetch(winTerrain);

	box(winDialogue,0,0);
	wrefresh(winTerrain);
}

void txtBoucle (Jeu & jeu) {
	// Creation d'une nouvelle fenetre en mode texte
	// => fenetre de dimension et position (WIDTH,HEIGHT,STARTX,STARTY)
	WINDOW * winTerrain = newwin(jeu.getConstTerrain().tabTerrain[1].getdimX(),jeu.getConstTerrain().tabTerrain[1].getdimY(),0,0);
	WINDOW * winDialogue = newwin(10,70,jeu.getConstTerrain().tabTerrain[1].getdimX(),0);
	int winDiaDebx,winDiaDeby;
	getbegyx(winDialogue,winDiaDebx,winDiaDeby);

	bool ok = true;
	int c,d;

	keypad(winTerrain,true);
	noecho();


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
				mvwprintw(winDialogue,1,1,"Voulez-vous planter une graine? (oui/non) ");
				wrefresh(winDialogue);
                jeu.actionClavier('p');
				break;
			case 'q':
				ok = false;
				break;
		}
	} while (ok);

}

