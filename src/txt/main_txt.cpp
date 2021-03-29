#include "winTxt.h"
#include "txtJeu.h"
#include <ncurses.h>


int main ( int argc, char** argv ) {
    
	initscr();
	Jeu jeu;
	txtBoucle(jeu);
    termClear();
	endwin();
	return 0;
}
