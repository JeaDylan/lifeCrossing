#include <cassert>
#include "Inventaire.h"


Inventaire::Inventaire() {
    stockFruitLeg.setNiveau(5);
    stockEau.setNiveau(5);
    stockManger.setNiveau(5);
    stockFruitLeg.setNiveauMax(50);
    stockEau.setNiveauMax(50);
    stockManger.setNiveauMax(50);
}

Inventaire::~Inventaire() {
    stockFruitLeg.setNiveau(5);
    stockEau.setNiveau(5);
    stockManger.setNiveau(5);
    stockFruitLeg.setNiveauMax(50);
    stockEau.setNiveauMax(50);
    stockManger.setNiveauMax(50);
}

Jauge Inventaire::getFruitLeg() const {
    return stockFruitLeg;
}

Jauge Inventaire::getEau() const {
    return stockEau;
}

Jauge Inventaire::getManger() const {
    return stockManger;
}

void Inventaire::setFruitLeg(int nouveau, bool augmente) {
    assert(nouveau>=0);
    if (augmente) 
    stockFruitLeg.setNiveau(stockFruitLeg.getNiveau()+nouveau);
    if (!augmente)
    stockFruitLeg.setNiveau(stockFruitLeg.getNiveau()-nouveau);
}

void Inventaire::setEau(int nouveau, bool augmente) {
    assert(nouveau>=0);
    if (augmente) 
    stockEau.setNiveau(stockEau.getNiveau()+nouveau);
    if (!augmente) 
    stockEau.setNiveau(stockEau.getNiveau()-nouveau);
}

void Inventaire::setManger(int nouveau, bool augmente) {
    assert(nouveau>=0);
    if (augmente) 
    stockManger.setNiveau(stockManger.getNiveau()+nouveau);
    if (!augmente) 
    stockManger.setNiveau(stockManger.getNiveau()-nouveau);
}

void Inventaire::afficheInventaire() const {
    cout<<"Voici votre inventaire :"<<endl;
    cout<<"Stock de Fruits et Legumes :"<<endl;
    stockFruitLeg.afficheJauge();
    cout<<"Stock d'Eau :"<<endl;
    stockEau.afficheJauge();
    cout<<"Stock de Nourriture :"<<endl;
    stockManger.afficheJauge();
}

EnsembleFruitLeg Inventaire::getInventaireFruitLeg() const {
    return inventaireFruitLeg;
}

void Inventaire::ajouterFruitLeg(const FruitLegume &fruitLeg){
   
    inventaireFruitLeg.tabFruitLeg->push_back(fruitLeg);
    setFruitLeg(1,true);
  
}

void Inventaire::suppFruitLeg(string fruitLeg,string type){
    FruitLegume supp = inventaireFruitLeg.chercherFruitLeg(fruitLeg);
    type = supp.getTypeGraine();
    inventaireFruitLeg.suppFruitLeg(fruitLeg,type);
    setFruitLeg(1,false);
}

void Inventaire::testRegression() {
    cout<<"Tests pour le module Inventaire :"<<endl;
    assert(stockFruitLeg.getNiveau() == 5);
    assert(stockEau.getNiveau() == 5);
    assert(stockManger.getNiveau() == 5);
    assert(stockFruitLeg.getNiveauMax() == 50);
    assert(stockEau.getNiveauMax() == 50);
    assert(stockManger.getNiveauMax() == 50);
    cout<<"Constructeur par défaut OK ..."<<endl;
    setFruitLeg(5,true);
    assert(stockFruitLeg.getNiveau()==10);
    setEau(4,false);
    assert(stockEau.getNiveau()==1);
    afficheInventaire();
    Inventaire test;
    assert(test.inventaireFruitLeg.tabFruitLeg->size() == 0);
    cout<<"Construction de inventaireFruitLeg...OK"<<endl;
    //test.ajouterFruitLeg("banane");
    assert(test.inventaireFruitLeg.tabFruitLeg->size()== 1);
    assert(test.inventaireFruitLeg.tabFruitLeg->at(0).getNomGraine() == "banane");
    cout<<"Ajout FruitLeg à l'inventaire...OK"<<endl;
    //bool b = test.possedeFruitLeg("banane");
    //assert(b == true);
    //cout<<"possedeFruitLeg()...OK"<<endl;
    test.suppFruitLeg("banane","fruit");
    assert(inventaireFruitLeg.tabFruitLeg->size() == 0);
    cout<<"Suppression du FruitLeg...OK"<<endl;

}
