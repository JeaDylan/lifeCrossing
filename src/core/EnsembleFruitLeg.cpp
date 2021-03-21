#include "EnsembleFruitLeg.h"


EnsembleFruitLeg::EnsembleFruitLeg(){
    tabFruitLeg = new vector<FruitLegume>;
  
}

EnsembleFruitLeg::~EnsembleFruitLeg(){
 
    delete [] tabFruitLeg;
    tabFruitLeg = NULL;
    
}

void EnsembleFruitLeg::addFruitLeg(const FruitLegume & fruitLeg){ //ajout dans le tabFruitLeg de l'inventaire du perso
          
          tabFruitLeg->push_back(fruitLeg);
          

}

void EnsembleFruitLeg::suppFruitLeg(string nom){ //suppression d'un fruit ou legume dans l'inventaire du perso
    int taille = tabFruitLeg->size();
    for(int i = 0; i < taille ; i++){
        if(nom == (*tabFruitLeg)[i].getNomGraine()){
                tabFruitLeg->erase(tabFruitLeg->begin() + i); 
        }
    }
}

void EnsembleFruitLeg::chercherFruitLeg(string nomFruitLeg)const{
    int taille = tabFruitLeg->size();
    for(int i = 0; i < taille ; i++){
        if(nomFruitLeg == (*tabFruitLeg)[i].getNomGraine()){
                cout << "Nom de la graine : " << (*tabFruitLeg)[i].getNomGraine() << endl;
                cout << "Type de la graine : " << (*tabFruitLeg)[i].getTypeGraine() << endl;
                cout << "Prix d'achat : " <<  (*tabFruitLeg)[i].getPrixGraine() << endl;
                cout << "Prix revente : " << (*tabFruitLeg)[i].getPrixVente() << endl;
                cout << "Gain energetique : " << (*tabFruitLeg)[i].getGainEnergie() << endl; 
                exit(1);
        }
    }
    cout << "Ce fruit ou legume n'est pas possede "<< endl;
    exit(0);

}

void EnsembleFruitLeg::afficheListeFruitLeg()const{
    cout << "Fruits et legumes disponibles : " <<endl;
    int taille = tabFruitLeg->size();
    for(int i = 0; i < taille; i++){
        cout << " - " << (*tabFruitLeg)[i].getNomGraine() << endl;
    }

}

void EnsembleFruitLeg::banqueDeFruitLeg(){ //il faut ajuster/definir les prix et gain energie

    tabFruitLeg->push_back(FruitLegume("banane","fruit",0,0,5,0));
    tabFruitLeg->push_back(FruitLegume("coco","fruit",0,0,12,0));
    tabFruitLeg->push_back(FruitLegume("fraise","fruit",1.4,3.9,0,9));
    tabFruitLeg->push_back(FruitLegume("framboise","fruit",1.6,4.1,0,1));
    tabFruitLeg->push_back(FruitLegume("orange","fruit",0,0,0,0));
    tabFruitLeg->push_back(FruitLegume("pamplemousse","fruit",0,0,0,0));
    tabFruitLeg->push_back(FruitLegume("poire","fruit",0,0,0,0));
    tabFruitLeg->push_back(FruitLegume("pomme","fruit",0,0,0,0));
    tabFruitLeg->push_back(FruitLegume("mure","fruit",0,0,0,0));    
    tabFruitLeg->push_back(FruitLegume("tomate", "fruit",0,0,0,0));

    tabFruitLeg->push_back(FruitLegume ("aubergine","legume",0,0,0,0));
    tabFruitLeg->push_back(FruitLegume ("brocolli","legume",0,0,0,0));
    tabFruitLeg->push_back(FruitLegume ("carotte","legume",0,0,0,0));
    tabFruitLeg->push_back(FruitLegume ("champignon","legume",0,0,0,0));
    tabFruitLeg->push_back(FruitLegume ("chou","legume",0,0,0,0));
    tabFruitLeg->push_back(FruitLegume ("fenouil","legume",0,0,0,0));
    tabFruitLeg->push_back(FruitLegume ("lentille","legume",0,0,0,0));
    tabFruitLeg->push_back(FruitLegume ("mais","legume",0,0,0,0));
    tabFruitLeg->push_back(FruitLegume ("patate","legume",0,0,0,0));
    tabFruitLeg->push_back(FruitLegume ("salede","legume",0,0,0,0));
    
}