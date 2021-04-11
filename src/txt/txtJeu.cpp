#include <iostream>
#include "txtJeu.h"
#include "../core/Jeu.h"


void txtAff(WINDOW * winTerrain,WINDOW * winDialogue, WINDOW * winCommandes, Jeu & jeu) {
	
	const EnsembleTerrain& ter = jeu.getConstTerrain();
	const Personnage& perso = jeu.getConstPersonnage();
  	const EnsembleJardin& jardin = jeu.getConstJardin();
	const EnsemblePnj& pnjs = jeu.getConstPnjs();	

	for(unsigned int i=0;i<ter.tabTerrain[1].getdimX();++i) {
        for(unsigned int j=0;j<ter.tabTerrain[1].getdimY();++j) {
			wmove(winTerrain,j,i);
			waddch(winTerrain,ter.tabTerrain[1].getXY(i,j));
        }
    }
	for(unsigned int k=0; k<4; k++){
		if(jardin.tabJardin->at(k).getOccupe() == true){
			wmove(winTerrain,jardin.tabJardin->at(k).getPosX()
				,jardin.tabJardin->at(k).getPosY());
			waddch(winTerrain, 'o');
		}
	}

	wmove(winTerrain,perso.getPosX(),perso.getPosY());
	waddch(winTerrain,'P');

	box(winDialogue,0,0);
	wrefresh(winTerrain);

	box(winCommandes,0,0);
	mvwprintw(winCommandes,1,1,"Bienvenue sur Life Crossing 1.0 ! ");
	mvwprintw(winCommandes,3,1, "Voici les modalités du jeu : ");
	mvwprintw(winCommandes,4,1,"Touches : 'k' gauche 'm' droite 'o' haut 'l' bas");
	mvwprintw(winCommandes,5,1,"     'q' quitter 'j' planter 'p' infos personnage ");
	mvwprintw(winCommandes,6,1,"Description : 'x' obstacles 'j' jardin ");
	mvwprintw(winCommandes,7,1,"     'i' personnage 'a' Activitee 'c' Commerce ");
	wrefresh(winCommandes);
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
		if(jeu.planter(reponse,jeu.getPersonnage().getPosX()
			,jeu.getPersonnage().getPosY()) == true) {
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

	int c,prixCine;
	string nomPnj,nomPerso;
	Personnage perso;
	EnsemblePnj pnjs;
	perso = jeu.getPersonnage();
	pnjs = jeu.getPnjs();

	if(perso.getPosX()==pnjs.tabPnj[0].getPosition().x 
		&&perso.getPosY()==pnjs.tabPnj[0].getPosition().y) {
			
			nomPnj = jeu.getPnjs().tabPnj[0].getNom();
			nomPerso = jeu.getPersonnage().getNom();
			prixCine = jeu.getActivites().tabActivite[0].getPrix();

			string ligne1 = "Bonjour " + nomPerso 
			+ ", je suis " + nomPnj + " !";
			const char * ligne1m = (const char *) ligne1.c_str();

			string ligne2 = "Cette activitée coûte " + to_string(prixCine)
							+ "$.";
			const char * ligne2m = (const char *) ligne2.c_str();

			mvwprintw(winDialogue,1,1,ligne1m);
			mvwprintw(winDialogue,2,1,"Tu te trouves devant le cinema.");
			mvwprintw(winDialogue,3,1,"Regarde un film et remporte des xp.");
			mvwprintw(winDialogue,4,1,"Pour ce faire il te suffit de te placer sur a et appuyer sur a.");
			mvwprintw(winDialogue,5,1,ligne2m);
	}

	c=wgetch(winDialogue);
	werase(winDialogue);	
}

void txtAffPerso(WINDOW * winDialogue, Jeu & jeu) {
	int c;
	
	string ligne1 = jeu.getConstPersonnage().getNom() + " :";
	const char * ligne1m = (const char *) ligne1.c_str();
	
	string ligne2 = "- Argent : " + to_string(jeu.getConstPersonnage()
					.getArgent());
	const char * ligne2m = (const char *) ligne2.c_str();

	string ligne2_1 = "- Niveau : " + jeu.getConstPersonnage()
						.niveau.afficheJeuTxt();
	const char * ligne2_1m = (const char *) ligne2_1.c_str();

	string ligne2_2 = "- XP : " + jeu.getConstPersonnage()
					.xp.afficheJeuTxt();
	const char * ligne2_2m = (const char *) ligne2_2.c_str();

	string ligne3 = "- Stock Fruit/Legume : " + jeu.getConstPersonnage().
					inventaire.getFruitLeg().afficheJeuTxt();
	const char * ligne3m = (const char *) ligne3.c_str();

	string ligne4 = "- Stock Eau : " + jeu.getConstPersonnage().
					inventaire.getEau().afficheJeuTxt();
	const char * ligne4m = (const char *) ligne4.c_str();

	string ligne5 = "- Stock Nourriture : " + jeu.getConstPersonnage().
					inventaire.getManger().afficheJeuTxt();
	const char * ligne5m = (const char *) ligne5.c_str();

	string ligne6 = "Points vie : " + jeu.getPersonnage()
					.vie.getPtsDeVie().afficheJeuTxt();
	const char * ligne6m = (const char *) ligne6.c_str();

	string ligne7 = "Faim : " + jeu.getPersonnage()
					.vie.getFaim().afficheJeuTxt();
	const char * ligne7m = (const char *) ligne7.c_str();

	string ligne8 = "Soif : " + jeu.getPersonnage()
					.vie.getSoif().afficheJeuTxt();
	const char * ligne8m = (const char *) ligne8.c_str();

	string ligne9 = "Fatigue : " + jeu.getPersonnage()
					.vie.getFatigue().afficheJeuTxt();
	const char * ligne9m = (const char *) ligne9.c_str();
	

	mvwprintw(winDialogue,1,1,ligne1m);
	mvwprintw(winDialogue,2,1,ligne2m);
	mvwprintw(winDialogue,3,1,ligne2_1m);
	mvwprintw(winDialogue,4,1,ligne2_2m);
	mvwprintw(winDialogue,5,1,"Inventaire : ");
	mvwprintw(winDialogue,6,1,ligne3m);
	mvwprintw(winDialogue,7,1,ligne4m);
	mvwprintw(winDialogue,8,1,ligne5m);
	mvwprintw(winDialogue,5,35,"Vie : ");
	mvwprintw(winDialogue,6,35,ligne6m);
	mvwprintw(winDialogue,7,35,ligne7m);
	mvwprintw(winDialogue,8,35,ligne8m);
	mvwprintw(winDialogue,9,35,ligne9m);

	c=wgetch(winDialogue);
	werase(winDialogue);

}

void txtAffActivite(WINDOW * winDialogue, Jeu & jeu) {

	int c;
	Personnage perso;
	EnsembleActivite activites;
	perso = jeu.getConstPersonnage();
	activites = jeu.getConstActivites();
	
	string ligne1 = "Vous venez de regarder un film ! ";
	const char * ligne1m = (const char *) ligne1.c_str();

	string ligne2 =	activites.tabActivite[0].affichejeuTxt();
	const char * ligne2m = (const char *) ligne2.c_str();

	if (perso.getPosX()==activites.tabActivite[0].getPosition().x
		&& perso.getPosY()==activites.tabActivite[0].getPosition().y) {
			int nouvXp;
			nouvXp = perso.xp.getNiveau() + 
			activites.tabActivite[0].getRecompense();
			mvwprintw(winDialogue,1,1,ligne1m);
			mvwprintw(winDialogue,2,1,ligne2m);
			jeu.getPersonnage().
			perteArgent(activites.tabActivite[0].getPrix());
			jeu.getPersonnage().xp.setNiveau(nouvXp);
		}

	c=wgetch(winDialogue);
	werase(winDialogue);	
}

void txtAffMarche(WINDOW * winDialogue, Jeu & jeu) {
	int c;
	Personnage perso;
	perso = jeu.getConstPersonnage();
	if(perso.getPosX()==15,perso.getPosY()==4) {
		const char * affm;
		string affs;
		mvwprintw(winDialogue,1,1,"Commerce :");
		mvwprintw(winDialogue,2,1,"Fruits Legumes - 20$");
		/*for (int i=0; i<jeu.getConstFruitLeg().tabFruitLeg->size();i++ ) {
			affs = jeu.getConstFruitLeg().tabFruitLeg->at(i).affichejeuTxt();
			aff.push_back(affs);
			affm = (const char *) aff[i].c_str();
			mvwprintw(winDialogue,i+3,1,affm);
		}*/
		mvwprintw(winDialogue,2,25,"Eau - 5$");
		mvwprintw(winDialogue,3,25,"Nourriture - 10$");
	}
	c=wgetch(winDialogue);
	werase(winDialogue);
}


void txtBoucle (Jeu & jeu) {

	Terrain ter = jeu.getConstTerrain().tabTerrain[1];

	WINDOW * winTerrain = newwin(ter.getdimX(),ter.getdimY(),0,0);
	WINDOW * winDialogue = newwin(15,70,ter.getdimX(),0);
	WINDOW * winCommandes = newwin(ter.getdimX(),50,0,ter.getdimY());

	bool ok = true;
	int c,d;
	string reponse;

	noecho();

	do {
	    txtAff(winTerrain,winDialogue,winCommandes,jeu);

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
			case 'c':
				txtAffMarche(winDialogue,jeu);
				break;
			case 'q':
				ok = false;
				break;
		}
	} while (ok);
	wclear(winDialogue);
	wclear(winTerrain);
	wclear(winCommandes);
	delwin(winDialogue);
	delwin(winTerrain);
	delwin(winCommandes);
}

