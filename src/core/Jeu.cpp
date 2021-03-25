#include "Jeu.h"

Jeu::Jeu() : ter(), perso(), jardin() { }

Terrain& Jeu::getTerrain(){ return ter; }

Personnage& Jeu::getPersonnage(){ return perso; }

EnsembleJardin& Jeu::getJardin(){ return jardin; }

const Terrain& Jeu::getConstTerrain(){ return ter; }

const Personnage& Jeu::getConstPersonnage(){ return perso; }

const EnsembleJardin& Jeu::getConstJardin(){ return jardin;  }

void Jeu::actionClavier(const char touche){
    switch(touche){
        case 'g' :
			perso.gauche(ter);
			break;
		case 'd' :
			perso.droite(ter);
			break;
		case 'h' :
			perso.haut(ter);
			break;
		case 'b' :
			perso.bas(ter);
			break;
        case 'p' : //planter
            string rep;
            cout<<"Voulez-vous planter une graine? (oui/non) "<<endl;
            cin>>rep;
            assert(rep == "oui" || rep == "non");
            if(rep == "oui"){
                string graine;
                cout<<"Que voulez-vous planter?"<<endl;
                cin>>graine;
                cout<<"La graine est plantée, attendre qu'elle soit recoltable..."<<endl;
                //assert position valide -> fonction
                //assert getOccupe == false -> fonction
                if (perso.planter(graine,perso.position.getX(),perso.position.getY()) == true ){
                    ter.setChar(perso.getPosX(),perso.getPosY(),'-');                
                }                
            }
            break;
        case 'r' : //recolter
            string rep2;
            cout<<"Voulez-vous récolter cette graine?"<<endl;
            cin>>rep2;
            assert(rep == "oui" || rep == "non");
            if(rep2 == "oui"){
                if(ter.jardin.estRecoltable(perso.position.getX(),perso.position.getY()) == true){
                //assert position valide
                perso.recolter();//setOccupe = false
                }
                ter.setChar(perso.position.getX(),perso.position.getY(),'o');
                cout<<"La graine a été placé dans votre inventaire"<<endl;
            }
            break;     
        
   




}