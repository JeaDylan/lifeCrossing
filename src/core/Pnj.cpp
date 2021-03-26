#include "Pnj.h"
#include <cassert>

Pnj::Pnj() {
    nom="sansNom";
    dialogue="Bonjour !";
    //mission=Mission();
    position.setX(0);
    position.setY(0);
}

Pnj::Pnj(string nomPNJ, string dialoguePNJ, /*Mission missionPNJ,*/ Point2D positionPNJ) {
    nom=nomPNJ;
    dialogue=dialoguePNJ;
    //mission=missionPNJ;
    position=positionPNJ;
}

Pnj::~Pnj() {
    nom="sansNom";
    dialogue="Bonjour !";
    //mission.~Mission();
    position.~Point2D();
}

string Pnj::getNom() const {
    return nom;
}

string Pnj::getDialogue() const {
    return dialogue;
}

void Pnj::setNom(string nomPNJ) {
    nom=nomPNJ;
}

void Pnj::setDialogue(string dialoguePNJ) {
    dialogue=dialoguePNJ;
}

void Pnj::affichePNJ() {
    cout << "- " << nom << "' " << dialogue <<" ' (" << position.getX() << ", " <<
        position.getY() << ")" << endl;
}

void Pnj::testRegression() {
    cout<<"Tests pour le module Pnj :"<<endl;
    assert(nom == "sansNom");    
    assert(dialogue == "Bonjour !");
    assert(position.getX()==0&&position.getY()==0);
    cout<<"Constructeur par défaut OK ..."<<endl;
    /*Mission mission.Mission();
    Pnj p("Luc", "Comment vas-tu ?", mission, position);
    assert(p.getNom()=="Luc");
    assert(p.getDialogue()=="Comment vas-tu ?");
    assert(p.position.getX()==0&&p.position.getY()==0);
    cout<<"Constructeur par copie OK ..."<<endl;*/
    affichePNJ();
}
