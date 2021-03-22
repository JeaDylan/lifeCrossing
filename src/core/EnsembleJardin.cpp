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
    int taille = tabJardin->size();
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


bool EnsembleJardin::planter(string nom, unsigned int nx, unsigned int ny){
    int i = recupIndice(nx,ny);
    assignerFruitLeg((*tabJardin)[i], nom);
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


void EnsembleJardin::assignerFruitLeg(Jardin & jardin, string nom){
     banqueFruitLeg.banqueDeFruitLeg(); //instancie une banque de fruit leg 
     jardin.plant = banqueFruitLeg.chercherFruitLeg(nom); //le FruitLeg du jardin est initialisé avec une graine

}
