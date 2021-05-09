#include <iostream>
#include <chrono>
#include <future>
#include "txtJeu.h"
#include "../core/Jeu.h"


void txtAff(WINDOW * winTerrain,WINDOW * winDialogue, WINDOW * winCommandes, Jeu & jeu) {
	
	EnsembleTerrain& ter = jeu.getTerrain();
	const Personnage& perso = jeu.getConstPersonnage();
  	const EnsembleJardin& jardin = jeu.getConstJardin();

	for(unsigned int i=0;i<ter.terrCourant.getdimX();++i) {
        for(unsigned int j=0;j<ter.terrCourant.getdimY();++j) {
			wmove(winTerrain,j,i);
			waddch(winTerrain,ter.terrCourant.getXY(i,j));
        }
    }
	/*for(unsigned int k=0; k<4; k++){
		if(jardin.tabJardin->at(k).getOccupe() == true){
			wmove(winTerrain,jardin.tabJardin->at(k).getPosX()
				,jardin.tabJardin->at(k).getPosY());
			waddch(winTerrain, 'o');
		}
	}*/

	wmove(winTerrain,perso.getPosX(),perso.getPosY());
	waddch(winTerrain,'P');

	box(winDialogue,0,0);
	wrefresh(winTerrain);

	string affTer = "Terrain : " + jeu.getTerrain().terrCourant.getNom();
	const char * affTerm = (const char *) affTer.c_str();
	wclear(winCommandes);
	box(winCommandes,0,0);
	mvwprintw(winCommandes,1,1,"Bienvenue sur Life Crossing 1.0 ! ");
	mvwprintw(winCommandes,2,1,affTerm);
	mvwprintw(winCommandes,3,1, "Voici les modalités du jeu : ");
	mvwprintw(winCommandes,4,1,"Touches : 'k' gauche 'm' droite 'o' haut 'l' bas");
	mvwprintw(winCommandes,5,1,"     'q' quitter 'p' infos personnage ");
	mvwprintw(winCommandes,6,1,"Description : 'x' obstacles 'j' jardin 'e' entrer ");
	mvwprintw(winCommandes,7,1,"     'i' personnage 'a' Activitee 'c' Commerce");
	mvwprintw(winCommandes,8,1,"     'n' table à manger 'd' dormir 'b' boire ");
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
	Personnage perso;
	perso = jeu.getPersonnage();
	if(jeu.posJardinValide()){
		mvwprintw(winDialogue,1,1,"Voulez-vous planter une graine? (y/n) "); 
		c =	wgetch(winDialogue); 
		if(c == 'y'){
			mvwprintw(winDialogue,3,1,"Quelle graine voulez-vous planter? (Entrez un nombre)");
			wgetch(winDialogue);
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
}

void txtAffPnj(WINDOW * winDialogue, Jeu & jeu) {

	int prix;
	string nomPnj,nomPerso = jeu.getPersonnage().getNom();
	Personnage& perso = jeu.getPersonnage();
	EnsemblePnj& pnjs = jeu.getPnjs();

	if(perso.getPosX()==pnjs.tabPnj[0].getPosition().x 
		&&perso.getPosY()==pnjs.tabPnj[0].getPosition().y) {
			
			nomPnj = jeu.getPnjs().tabPnj[0].getNom();
			prix = jeu.getActivites().tabActivite[0].getPrix();

			string ligne1 = "Bonjour " + nomPerso 
			+ ", je suis " + nomPnj + " !";
			const char * ligne1m = (const char *) ligne1.c_str();

			string ligne2 = "Cette activitée coûte " + to_string(prix)
							+ "$.";
			const char * ligne2m = (const char *) ligne2.c_str();

			mvwprintw(winDialogue,1,1,ligne1m);
			mvwprintw(winDialogue,2,1,"Tu te trouves devant le cinema.");
			mvwprintw(winDialogue,3,1,"Regarde un film et remporte des xp.");
			mvwprintw(winDialogue,4,1,"Pour ce faire il te suffit de te placer sur a et appuyer sur a.");
			mvwprintw(winDialogue,5,1,ligne2m);
	}

	if(perso.getPosX()==pnjs.tabPnj[1].getPosition().x 
		&&perso.getPosY()==pnjs.tabPnj[1].getPosition().y) {
			
			nomPnj = jeu.getPnjs().tabPnj[1].getNom();

			string ligne1 = "Bonjour " + nomPerso 
			+ ", je suis " + nomPnj + " !";
			const char * ligne1m = (const char *) ligne1.c_str();

			mvwprintw(winDialogue,1,1,ligne1m);
			mvwprintw(winDialogue,2,1,"Tu te trouves devant le Commerce de la ville.");
			mvwprintw(winDialogue,3,1,"Mission : si tu remplie ton stock de nourriture,");
			mvwprintw(winDialogue,4,1," tu gagnes 200xp.");
	}

	wgetch(winDialogue);
	werase(winDialogue);	
}

void txtAffPerso(WINDOW * winDialogue, Jeu & jeu) {
	
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

	wgetch(winDialogue);
	werase(winDialogue);

}

void txtAffActivite(WINDOW * winDialogue, Jeu & jeu) {

	Personnage& perso = jeu.getPersonnage();;
	EnsembleActivite& activites = jeu.getActivites();
	
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

	wgetch(winDialogue);
	werase(winDialogue);	
}

void txtAffMarche(WINDOW * winDialogue, Jeu & jeu) {

	Personnage& perso = jeu.getPersonnage();
	string dialogue;
	const char * dialoguem;
	int c;
	if(perso.getPosX()==15&&perso.getPosY()==4) {
		mvwprintw(winDialogue,1,1,"Commerce :");
		mvwprintw(winDialogue,2,1,"Fruits Legumes :");
		for (unsigned int i=0; i<10;i++ ) {
			mvwprintw(winDialogue,i+3,1,(const char *)jeu.getConstFruitLeg()
					.tabFruitLeg->at(i).affichejeuTxt(i).c_str());
		}
		mvwprintw(winDialogue,2,25,"(e) Eau - 2$");
		mvwprintw(winDialogue,3,25,"(n) Nourriture - 5$");

		c = wgetch(winDialogue);
		switch (c)
		{
		case 'e':
			if(perso.inventaire.getEau().jaugeRemplie()==false) {
				perso.perteArgent(2);
				perso.inventaire.setEau(5,true);
				werase(winDialogue);
				box(winDialogue,0,0);
				mvwprintw(winDialogue,1,1,"Vous avez achetez de l'eau !");
			}
			break;
		
		case 'n':
			if(perso.inventaire.getManger().jaugeRemplie()==false) {
				jeu.getPersonnage().perteArgent(5);
				jeu.getPersonnage().inventaire.setManger(5,true);
				werase(winDialogue);
				box(winDialogue,0,0);
				mvwprintw(winDialogue,1,1,"Vous avez achetez à manger !");
			}
			break;

		case '0':
			if(perso.inventaire.getFruitLeg().jaugeRemplie()==false) {
				jeu.getPersonnage().perteArgent(jeu.getConstFruitLeg()
				.tabFruitLeg->at(0).getPrixGraine());
				jeu.getPersonnage().inventaire.setFruitLeg(4,true);
				dialogue = "Vous avez acheté un(e) " + jeu.getConstFruitLeg()
				.tabFruitLeg->at(0).getNomGraine() + " ! ";
				dialoguem = (const char *) dialogue.c_str();
				werase(winDialogue);
				box(winDialogue,0,0);
				mvwprintw(winDialogue,1,1,dialoguem);
			}
			break;
		case '1':
			if(perso.inventaire.getFruitLeg().jaugeRemplie()==false) {
				jeu.getPersonnage().perteArgent(jeu.getConstFruitLeg()
				.tabFruitLeg->at(1).getPrixGraine());
				jeu.getPersonnage().inventaire.setFruitLeg(10,true);
				dialogue = "Vous avez acheté un(e) " + jeu.getConstFruitLeg()
				.tabFruitLeg->at(1).getNomGraine() + " ! ";
				dialoguem = (const char *) dialogue.c_str();
				werase(winDialogue);
				box(winDialogue,0,0);
				mvwprintw(winDialogue,1,1,dialoguem);
			}
			break;
		case '2':
			if(perso.inventaire.getFruitLeg().jaugeRemplie()==false) {
				jeu.getPersonnage().perteArgent(jeu.getConstFruitLeg()
				.tabFruitLeg->at(2).getPrixGraine());
				jeu.getPersonnage().inventaire.setFruitLeg(1,true);
				dialogue = "Vous avez acheté un(e) " + jeu.getConstFruitLeg()
				.tabFruitLeg->at(2).getNomGraine() + " ! ";
				dialoguem = (const char *) dialogue.c_str();
				werase(winDialogue);
				box(winDialogue,0,0);
				mvwprintw(winDialogue,1,1,dialoguem);
			}
			break;
		case '3':
			if(perso.inventaire.getFruitLeg().jaugeRemplie()==false) {
				jeu.getPersonnage().perteArgent(jeu.getConstFruitLeg()
				.tabFruitLeg->at(3).getPrixGraine());
				jeu.getPersonnage().inventaire.setFruitLeg(1,true);
				dialogue = "Vous avez acheté un(e) " + jeu.getConstFruitLeg()
				.tabFruitLeg->at(3).getNomGraine() + " ! ";
				dialoguem = (const char *) dialogue.c_str();
				werase(winDialogue);
				box(winDialogue,0,0);
				mvwprintw(winDialogue,1,1,dialoguem);
			}
			break;
		case '4':
			if(perso.inventaire.getFruitLeg().jaugeRemplie()==false) {
				jeu.getPersonnage().perteArgent(jeu.getConstFruitLeg()
				.tabFruitLeg->at(4).getPrixGraine());
				jeu.getPersonnage().inventaire.setFruitLeg(2,true);
				dialogue = "Vous avez acheté un(e) " + jeu.getConstFruitLeg()
				.tabFruitLeg->at(4).getNomGraine() + " ! ";
				dialoguem = (const char *) dialogue.c_str();
				werase(winDialogue);
				box(winDialogue,0,0);
				mvwprintw(winDialogue,1,1,dialoguem);
			}
			break;
		case '5':
			if(perso.inventaire.getFruitLeg().jaugeRemplie()==false) {
				jeu.getPersonnage().perteArgent(jeu.getConstFruitLeg()
				.tabFruitLeg->at(5).getPrixGraine());
				jeu.getPersonnage().inventaire.setFruitLeg(3,true);
				dialogue = "Vous avez acheté un(e) " + jeu.getConstFruitLeg()
				.tabFruitLeg->at(5).getNomGraine() + " ! ";
				dialoguem = (const char *) dialogue.c_str();
				werase(winDialogue);
				box(winDialogue,0,0);
				mvwprintw(winDialogue,1,1,dialoguem);
			}
			break;
		case '6':
			if(perso.inventaire.getFruitLeg().jaugeRemplie()==false) {
				jeu.getPersonnage().perteArgent(jeu.getConstFruitLeg()
				.tabFruitLeg->at(6).getPrixGraine());
				jeu.getPersonnage().inventaire.setFruitLeg(2,true);
				dialogue = "Vous avez acheté un(e) " + jeu.getConstFruitLeg()
				.tabFruitLeg->at(6).getNomGraine() + " ! ";
				dialoguem = (const char *) dialogue.c_str();
				werase(winDialogue);
				box(winDialogue,0,0);
				mvwprintw(winDialogue,1,1,dialoguem);
			}
			break;
		case '7':
			if(perso.inventaire.getFruitLeg().jaugeRemplie()==false) {
				jeu.getPersonnage().perteArgent(jeu.getConstFruitLeg()
				.tabFruitLeg->at(7).getPrixGraine());
				jeu.getPersonnage().inventaire.setFruitLeg(2,true);
				dialogue = "Vous avez acheté un(e) " + jeu.getConstFruitLeg()
				.tabFruitLeg->at(7).getNomGraine() + " ! ";
				dialoguem = (const char *) dialogue.c_str();
				werase(winDialogue);
				box(winDialogue,0,0);
				mvwprintw(winDialogue,1,1,dialoguem);
			}
			break;
		case '8':
			if(perso.inventaire.getFruitLeg().jaugeRemplie()==false) {
				jeu.getPersonnage().perteArgent(jeu.getConstFruitLeg()
				.tabFruitLeg->at(8).getPrixGraine());
				jeu.getPersonnage().inventaire.setFruitLeg(9,true);
				dialogue = "Vous avez acheté un(e) " + jeu.getConstFruitLeg()
				.tabFruitLeg->at(8).getNomGraine() + " ! ";
				dialoguem = (const char *) dialogue.c_str();
				werase(winDialogue);
				box(winDialogue,0,0);
				mvwprintw(winDialogue,1,1,dialoguem);
			}
			break;
		case '9':
			if(perso.inventaire.getFruitLeg().jaugeRemplie()==false) {
				jeu.getPersonnage().perteArgent(jeu.getConstFruitLeg()
				.tabFruitLeg->at(9).getPrixGraine());
				jeu.getPersonnage().inventaire.setFruitLeg(5,true);
				dialogue = "Vous avez acheté un(e) " + jeu.getConstFruitLeg()
				.tabFruitLeg->at(9).getNomGraine() + " ! ";
				dialoguem = (const char *) dialogue.c_str();
				werase(winDialogue);
				box(winDialogue,0,0);
				mvwprintw(winDialogue,1,1,dialoguem);
			}
			break;
		default:
			break;
		}
	}
	
	wgetch(winDialogue);
	werase(winDialogue);
}

void changeTerrain(Jeu & jeu) {
	// Quartier vers Maison
	if(jeu.getPersonnage().getPosX()==jeu.getTerrain().tabTerrain[1].getPortails().tabPortail[0].position.x&&
	jeu.getPersonnage().getPosY()==jeu.getTerrain().tabTerrain[1].getPortails().tabPortail[0].position.y) {
		jeu.getTerrain().terrCourant=jeu.getTerrain().tabTerrain[0];
		jeu.getPersonnage().setPosX(jeu.getTerrain().tabTerrain[0].getPortails().tabPortail[0].position.x+1);
		jeu.getPersonnage().setPosY(jeu.getTerrain().tabTerrain[0].getPortails().tabPortail[0].position.y);
	}
	// Maison vers Quartier
	if(jeu.getPersonnage().getPosX()==jeu.getTerrain().tabTerrain[0].getPortails().tabPortail[0].position.x&&
	jeu.getPersonnage().getPosY()==jeu.getTerrain().tabTerrain[0].getPortails().tabPortail[0].position.y) {
		jeu.getTerrain().terrCourant=jeu.getTerrain().tabTerrain[1];
		jeu.getPersonnage().setPosX(jeu.getTerrain().tabTerrain[1].getPortails().tabPortail[0].position.x);
		jeu.getPersonnage().setPosY(jeu.getTerrain().tabTerrain[1].getPortails().tabPortail[0].position.y);
	}	
}

void dormir(WINDOW * winDialogue, Jeu & jeu) {
	if(jeu.getPersonnage().getPosX()==7
		&&jeu.getPersonnage().getPosY()==5
		&&jeu.getTerrain().terrCourant.getNom()
		==jeu.getTerrain().tabTerrain[0].getNom()) {
		jeu.getPersonnage().vie.setFatigue(0);
		mvwprintw(winDialogue,1,1,"Tu viens de te reposer.");
	}
	wgetch(winDialogue);
	werase(winDialogue);
}

void manger(WINDOW * winDialogue, Jeu & jeu) {
	Personnage& perso = jeu.getPersonnage();
	EnsembleTerrain& ter = jeu.getTerrain();
	if(perso.getPosX()==4&&perso.getPosY()==4
	   &&ter.terrCourant.getNom()==ter.tabTerrain[0].getNom()) {
		if(perso.inventaire.getManger().getNiveau()>0) {
			// Baisse de la faim
			jeu.getPersonnage().vie.setFaim(0);
			// Baisse de l'inventaire
			jeu.getPersonnage().inventaire.setManger
			(1,false);
			mvwprintw(winDialogue,1,1,"Tu viens de te nourrir.");
		}
		else mvwprintw(winDialogue,1,1,"Achetez à manger avant.");
	}
	wgetch(winDialogue);
	werase(winDialogue);
}

void boire(WINDOW * winDialogue, Jeu & jeu) {
	Personnage& perso = jeu.getPersonnage();
	EnsembleTerrain& ter = jeu.getTerrain();
	if(perso.getPosX()==4&&perso.getPosY()==3
	   &&ter.terrCourant.getNom()==ter.tabTerrain[0].getNom()) {
		if(perso.inventaire.getEau().getNiveau()>0) {
			// Baisse de la soif
			jeu.getPersonnage().vie.setSoif(0);
			// Baisse de l'inventaire
			jeu.getPersonnage().inventaire.setEau
			(1,false);
			mvwprintw(winDialogue,1,1,"Tu viens de boire.");
		}
	else mvwprintw(winDialogue,1,1,"Achetez à boire avant.");
	}
	wgetch(winDialogue);
	werase(winDialogue);
}

void txtBoucle (Jeu & jeu) {

	Terrain& ter = jeu.getTerrain().terrCourant;

	WINDOW * winTerrain = newwin(ter.getdimX(),ter.getdimY(),0,0);
	WINDOW * winDialogue = newwin(15,70,ter.getdimX(),0);
	WINDOW * winCommandes = newwin(ter.getdimX(),50,0,ter.getdimY());

	bool ok = true;
	int c;
	string reponse;

	noecho();

	do {		
		txtAff(winTerrain,winDialogue,winCommandes,jeu);
		timeout(500);
		jeu.actionsAutomatiques();
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
				mvwprintw(winDialogue,1,1,"Jardin en traveaux");
				wgetch(winDialogue);
				werase(winDialogue);
				//txtAffPlant(winDialogue,jeu);
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
			case 'e':
				changeTerrain(jeu);
				break;
			case 'd':
				dormir(winDialogue,jeu);
				break;
			case 'n':
				manger(winDialogue,jeu);
				break;
			case 'b':
				boire(winDialogue,jeu);
				break;
			case 'f':
				jeu.getPersonnage().vie.setPtsDeVie(5);
				break;
			case 'q':
				ok = false;
				break;
		}

		//Mission
		if(!jeu.getMissions().tabMission->at(0).getFini()
		&&jeu.getPersonnage().inventaire.getManger().jaugeRemplie()) {
        	jeu.getPersonnage().niveau.setNiveau
			(jeu.getPersonnage().niveau.getNiveau()+2);
			jeu.getMissions().tabMission->at(0).setFini(true);
    	}  
		// Fin du jeu
		if(jeu.getPersonnage().vie.getPtsDeVie().getNiveau()==0) {	
			ok=false;
		}
	  } while (ok); 

	if(jeu.getPersonnage().vie.getPtsDeVie().getNiveau()==0) {
		ok=true;
		do {
			mvwprintw(winDialogue,1,1,"GAME OVER");
			mvwprintw(winDialogue,2,1,"'q' pour quitter");
			c=wgetch(winDialogue);
			if(c=='q') ok=false;
		} while(ok); 
	}

	wclear(winDialogue);
	wclear(winTerrain);
	wclear(winCommandes);
	delwin(winDialogue);
	delwin(winTerrain);
	delwin(winCommandes);
}

