#include "FruitLegume.h"



FruitLegume::FruitLegume(string nomG, string typeG, int prixG, int prixV, int gainE){
    
    assert(prixG > 0 && prixV > 0 && gainE > 0);
    nomGraine = nomG;
    typeGraine = typeG;
    prixGraine = prixG;
    prixVente = prixV;   
    gainEnergie = gainE;

}



FruitLegume::~FruitLegume(){
    nomGraine = NULL;
    typeGraine = NULL;
    prixGraine = 0 ;
    prixVente = 0 ;   
    gainEnergie = 0 ;

}


string FruitLegume::getNomGraine()const{ return nomGraine; }

    
string FruitLegume::getTypeGraine()const{ return typeGraine; }


int FruitLegume::getPrixGraine()const{ return prixGraine; }


int FruitLegume::getPrixVente()const{ return prixVente; }


int FruitLegume::getGainEnergie()const{ return gainEnergie; }


void FruitLegume::setNomGraine(string nom){  nomGraine = nom ;}   
   
    
void FruitLegume::setTypeGraine(string type){ typeGraine = type; }

void FruitLegume::setPrixGraine(int prixGr){
    assert(prixGr > 0);
    prixGraine = prixGr;
}

void FruitLegume::setPrixVente(int prixVe){
    assert(prixVe > 0);
    prixVente = prixVe; 
}

void FruitLegume::setGainEnergie(int gain){
    assert(gain > 0);
    gainEnergie = gain;
}

void FruitLegume::testRegression(){
    FruitLegume fraise("fraise","fruit",4,6,25);
    FruitLegume courgette("courgette","legume",6,8,50);
    cout << "Que voulez vous manger? Fruit ou Legume? " << endl;
    int reponse;
    cin >> reponse;
    if (reponse == "fruit"){
        cout << "Voici une fraise" << endl;
        cout << "Type : " << fraise.getTypeGraine << endl;
        cout << "Prix de " << fraise.getNomGraine << " : " << fraise.getPrixGraine << endl ;
        cout << "Regain energie : " << fraise.getGainEnergie << endl;
    }


}