#include "EnsembleFruitLeg.h"


EnsembleFruitLeg::EnsembleFruitLeg(){
    tabFruitLeg = new vector<FruitLegume>;
  
}

EnsembleFruitLeg::~EnsembleFruitLeg(){
    tabFruitLeg->clear();
    tabFruitLeg->shrink_to_fit ();
    delete tabFruitLeg;
    tabFruitLeg = NULL;
    
}



void EnsembleFruitLeg::ajouterFruitLeg(const FruitLegume & fruitLeg){ //ajout dans le tabFruitLeg de l'inventaire du perso
          
          tabFruitLeg->push_back(fruitLeg);
          

}

void EnsembleFruitLeg::suppFruitLeg(string nom,string type){ //suppression d'un fruit ou legume dans l'inventaire du perso
    int taille = tabFruitLeg->size();
    for(int i = 0; i < taille ; i++){
        if(nom == (*tabFruitLeg)[i].getNomGraine() && type == (*tabFruitLeg)[i].getTypeGraine() ){
                tabFruitLeg->erase(tabFruitLeg->begin() + i);
    
        }
    }
}


FruitLegume EnsembleFruitLeg::chercherFruitLeg(string nomFruitLeg)const{
    int taille = tabFruitLeg->size();
    int i;
    for(i = 0; i < taille ; i++){
        if(nomFruitLeg == (*tabFruitLeg)[i].getNomGraine()){
               
                return (*tabFruitLeg)[i];
        }
    }
    if(i == taille){
        cout << "Ce fruit ou legume n'est pas possede ou n'existe pas "<< endl;
    }
}

void EnsembleFruitLeg::afficheListeFruitLeg()const{
    cout << "Fruits et legumes disponibles : " <<endl;
    int taille = tabFruitLeg->size();
    for(int i = 0; i < taille; i++){
        cout << " - " << "("<< i<<")"<< (*tabFruitLeg)[i].getNomGraine() << endl;
    }

}


void EnsembleFruitLeg::banqueDeFruitLeg(){ //il faut ajuster/definir les prix et gain energie

    tabFruitLeg->push_back(FruitLegume("banane","fruit",11,22,5,50));
    tabFruitLeg->push_back(FruitLegume("coco","fruit",10,20,30,9));
    tabFruitLeg->push_back(FruitLegume("fraise","fruit",13,26,15,9));
    tabFruitLeg->push_back(FruitLegume("framboise","fruit",12,24,13,1));
    tabFruitLeg->push_back(FruitLegume("orange","fruit",22,44,27,7));
    tabFruitLeg->push_back(FruitLegume("pamplemousse","fruit",20,40,23,8));
    tabFruitLeg->push_back(FruitLegume("poire","fruit",23,46,10,4));
    tabFruitLeg->push_back(FruitLegume("pomme","fruit",24,48,14,5));
    tabFruitLeg->push_back(FruitLegume("mure","fruit",19,38,4,3));    
    tabFruitLeg->push_back(FruitLegume("tomate", "fruit",15,30,60,30));
    tabFruitLeg->push_back(FruitLegume("pasteque", "fruit",25,50,60,30));
    tabFruitLeg->push_back(FruitLegume("raisin", "fruit",18,36,60,30));

    tabFruitLeg->push_back(FruitLegume ("aubergine","legume",26,78,7,22));
    tabFruitLeg->push_back(FruitLegume ("brocolli","legume",12,36,32,62));
    tabFruitLeg->push_back(FruitLegume ("carotte","legume",22,66,17,18));
    tabFruitLeg->push_back(FruitLegume ("champignon","legume",15,45,25,10));
    tabFruitLeg->push_back(FruitLegume ("chou","legume",14,42,12,9));
    tabFruitLeg->push_back(FruitLegume ("fenouil","legume",10,30,19,20));
    tabFruitLeg->push_back(FruitLegume ("poivron","legume",18,54,70,90));
    tabFruitLeg->push_back(FruitLegume ("mais","legume",30,90,70,100));
    tabFruitLeg->push_back(FruitLegume ("patate","legume",10,30,100,95));
    tabFruitLeg->push_back(FruitLegume ("salade","legume",19,57,34,24));
    tabFruitLeg->push_back(FruitLegume ("radis","legume",18,54,34,24));
    tabFruitLeg->push_back(FruitLegume ("piment","legume",50,150,100,24));
    
}


void EnsembleFruitLeg::testRegression(){
   //j'instancie un EnsembleFruitLeg dans le main   
   cout<<"Debut test regression EnsembleFruitLeg..."<<endl;
   EnsembleFruitLeg test;
   assert(test.tabFruitLeg != NULL);//verification du constructeur
   assert(test.tabFruitLeg->size() == 0);
   FruitLegume fraise = FruitLegume("fraise","fruit",4,6,25,5);
   FruitLegume courgette = FruitLegume("courgette","legume",6,8,50,120);
   test.ajouterFruitLeg(fraise);
   assert(test.tabFruitLeg->size() == 1);
   assert(test.tabFruitLeg->at(0).getNomGraine() == "fraise");
   assert(test.tabFruitLeg->at(0).getPrixGraine() == 4);
   test.ajouterFruitLeg(courgette);
   assert(test.tabFruitLeg->size() == 2);
   test.suppFruitLeg("fraise","fruit");
   assert(test.tabFruitLeg->size() == 1);
   assert(test.tabFruitLeg->at(0).getNomGraine() == "courgette");
   test.afficheListeFruitLeg(); //affichage d'une liste sur le terminal
   EnsembleFruitLeg testBanque; //test de la banque de FruitLegume
   testBanque.banqueDeFruitLeg();
   assert(testBanque.tabFruitLeg->at(0).getNomGraine() == "banane");
   assert(testBanque.tabFruitLeg->at(1).getNomGraine() == "coco");
   assert(testBanque.tabFruitLeg->at(10).getNomGraine() == "aubergine");
   testBanque.afficheListeFruitLeg();
   cout<<"Test Regression EnsembleFruitLeg...OK"<<endl;

}