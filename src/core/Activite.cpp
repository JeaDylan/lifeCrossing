#include <cassert>
#include "Activite.h"

Activite::Activite() {
    nom=" ";
    prix=0;
    position.setX(0);    
    position.setY(0);
    recompense=0;
    typeRecompense=" ";
}

Activite::Activite(string nomA, unsigned int prixA, Point2D positionA, unsigned int recompenseA, string typeRecompenseA) {
    nom=nomA;
    prix=prixA;
    position=positionA;
    recompense=recompenseA;
    typeRecompense=typeRecompenseA;
}

Activite::~Activite() {
    nom=" ";
    prix=0;
    position.setX(0);    
    position.setY(0);
    recompense=0;
    typeRecompense=" ";
}

string Activite::getNom()const {
    return nom;
}

unsigned int Activite::getPrix()const {
    return prix;
}

Point2D Activite::getPosition()const {
    return position;
}

unsigned int Activite::getRecompense()const {
    return recompense;
}

string Activite::getTypeRecompense()const {
    return typeRecompense;
}

void Activite::setNom(string newNom) {
    nom=newNom;
}

void Activite::setPrix(unsigned int newPrix) {
    prix=newPrix;
}

void Activite::setPosition(Point2D newPosition) {
    position=newPosition;
}

void Activite::setRecompense(unsigned int newRecompense) {
    recompense=newRecompense;
}

void Activite::setTypeRecompense(string newTypeRecompense) {
    typeRecompense=newTypeRecompense;
}

bool Activite::activiteEffectuee() const {
    return (recompense==0);
}

void Activite::afficheActivite() const {
    cout << "L'activité nommée " << nom << " coûte " << prix <<" pièces. Elle se trouve à la position ("
        << position.getX() << ", " << position.getY() <<") et vous donne " << recompense << " " << typeRecompense << endl;
}

string Activite::affichejeuTxt() const {
    return " - " + to_string(prix) + "$  + " 
            + to_string(recompense) + " " + typeRecompense;
}

void Activite::testRegression() {
    cout<<"Tests pour le module Activite :"<<endl;
    assert(nom == " ");
    assert(prix == 0);
    assert(recompense == 0);
    assert(position.getX()==0);
    assert(position.getY()==0);
    cout<<"Constructeur par défaut OK ..."<<endl;
    Point2D posA(10,10);
    Activite a("Alpha", 100, posA, 150, "xp");
    assert(a.getNom()=="Alpha");
    assert(a.getPrix()==100);
    assert(a.getRecompense()==150);
    assert(a.getTypeRecompense()=="xp");
    assert(a.getPosition().getX()==10 && a.getPosition().getY()==10);
    cout<<"Constructeur par copie OK ..."<<endl;
    a.setRecompense(0);
    assert(a.activiteEffectuee());
    cout<<"Activité bien effectuée"<<endl;
    a.afficheActivite();
}
