#include <cassert>
#include "Jauge.h"

Jauge::Jauge() {
    niveauActuel=0;
    niveauMax=100;
}

Jauge::Jauge(int niv, int nivMax) {
    niveauActuel=niv;
    niveauMax=nivMax;
}

Jauge::~Jauge() {
    niveauActuel=0;
    niveauMax=100;
}

int Jauge::getNiveau() const {
    return niveauActuel;
}

int Jauge::getNiveauMax() const {
    return niveauMax;
}

void Jauge::setNiveau(int newNiveau) {
    niveauActuel=newNiveau;
}

void Jauge::setNiveauMax(int newNiveauMax) {
    niveauMax=newNiveauMax;
}

bool Jauge::jaugeRemplie() const {
    return(niveauMax<niveauActuel);
}

void Jauge::afficheJauge() const {
    cout<<" - " << niveauActuel << " / "<< niveauMax << endl;
}

string Jauge::afficheJeuTxt() const {
    return to_string(niveauActuel) + " / " + to_string(niveauMax);
}

void Jauge::testRegression() {
    cout<<"Tests pour le module Jauge :"<<endl;
    assert(niveauActuel == 0 && niveauMax==100);
    cout<<"Constructeur par défaut OK ..."<<endl;
    Jauge j(85, 150);
    assert(j.getNiveau()==85);
    assert(j.getNiveauMax()==150);
    cout<<"Constructeur par copie OK ..."<<endl;
    afficheJauge();
}
