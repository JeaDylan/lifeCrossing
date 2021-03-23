#include "EnsembleMeuble.h"
#include <cassert>


EnsembleMeuble::EnsembleMeuble(){
    tabMeuble = new vector<Meuble>;
}

EnsembleMeuble::~EnsembleMeuble() {
    tabMeuble->clear();
    tabMeuble->shrink_to_fit ();
    delete tabMeuble;
    tabMeuble = NULL;
    
}

void EnsembleMeuble::ajouterMeuble(const Meuble & meuble) {
    tabMeuble->push_back(meuble);
}

void EnsembleMeuble::suppMeuble(string nomMeuble) {
    int taille = tabMeuble->size();
    for(int i = 0; i < taille ; i++){
        if(nomMeuble == (*tabMeuble)[i].getNomMeuble()) {
                tabMeuble->erase(tabMeuble->begin() + i);
    
        }
    }
}

void EnsembleMeuble::afficheListeMeuble()const {
    cout << "Meubles et leurs dimensions : " <<endl;
    int taille = tabMeuble->size();
    for(int i = 0; i < taille; i++){
        (*tabMeuble)[i].afficheMeuble();
    }

}

void EnsembleMeuble::testRegression() {
   cout<<"Tests pour le module EnsembleMeuble :"<<endl;
   EnsembleMeuble test;
   assert(test.tabMeuble != NULL);
   assert(test.tabMeuble->size() == 0);
   cout<<"Constructeur par Défaut OK ..."<<endl;

   //création d'un meuble
   Point2D tablePoints1(0,1);
   Point2D tablePoints2(1,1);
   Meuble table1("table1",tablePoints1);
   Meuble table2("table2",tablePoints2);
   assert(table1.getNomMeuble()=="table1"&&table2.getNomMeuble()=="table2");
   assert(table1.getDimension().getX()==0&&table1.getDimension().getY()==1);
   assert(table2.getDimension().getX()==1&&table2.getDimension().getY()==1);
   table1.afficheMeuble();
   table2.afficheMeuble();
   cout<<"Constructeur par copie OK ..."<<endl;
   test.ajouterMeuble(table1);
   test.ajouterMeuble(table2);
   assert(test.tabMeuble->size() == 2);
   assert(test.tabMeuble->at(0).getNomMeuble() == "table1");
   assert(test.tabMeuble->at(1).getNomMeuble() == "table2");
   test.suppMeuble("table1");
   assert(test.tabMeuble->size()==1);
   test.tabMeuble->at(0).afficheMeuble();
   cout<<"Suppression OK ..."<<endl;
   test.afficheListeMeuble();
   cout<<"Test Regression EnsembleMeuble...OK"<<endl;

}