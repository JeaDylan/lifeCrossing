#include "FruitLegume.h"

FruitLegume::FruitLegume(){
    nomGraine = "NULL";
    typeGraine = "NULL";
    prixGraine = 0 ;
    prixVente = 0;   
    gainEnergie = 0 ;
    tempsRecolte = 0;
}

FruitLegume::FruitLegume(string nomG, string typeG, int prixG, 
                        int prixV, int gainE,unsigned int tempsR) {
    
    assert(prixG >= 0 && prixV >= 0 && gainE >= 0);
    nomGraine = nomG;
    typeGraine = typeG;
    prixGraine = prixG;
    prixVente = prixV;   
    gainEnergie = gainE;
    tempsRecolte = tempsR;
}

string FruitLegume::getNomGraine()const{ return nomGraine; }

    
string FruitLegume::getTypeGraine()const{ return typeGraine; }


int FruitLegume::getPrixGraine()const{ return prixGraine; }


int FruitLegume::getPrixVente()const{ return prixVente; }


int FruitLegume::getGainEnergie()const{ return gainEnergie; }

unsigned int FruitLegume::getTempsRecolte()const{ return tempsRecolte; }


void FruitLegume::setNomGraine(string nom){  nomGraine = nom ;}   
      
void FruitLegume::setTypeGraine(string type){ 
    assert(type == "fruit" || type == "legume");
    typeGraine = type; }

void FruitLegume::setPrixGraine(int prixGr){
    assert(prixGr >= 0);
    prixGraine = prixGr;
}

void FruitLegume::setPrixVente(int prixVe){
    assert(prixVe >= 0);
    prixVente = prixVe; 
}

void FruitLegume::setGainEnergie(int gain){
    assert(gain >= 0);
    gainEnergie = gain;
}

void FruitLegume::setTempsRecolte(unsigned int temps){  
    tempsRecolte = temps ; 
}

string FruitLegume::affichejeuTxt() const {
    return nomGraine + " - " + to_string(prixGraine) + "$";
}

void FruitLegume::testRegression() const {
    //creation d'une fraise
    FruitLegume fraise("fraise","fruit",4,6,25,5); 
    assert(fraise.getNomGraine() == "fraise");
    assert(fraise.getTypeGraine() == "fruit");
    assert(fraise.getPrixGraine() == 4);
    assert(fraise.getPrixVente() == 6 );
    assert(fraise.getGainEnergie()== 25);
    assert(fraise.getTempsRecolte() == 5);
     //creation d'une courgette
    FruitLegume courgette("courgette","legume",6,8,50,120);
    fraise.setPrixGraine(15); 
    assert(fraise.getPrixGraine() == 15);
    fraise.setGainEnergie(3);
    assert(fraise.getGainEnergie()==3);
    courgette.setTempsRecolte(300);
    assert(courgette.getTempsRecolte() == 300);
    courgette.setTypeGraine("legume");
    assert(courgette.getTypeGraine() == "legume" );
}