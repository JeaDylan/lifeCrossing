#include <iostream>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // WIN32
#include "txtJeu.h"
#include "../core/Jeu.h"


void txtAff(WINDOW * winTerrain,WINDOW * winDialogue, WINDOW * winCommandes, Jeu & jeu) {
	
	const EnsembleTerrain& ter = jeu.getConstTerrain();
	const Personnage& perso = jeu.getConstPersonnage();
  	const EnsembleJardin& jardin = jeu.getConstJardin();
	const EnsemblePnj& pnjs = jeu.getConstPnjs();
	
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
	for(unsigned int k=0; k<4; k++){
		if(jardin.tabJardin->at(k).getOccupe() == true){
			wmove(winTerrain,jardin.tabJardin->at(k).getPosX(),jardin.tabJardin->at(k).getPosY());
			waddch(winTerrain, 'o');
			wgetch(winTerrain);
		}
	}

	wmove(winTerrain,perso.getPosX(),perso.getPosY());
	waddch(winTerrain,'P');

	box(winDialogue,0,0);
	wrefresh(winTerrain);
	wrefresh(winDialogue);

	box(winCommandes,0,0);
	mvwprintw(winCommandes,1,1,"Bienvenue sur Life Crossing 1.0 ! ");
	mvwprintw(winCommandes,3,1, "Voici les modalités du jeu : ");
	mvwprintw(winCommandes,4,1,"Touches : 'k' gauche 'm' droite 'o' haut 'l' bas");
	mvwprintw(winCommandes,5,1,"     'q' quitter 'j' planter 'p' infos personnage ");
	mvwprintw(winCommandes,6,1,"Description : 'x' obstacles 'j' jardin ");
	mvwprintw(winCommandes,7,1,"     'i' personnage 'a' Activitee ");
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

void txtAffPnj(WINDOW * winDialogue, Jeu & jeu) {
	int c;
	string nom;
	if(jeu.getPersonnage().getPosX()==jeu.getPnjs().tabPnj[0].getPosition().x 
		&& jeu.getPersonnage().getPosY()==jeu.getPnjs().tabPnj[0].getPosition().y) {
			nom = jeu.getPnjs().tabPnj[0].getNom();
			string ligne1 = "Bonjour je suis " + nom + " !";
			const char * ligne1m = (const char *)ligne1.c_str();
			mvwprintw(winDialogue,1,1,ligne1m);
			mvwprintw(winDialogue,2,1,"Tu te trouves devant le cinema.");
			mvwprintw(winDialogue,3,1,"Regarde un film et remporte des xp.");
			mvwprintw(winDialogue,4,1,"Pour ce faire il te suffit de te placer sur a et appuyer sur a.");
	}
	c=wgetch(winDialogue);
	if (c!='i') {
		werase(winDialogue);
	}
}

void txtAffPerso(WINDOW * winDialogue, Jeu & jeu) {
	int c;
	string ligne1 = jeu.getConstPersonnage().getNom() + " :";
	const char * ligne1m = (const char *)ligne1.c_str();
	string ligne2 = "- Argent : " + to_string(jeu.getConstPersonnage().getArgent());
	const char * ligne2m = (const char *)ligne2.c_str();
	//string ligne3 = "- Stock Fruit/Legume : " + jeu.getConstPersonnage().getInventaire().getFruitLeg().;

	mvwprintw(winDialogue,1,1,ligne1m);
	mvwprintw(winDialogue,2,1,ligne2m);
	mvwprintw(winDialogue,4,1,"Inventaire : ");
	//mvwprintw(winDialogue,5,1,);

	c=wgetch(winDialogue);
	if (c!='p') {
		werase(winDialogue);
	}
}

void txtAffActivite(WINDOW * winDialogue, Jeu & jeu) {
	int c;
	string ligne1 = "Bienvenue à l'activite " + jeu.getConstActivites().tabActivite[0].getNom() + " !";
	const char * ligne1m = (const char *)ligne1.c_str();
	if (jeu.getPersonnage().getPosX()==jeu.getActivites().tabActivite[0].getPosition().x
		&& jeu.getPersonnage().getPosY()==jeu.getActivites().tabActivite[0].getPosition().y) {
			mvwprintw(winDialogue,1,1,ligne1m);
			jeu.getPersonnage().perteArgent(jeu.getActivites().tabActivite[0].getPrix());
		}
	c=wgetch(winDialogue);
	if (c!='a') {
		werase(winDialogue);
	}
	
}

void txtBoucle (Jeu & jeu) {

	WINDOW * winTerrain = newwin(jeu.getConstTerrain().tabTerrain[1].getdimX(),jeu.getConstTerrain().tabTerrain[1].getdimY(),0,0);
	WINDOW * winDialogue = newwin(15,70,jeu.getConstTerrain().tabTerrain[1].getdimX(),0);
	WINDOW * winCommandes = newwin(jeu.getConstTerrain().tabTerrain[1].getdimX(),50,0,jeu.getConstTerrain().tabTerrain[1].getdimY());

	int winDiaDebx,winDiaDeby;
	getbegyx(winDialogue,winDiaDebx,winDiaDeby);

	bool ok = true;
	int c,d;
	string reponse;

	keypad(winTerrain,true);
	noecho();
	cbreak();


	do {
	    txtAff(winTerrain,winDialogue,winCommandes,jeu);
		wrefresh(winCommandes);

        #ifdef _WIN32
        Sleep(100);
		#else
		usleep(100000);
        #endif // WIN32

		//jeu.actionsAutomatiques();	
		timeout(500);
		c = wgetch(winDialogue);
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
			case 'j':	
				txtAffPlant(winDialogue,jeu);
				break;
			case 'i':
				txtAffPnj(winDialogue,jeu);
				break;
			case 'p':
				txtAffPerso(winDialogue,jeu);
				break;
			case 'a':
				txtAffActivite(winDialogue,jeu);
				break;
			case 'q':
				ok = false;
				break;
		}
	} while (ok);

}

