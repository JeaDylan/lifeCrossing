#include <cassert>
#include "Jauge.h"

Jauge::Jauge() {
    niveauActuel=0;
    niveauMax=500;
}

Jauge::Jauge(int niv, int nivMax) {
    niveauActuel=niv;
    niveauMax=nivMax;
}

Jauge::~Jauge() {
    niveauActuel=0;
    niveauMax=500;
}

int Jauge::getNiveau() const {
    return niveauActuel;
}

int Jauge::getNiveauMax() const {
    return niveauMax;
}

void Jauge::setNiveau(int newNiveau) {
    if(newNiveau<=0)
    niveauActuel=0;
    else if(newNiveau>niveauMax)
    niveauActuel=niveauMax;
    else niveauActuel=newNiveau;
}

void Jauge::setNiveauMax(int newNiveauMax) {
    niveauMax=newNiveauMax;
}

bool Jauge::jaugeRemplie() const {
    return(niveauMax <= niveauActuel);
}

bool Jauge::jaugeVide() const {
    return(0==niveauActuel);
}

void Jauge::afficheJauge() const {
    cout<<" - " << niveauActuel << " / "<< niveauMax << endl;
}

string Jauge::afficheJeuTxt() const {
    return to_string(niveauActuel) + " / " + to_string(niveauMax);
}

void Jauge::testRegression() {
    cout<<"Tests pour le module Jauge :"<<endl;
    assert(niveauActuel == 0 && niveauMax==500);
    cout<<"Constructeur par défaut OK ..."<<endl;
    Jauge j(85, 150);
    assert(j.getNiveau()==85);
    assert(j.getNiveauMax()==150);
    cout<<"Constructeur par copie OK ..."<<endl;
    afficheJauge();
}
