#include <cassert>
#include "Portail.h"


Portail::Portail() {
    nom="sansnom";
    position.setX(0);
    position.setY(0);
}

Portail::Portail(string nomP,const Point2D & pos) {
    nom=nomP;
    position=pos;
}

Portail::~Portail() {
    nom="sansnom";
    position.setX(0);
    position.setY(0);
}

string Portail::getNomPortail() const {
    return nom;
}

Point2D Portail::getPosition() const {
    return position;
}

void Portail::affichePortail() const {
    cout<<" - " << nom << " : ("<< position.getX()<<","<<position.getY() <<")"<<endl;
}

void Portail::testRegression() {
    cout<<"Tests pour le module Portail :"<<endl;
    assert(nom == "sansnom");
    assert(position.getX()==0&&position.getY()==0);
    cout<<"Constructeur par défaut OK ..."<<endl;
    Portail p1("test",position);
    assert(p1.getNomPortail()=="test");
    assert(p1.position.getX()==0&&p1.position.getY()==0);
    cout<<"Constructeur par copie OK ..."<<endl;
    affichePortail();
}
