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

void EnsembleFruitLeg::suppFruitLeg(string nom){ //suppression d'un fruit ou legume dans l'inventaire du perso
    int taille = tabFruitLeg->size();
    for(int i = 0; i < taille ; i++){
        if(nom == (*tabFruitLeg)[i].getNomGraine()){
                tabFruitLeg->erase(tabFruitLeg->begin() + i);
    
        }
    }
}

FruitLegume EnsembleFruitLeg::chercherFruitLeg(string nomFruitLeg)const{
    int taille = tabFruitLeg->size();
    for(int i = 0; i < taille ; i++){
        if(nomFruitLeg == (*tabFruitLeg)[i].getNomGraine()){
               
                return (*tabFruitLeg)[i];
        }
    }
    cout << "Ce fruit ou legume n'est pas possede ou n'existe pas "<< endl;
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
    tabFruitLeg->push_back(FruitLegume ("salade","legume",0,0,0,0));
    
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
   test.suppFruitLeg("fraise");
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