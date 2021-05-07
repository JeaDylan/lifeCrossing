#include "Jeu.h"

Jeu::Jeu() : ter(), perso(), jardin(), pnjs(), activites(), fruitsLeg() , mission() {

        jardin.tabJardin->push_back(Jardin(1,3));//tabJardin[0]
        jardin.tabJardin->push_back(Jardin(2,3));//tabJardin[1]
        jardin.tabJardin->push_back(Jardin(1,2));//tabJardin[2]
        jardin.tabJardin->push_back(Jardin(2,2));//tabJardin[3]

        //position des jardins dans la version graphique
         jardin.tabJardin->push_back(Jardin(9,3));//tabJardin[4]
         jardin.tabJardin->push_back(Jardin(9,5));//tabJardin[5]
         jardin.tabJardin->push_back(Jardin(9,7));//tabJardin[6]
         jardin.tabJardin->push_back(Jardin(11,3));//tabJardin[7]
         jardin.tabJardin->push_back(Jardin(11,5));//tabJardin[8]
         jardin.tabJardin->push_back(Jardin(11,7));//tabJardin[9]
         jardin.tabJardin->push_back(Jardin(14,3));//tabJardin[10]
         jardin.tabJardin->push_back(Jardin(14,5));//tabJardin[11]
         jardin.tabJardin->push_back(Jardin(14,7));//tabJardin[12]
         jardin.tabJardin->push_back(Jardin(16,3));//tabJardin[13]
         jardin.tabJardin->push_back(Jardin(16,5));//tabJardin[14]
         jardin.tabJardin->push_back(Jardin(16,7));//tabJardin[15]


         
         //initialisation de l'inventaire du perso avec une banane, une fraise et une coco  (graine)       
         perso.inventaire.ajouterFruitLeg(FruitLegume("banane","graine",4,8,5,50));
         perso.inventaire.ajouterFruitLeg(FruitLegume("fraise","graine",4,8,5,50));
         perso.inventaire.ajouterFruitLeg(FruitLegume("coco","graine",4,8,5,50));
         
        pnjs.tabPnj.push_back(Pnj("Luc","Bonjour, je suis Luc !",Point2D(7,12)));
        pnjs.tabPnj.push_back(Pnj("Jules","Bonjour, je suis Jules !",Point2D(15,6)));
         
        activites.tabActivite.push_back(Activite("Cinema",10,Point2D(7,14),50,"xp"));
        activites.tabActivite.push_back(Activite("Plongée",200,Point2D(19,12),500,"xp"));
        
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
    bool succes = false;
    int i = jardin.recupIndice(nx,ny);    // i = indice du jardin de coordonnée (nx,ny) dans le tableau ensembleJardin
    bool possede = perso.possedeFruitLeg(nom,"graine");   //verifie si le perso dispose de la graine dans son inventaire    
    if(possede == true){ 
        if(jardin.tabJardin->at(i).getOccupe() == false){    //on verifie que la parcelle est libre (jardin occupé = faux)
            perso.inventaire.inventaireFruitLeg.suppFruitLeg(nom,"graine"); //enlever la graine de l'inventaire du perso
            jardin.assignerFruitLeg(nom,i); //un fruit est attribué au jardin de position (nx,ny) 
            jardin.tabJardin->at(i).setOccupe(true); //jardin occupé = vrai
            assert(jardin.tabJardin->at(i).getPret() == false); 
            jardin.tabJardin->at(i).setPret(true);//concerne le temps de recolte
            succes = true; 
            perso.xp.setNiveau(perso.xp.getNiveau()+15); //augmente le niv d'XP du perso
            cout<<"Graine de "<<nom<<" plantée avec succès! Récoltes-là à présent."<<endl;
            cout<<"+15XP"<<endl;
            cout<<"Niv XP actuel : "<<perso.xp.getNiveau()<<endl;
        }else{
            cout<<"Une graine est déjà plantée ici"<<endl;
            succes = false;
        }
    }else{
        cout<<"Tu ne possèdes aucune graine de "<<nom<<" dans ton inventaire. Tu peux allez en acheter au marché."<<endl;
        succes = false;
    }   
   
    
    return succes;

}

void Jeu::recolter(unsigned int nx,unsigned int ny){
    int i = jardin.recupIndice(nx,ny);  // i = indice du jardin de coordonnée (nx,ny) dans le tableau ensembleJardin
    string recolte = jardin.tabJardin->at(i).getPlant().getNomGraine(); //on recupere le nom du fruitLeg planté au jardin d'indice i
    FruitLegume fruitLeg = jardin.tabJardin->at(i).getPlant(); //on "transforme" la graine en fruitLeg
    perso.inventaire.ajouterFruitLeg(fruitLeg);    //ajout du fruitLeg a l'inventaire du perso
    jardin.tabJardin->at(i).setOccupe(false); //jardin occupé = faux
    jardin.tabJardin->at(i).setPret(false);  //concerne la gestion du temps
    FruitLegume vide; //on instancie un fruitLeg vide
    jardin.tabJardin->at(i).setPlant(vide); //on enleve la graine du jardin avec le fruitLeg vide
    int valeur = rand()%20 + 1; 
    perso.gainArgent(valeur); //le perso gagne de l'argent , somme aléatoire valeur
    cout<<recolte<<" a été ajoutée à ton inventaire."<<endl;
    cout<<" +"<<valeur<<"$"<<endl;
    cout<<"Solde actuel :"<<perso.getArgent()<<"$"<<endl;

        
}


void Jeu::acheter(string reponse){
    int solde = perso.getArgent();
    FruitLegume achat = fruitsLeg.chercherFruitLeg(reponse); //on recupere le fruitLeg ou le perso a cliqué
    int prix = achat.getPrixGraine(); //on recupere le prix de la graine
    if((solde - prix)>= 0){ //on verifie que le perso a assez d'argent
        achat.setTypeGraine("graine"); //on "transforme" le fruitLeg en graine
        perso.inventaire.ajouterFruitLeg(achat); //on ajoute la graine à l'inventaire        
        perso.perteArgent(prix); //le perso paie le prix
        cout<<"-"<<prix<<"$"<<endl;
        cout << "Tu as acheté une graine de "<<reponse<<endl;
        cout<<"Solde actuel :"<<solde-prix<<"$"<<endl;   
    }else{
        cout<<"Tu n'as pas assez d'argent"<<endl;
    }
    
}

void Jeu::vendre(string reponse){
        FruitLegume vente = fruitsLeg.chercherFruitLeg(reponse); //on recupere le fruitLeg ou le perso a cliqué
        string type = vente.getTypeGraine(); //on recupere le type du fruitLeg a vendre (fruit ou legume)
        bool possede = perso.possedeFruitLeg(reponse,type); //on verifie que le perso possede le fruitLeg
        if(possede == true){
            int prix = vente.getPrixVente();
            perso.gainArgent(prix);
            cout<<"+"<<prix<<"$"<<endl;
            perso.inventaire.suppFruitLeg(reponse,type);
            cout<<"Vous avez vendu un(e) : "<<reponse<<endl;

        }else{
            cout <<"Tu ne possèdes pas ce fruit ou legume"<<endl;
        }
 
    
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