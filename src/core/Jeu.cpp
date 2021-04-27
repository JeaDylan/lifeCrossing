#include "Jeu.h"

Jeu::Jeu() : ter(), perso(), jardin(), pnjs(), activites(), fruitsLeg() , mission() {

        jardin.tabJardin->push_back(Jardin(1,3));//tabJardin[0]
        jardin.tabJardin->push_back(Jardin(2,3));//tabJardin[1]
        jardin.tabJardin->push_back(Jardin(1,2));//tabJardin[2]
        jardin.tabJardin->push_back(Jardin(2,2));//tabJardin[3]
         
        pnjs.tabPnj.push_back(Pnj("Luc","Bonjour, je suis Luc !",Point2D(7,12)));
        pnjs.tabPnj.push_back(Pnj("Jules","Bonjour, je suis Jules !",Point2D(15,6)));
         
        activites.tabActivite.push_back(Activite("Cinema",10,Point2D(7,14),50,"xp"));
        
        fruitsLeg.banqueDeFruitLeg();
         
        ter.banqueDeTerrain();

        mission.banqueMission();

 }

EnsembleTerrain& Jeu::getTerrain(){ return ter; }

Personnage& Jeu::getPersonnage(){ return perso; }

EnsembleJardin& Jeu::getJardin(){ return jardin; }

EnsemblePnj& Jeu::getPnjs(){ return pnjs; }

EnsembleActivite& Jeu::getActivites(){ return activites; }

EnsembleFruitLeg& Jeu::getFruitLeg(){return fruitsLeg;}

EnsembleMission& Jeu::getMissions(){return mission;}

const EnsembleTerrain& Jeu::getConstTerrain()const{ return ter; }

const Personnage& Jeu::getConstPersonnage()const{ return perso; }

const EnsembleJardin& Jeu::getConstJardin()const{ return jardin;  }

const EnsemblePnj& Jeu::getConstPnjs() const{ return pnjs; }

const EnsembleActivite& Jeu::getConstActivites() const{ return activites; }

const EnsembleFruitLeg& Jeu::getConstFruitLeg() const{ return fruitsLeg;}

const EnsembleMission& Jeu::getConstMissions() const{ return mission;}

void Jeu::actionsAutomatiques() {
    getPersonnage().vie.varieAuto();
    getPersonnage().varieAuto();

    // Fonction mission1
    if(getPersonnage().inventaire.getFruitLeg().jaugeRemplie()
        &&getMissions().tabMission->at(0).getFini()==false) {
			getPersonnage().niveau.setNiveau
            (getPersonnage().niveau.getNiveau()
            +getMissions().tabMission->at(0).getRecompense());
			getMissions().tabMission->at(0).setFini(true);
		}
}

void Jeu::actionClavier(const char touche){
    string rep;
    switch(touche){
        case 'g' :
			perso.gauche(ter.terrCourant);
			break;
		case 'd' :
			perso.droite(ter.terrCourant);
			break;
		case 'h' :
			perso.haut(ter.terrCourant);
			break;
		case 'b' :
			perso.bas(ter.terrCourant);
			break;
        case 'j' : //planter

            break;
        case 'r' : //recolter
            string rep2;
            cout<<"Voulez-vous récolter cette graine (oui/non)?"<<endl;
            cin>>rep2;
            assert(rep2 == "oui" || rep2 == "non");
            if(rep2 == "oui"){
                if(jardin.estRecoltable(perso.getPosX(),perso.getPosY()) == true){
                //assert position valide
                  recolter();
                  ter.terrCourant.setChar(perso.getPosX(),perso.getPosY(),'o');
                }
                
                cout<<"La graine a été placée dans votre inventaire"<<endl;
            }
            else {
                cout << "La graine n'est pas prête...Attendez un peu!" <<endl;
            }
            break;
    }
        
}

bool Jeu::posJardinValide() {
    for(int i=0;i<getJardin().tabJardin->size();i++) {
        if(getPersonnage().getPosX()==getJardin().tabJardin->at(i).getPosX()
        &&getPersonnage().getPosY()==getJardin().tabJardin->at(i).getPosY()) {
            return true;
        }
    }
    return false;
}

bool Jeu::planter(string nom, unsigned int nx, unsigned int ny){
    bool fin = false;
    //enlever la graine de l'inventaire du perso
    int i = jardin.recupIndice(nx,ny);
    jardin.assignerFruitLeg(nom,i);
    jardin.tabJardin->at(i).setOccupe(true);    
    unsigned int j = 0;  
    while(j  < jardin.tabJardin->at(i).getPlant().getTempsRecolte() ){
           j++;        
    }      
    
   
    assert(jardin.tabJardin->at(i).getPret() == false);
    jardin.tabJardin->at(i).setPret(true);
    fin = true;
    return fin;

}

void Jeu::recolter(){
    int i = jardin.recupIndice(perso.getPosX(),perso.getPosY());
    string recolte = jardin.tabJardin->at(i).getPlant().getNomGraine();
    FruitLegume fruitLeg = jardin.banqueFruitLeg.chercherFruitLeg(recolte);
    //ajout fruitLeg à l'inventaire du perso
    
    jardin.tabJardin->at(i).setOccupe(false); 
    jardin.tabJardin->at(i).setPret(false); 
    FruitLegume vide; 
    jardin.tabJardin->at(i).getPlant() = vide; //on enleve la graine du jardin

        
}

void Jeu::testRegression(){

    cout<<"Debut test regression Module Jeu..."<< endl;
    assert(jardin.tabJardin->at(0).getPosX() == 1);
    assert(jardin.tabJardin->at(0).getPosY() == 12);
    cout <<"Jardin 1 initialisée...OK" <<endl;
    assert(jardin.tabJardin->at(1).getPosX() == 3);
    assert(jardin.tabJardin->at(1).getPosY() == 12);
    cout <<"Jardin 2 initialisée...OK" <<endl;
    assert(ter.terrCourant.getXY(1,12) == 'J');
    assert(ter.terrCourant.getXY(3,12) == 'J');
    assert(ter.terrCourant.getXY(5,12) == 'J');
    cout <<"Le caractere J est placé...OK"<<endl;   
    perso.setPosX(20);
    perso.setPosY(10);
    unsigned int position_depart = perso.getPosX();
    actionClavier('g'); //deplace a gauche
    assert(perso.getPosX() == position_depart - 1 );
    
    actionClavier('p');
    cout<<"Perso deplacé vers la gauche...OK"<<endl;
}