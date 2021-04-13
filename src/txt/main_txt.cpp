#include "winTxt.h"
#include "txtJeu.h"
#include <ncurses.h>
#include <iostream>

using namespace std;

int main ( int argc, char** argv ) {
	initscr();
	cbreak();
	Jeu jeu;
	string nom;	
	cout<< "Bonjour, veuillez entrer votre nom : "<<endl;
	cin>>nom;
	jeu.getPersonnage().setNom(nom);
	txtBoucle(jeu);	
    termClear();
	endwin();
	return 0;
}
