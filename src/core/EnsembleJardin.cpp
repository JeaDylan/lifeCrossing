#include "EnsembleJardin.h"



EnsembleJardin::EnsembleJardin(){
    tabJardin = new vector<Jardin>;
    dimX = 7;
    dimY = 7 ;
    char jar [dimX][dimY];
    //postion.setX() position en x du jardin sur le terrain
    //position.setY() position en y 
}

EnsembleJardin::~EnsembleJardin(){
    delete [] tabJardin;
    tabJardin = NULL;

}


unsigned int EnsembleJardin::getDimX(){ return dimX; }

unsigned int EnsembleJardin::getDimY(){ return dimY; }

void EnsembleJardin::setDimX(unsigned int dx){ return dimX = dx; }

void EnsembleJardin::setDimY(unsigned int dy){ return dimY = dy; }

void EnsembleJardin::addJardin(const Jardin & jardin){
   
    tabJardin->push_back(jardin);

}

void EnsembleJardin::suppJardin(unsigned int nx,unsigned  int ny){

    int taille = tabJardin->size();
    for(int i = 0; i < taille ; i++){
        if(nx == (*tabJardin)[i].position.getX() && ny == (*tabJardin)[i].position.getY() ){
                tabJardin->erase(tabJardin->begin() + i); 
        }
    }

}

int EnsembleJardin::recupIndice(unsigned int nx, unsigned int ny){
    //ajouter des assert pour verifier la position
    int taille = tabJardin->size();
    for(int i = 0; i < taille ; i++){
        if(nx == (*tabJardin)[i].position.getX() && ny == (*tabJardin)[i].position.getY() ){
            return i;
        }
    }

}
bool EnsembleJardin::estRecoltable(unsigned int x,unsigned int y){
    int i = recupIndice(x,y);
    if((*tabJardin)[i].getFini() == true) 
        return true;
    else return false;    
}

bool EnsembleJardin::planter(string nom, unsigned int nx, unsigned int ny){
    //enlever la graine de l'inventaire du perso
    int i = recupIndice(nx,ny);
    assignerFruitLeg(nom);
    (*tabJardin)[i].setOccupe(true);    
    clock_t time_req;
    time_req = clock();
    while( (clock() - time_req) < (*tabJardin)[i].getTempsRecolte() ){
             sleep(1);
    }
    assert((*tabJardin)[i].getPret() = false);
    (*tabJardin)[i].setPret(true);
    return true;

}


void EnsembleJardin::assignerFruitLeg(string nom){
     banqueFruitLeg.banqueDeFruitLeg(); //instancie une banque de fruit leg 
     plant = banqueFruitLeg.chercherFruitLeg(nom); //le FruitLeg du jardin est initialisé avec une graine

}


void EnsembleJardin::testRegression(){
    assert(tabJardin->empty());
    assert(tabJardin->size() == 0);
    Jardin jardin; 
    addJardin(jardin);
    assert(tabJardin->size() == 1);
    assert(tabJardin->at(0).getNomGraine() == "NULL");
    assert(tabJardin->at(0).getOccupe() == false);
    assignerFruitLeg(fraise);
    assert(tabJardin->at(0).getNomGraine() == "fraise");
    assert(tabJardin->at(0).getTypeGraine() == "fruit");

    
    


}
