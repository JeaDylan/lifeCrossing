#include "EnsembleJardin.h"



EnsembleJardin::EnsembleJardin(){
    tabJardin = new vector<Jardin>;
    dimX = 3;
    dimY = 6;

    //postion.setX() position en x du jardin sur le terrain
    //position.setY() position en y 
}

EnsembleJardin::~EnsembleJardin(){
    tabJardin->clear();
    tabJardin->shrink_to_fit ();
    delete tabJardin;
    tabJardin = NULL;

}


unsigned int EnsembleJardin::getDimX(){ return dimX; }

unsigned int EnsembleJardin::getDimY(){ return dimY; }

void EnsembleJardin::setDimX(unsigned int dx){  dimX = dx; }

void EnsembleJardin::setDimY(unsigned int dy){ dimY = dy; }

void EnsembleJardin::ajouterJardin(const Jardin & jardin){
   
    tabJardin->push_back(jardin);

}

void EnsembleJardin::suppJardin(unsigned int nx,unsigned  int ny){

    int taille = tabJardin->size();
    for(int i = 0; i < taille ; i++){
        if(nx == (*tabJardin)[i].getPosX() && ny == (*tabJardin)[i].getPosY() ){
                tabJardin->erase(tabJardin->begin() + i); 
        }
    }

}

int EnsembleJardin::recupIndice(unsigned int nx, unsigned int ny){
    //ajouter des assert pour verifier la position
    int taille = tabJardin->size();
    for(int i = 0; i < taille ; i++){
        if(nx == (*tabJardin)[i].getPosX() && ny == (*tabJardin)[i].getPosY() ){
            return i;
        }
    }
    return -1;

}
bool EnsembleJardin::estRecoltable(unsigned int x,unsigned int y){
    int i = recupIndice(x,y);
    if((*tabJardin)[i].getPret() == true) 
        return true;
    else return false;    
}




void EnsembleJardin::assignerFruitLeg(string nom,unsigned int indice){
     banqueFruitLeg.banqueDeFruitLeg(); //instancie une banque de fruit leg 
     (*tabJardin)[indice].setPlant(banqueFruitLeg.chercherFruitLeg(nom)); //le FruitLeg du jardin est initialisé avec une graine

}


void EnsembleJardin::testRegression(){
    cout <<"Debut test regression Module EnsembleJardin..."<<endl;
    assert(tabJardin->empty());
    assert(tabJardin->size() == 0);
    cout<<"Constructeur par défaut...OK"<<endl;
    Jardin jardin; 
    ajouterJardin(jardin);
    assert(tabJardin->size() == 1);
    assert(tabJardin->at(0).getPlant().getNomGraine() == "NULL");
    assert(tabJardin->at(0).getOccupe() == false);
    cout<<"Ajout d'un jardin...OK" <<endl;
    assignerFruitLeg("fraise",0);
    assert(tabJardin->at(0).getPlant().getNomGraine() == "fraise");
    assert(tabJardin->at(0).getPlant().getTypeGraine() == "fruit");
    cout<<"Assignation d'un Fraise au jardin[0]...OK" <<endl;
    ajouterJardin(Jardin());
    assert(tabJardin->size() == 2);
    assert(tabJardin->at(1).getPlant().getNomGraine() == "NULL");
    assert(tabJardin->at(1).getPosX() == 0);
    assert(tabJardin->at(1).getPosY() == 0);
    cout<<"Ajout d'un jardin par défaut...OK";
    assignerFruitLeg("coco",1);
    assert(tabJardin->at(1).getPlant().getNomGraine() == "coco");
    assert(tabJardin->at(1).getPlant().getTypeGraine() == "fruit");
    assert(tabJardin->at(1).getPlant().getGainEnergie() == 30);
    cout<<"Assignation d'un FruitLeg au jardin[1]...OK" <<endl;
    Jardin jardin2(5,5);
    ajouterJardin(jardin2);
    assert(tabJardin->size() == 3);
    cout<<"Ajout d'un jardin(5,5)...OK" <<endl;
    tabJardin->at(2).setPret(true);
    bool test = estRecoltable(tabJardin->at(2).getPosX(),tabJardin->at(2).getPosY());
    assert(test == true);   
    cout<<"Fin du test regression. Tout est OK!" << endl;

}
