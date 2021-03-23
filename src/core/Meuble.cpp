#include <cassert>
#include "Meuble.h"


Meuble::Meuble() {
    nom="sansnom";
    dimension.setX(0);
    dimension.setY(0);
}

Meuble::Meuble(string nomM,const Point2D & dim) {
    nom=nomM;
    dimension=dim;
}

Meuble::~Meuble() {
    nom="sansnom";
    dimension.setX(0);
    dimension.setY(0);
}

string Meuble::getNomMeuble() const {
    return nom;
}

Point2D Meuble::getDimension() const {
    return dimension;
}

void Meuble::afficheMeuble() const {
    cout<<" - " << nom << " : ("<< dimension.getX()<<","<<dimension.getY() <<")"<<endl;
}

void Meuble::testRegression() {
    cout<<"Tests pour le module Meuble :"<<endl;
    assert(nom == "sansnom");
    assert(dimension.getX()==0&&dimension.getY()==0);
    cout<<"Constructeur par défaut OK ..."<<endl;
    Meuble m1("table",dimension);
    assert(m1.getNomMeuble()=="table");
    assert(m1.dimension.getX()==0&&m1.dimension.getY()==0);
    cout<<"Constructeur par copie OK ..."<<endl;
    afficheMeuble();
}
