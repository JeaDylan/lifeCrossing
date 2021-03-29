#include <iostream>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // WIN32
#include "winTxt.h"
#include <ncurses.h>

#include "../core/Jeu.h"

void txtAff(WINDOW * win, Jeu & jeu) {
	const EnsembleTerrain& ter = jeu.getConstTerrain();
	const Personnage& perso = jeu.getConstPersonnage();
  	const EnsembleJardin& jardin = jeu.getConstJardin();

	// Avec winTxt.h
	/*win.clear();

    // Affichage quartier
	for(unsigned int i=0;i<ter.tabTerrain[1].getdimX();++i) {
        for(unsigned int j=0;j<ter.tabTerrain[1].getdimY();++j) {
            win.print(i,j,ter.tabTerrain[1].getXY(i,j));
        }
    }
    
    //Affichage du Personnage
    win.print(perso.getPosX(),perso.getPosY(),'P');


	win.draw();*/

	// Avec ncurces.h
	curs_set(0);
	noecho();
	int y,x,yDeb,xDeb,yMax,xMax;

	getyx(stdscr,y,x);
	getbegyx(stdscr,yDeb,xDeb);
	getmaxyx(stdscr,yMax,xMax);

	for(unsigned int i=0;i<ter.tabTerrain[1].getdimX();++i) {
        for(unsigned int j=0;j<ter.tabTerrain[1].getdimY();++j) {
			wmove(win,j,i);
			waddch(win,ter.tabTerrain[1].getXY(i,j));
        }
    }
	wmove(win,perso.getPosX(),perso.getPosY());
	waddch(win,'P');
	wgetch(win);
}

void txtBoucle (Jeu & jeu) {
	// Creation d'une nouvelle fenetre en mode texte
	// => fenetre de dimension et position (WIDTH,HEIGHT,STARTX,STARTY)
	WINDOW * win = newwin(jeu.getConstTerrain().tabTerrain[1].getdimX(),jeu.getConstTerrain().tabTerrain[1].getdimY(),0,0);

	bool ok = true;
	int c;

	do {
	    txtAff(win,jeu);

        #ifdef _WIN32
        Sleep(100);
		#else
		usleep(100000);
        #endif // WIN32

		//jeu.actionsAutomatiques();	
		nodelay(win,true);
		c = wgetch(win);
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
                jeu.actionClavier('p');
			case 'q':
				ok = false;
				break;
		}

	} while (ok);

}
