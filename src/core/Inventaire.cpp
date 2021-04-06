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
    assert(nouveau>0);
    if ( augmente && stockFruitLeg.getNiveau()+nouveau<stockFruitLeg.getNiveauMax()) 
    stockFruitLeg.setNiveau(stockFruitLeg.getNiveau()+nouveau);
    if ( !augmente && stockFruitLeg.getNiveau()>nouveau)
    stockFruitLeg.setNiveau(stockFruitLeg.getNiveau()-nouveau);
}

void Inventaire::setEau(int nouveau, bool augmente) {
    assert(nouveau>0);
    if ( augmente && stockEau.getNiveau()+nouveau<stockEau.getNiveauMax()) 
    stockEau.setNiveau(stockEau.getNiveau()+nouveau);
    if ( !augmente && stockEau.getNiveau()>nouveau)
    stockEau.setNiveau(stockEau.getNiveau()-nouveau);
}

void Inventaire::setManger(int nouveau, bool augmente) {
    assert(nouveau>0);
    if ( augmente && stockManger.getNiveau()+nouveau<stockManger.getNiveauMax()) 
    stockManger.setNiveau(stockManger.getNiveau()+nouveau);
    if ( !augmente && stockManger.getNiveau()>nouveau)
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
}