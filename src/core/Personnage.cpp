#include <cassert>
#include "Personnage.h"

const char persoChar[3]  = "P";

Personnage::Personnage() {
    nom="sansNom";
    avatar=persoChar[0];
    argent=200;
    position.setX(0);
    position.setY(0);
    vie.setPtsDeVie(100);
    vie.setFaim(0);
    vie.setSoif(0);
    vie.setFatigue(0);
    niveau.setNiveau(0);
    niveau.setNiveauMax(100);
    xp.setNiveau(0);
    xp.setNiveauMax(100);
    inventaire=Inventaire();
}

Personnage::Personnage(string nomP) {
    nom=nomP;
    avatar=persoChar[0];
    argent=0.0;
    position.setX(0);
    position.setY(0);
    vie.setPtsDeVie(100);
    vie.setFaim(0);
    vie.setSoif(0);
    vie.setFatigue(0);
    niveau.setNiveau(0);
    niveau.setNiveauMax(100);
    xp.setNiveau(0);
    xp.setNiveauMax(100);
    inventaire=Inventaire();
}

Personnage::~Personnage() {
    nom="sansNom";
}

string Personnage::getNom() const {
    return nom;
}

char Personnage::getAvatar() const {
    return avatar;
}

float Personnage::getArgent() const {
    return argent;
}

unsigned int Personnage::getPosX() const {
    return position.getX();
}

unsigned int Personnage::getPosY() const {
    return position.getY();
}

void Personnage::setNom(string nomP) {
    nom=nomP;
}

void Personnage::setAvatar(char avatarP) {
    avatar=avatarP;
}

void Personnage::gainArgent(float gain) {
    argent+=gain;
}

void Personnage::perteArgent(float perte) {
    argent-=perte;
}

void Personnage::setPosX(unsigned int posX) {
    position.setX(posX);
}

void Personnage::setPosY(unsigned int posY) {
    position.setY(posY);
}


void Personnage::gauche (Terrain &t) {
    if (t.estPositionPersoValide(getPosX(),getPosY()-1)) setPosY(getPosY()-1);
}

void Personnage::droite (Terrain &t) {
    if (t.estPositionPersoValide(getPosX(),getPosY()+1)) setPosY(getPosY()+1);
}

void Personnage::bas (Terrain &t) {
    if (t.estPositionPersoValide(getPosX()-1,getPosY())) setPosX(getPosX()-1);
}

void Personnage::haut (Terrain &t) {
    if (t.estPositionPersoValide(getPosX()+1,getPosY())) setPosX(getPosX()+1);
}

bool Personnage::choixActivite (Terrain terrain) const {
    return false;
}

bool Personnage::choixDiscuterPnj (Terrain terrain) const {
    return false;
}

bool Personnage::choixAcheterMarche (Terrain terrain) const {
    return false;
}

void Personnage::affichePersonnage() const {
    cout<<" - " << nom << " : ("<< avatar << "," << argent<<")"<<endl;
    cout<< "Il se situe à la case ("<<position.getX()<<", " << position.getY() <<"), et possède " << argent <<"€"<<endl;
}

void Personnage::testRegression(Terrain terrain) {
    cout<<"Tests pour le module Personnage :"<<endl;
    assert(nom == "sansNom");
    assert(avatar == persoChar[0]);
    assert(argent == 200);
    assert(position.getX()==0);
    assert(position.getY()==0);
    assert(niveau.getNiveau()==0);
    assert(niveau.getNiveauMax()==100);
    assert(xp.getNiveau()==0);
    assert(xp.getNiveauMax()==100);
    cout<<"Constructeur par défaut OK ..."<<endl;
    Point2D posPerso(10,10);
    Personnage p=Personnage("Alpha");
    p.gainArgent(150.0);
    p.perteArgent(50.0);
    p.bas(terrain);
    p.droite(terrain);
    p.bas(terrain);
    p.droite(terrain);
    p.gauche(terrain);
    p.haut(terrain);
    assert(p.getNom()=="Alpha");
    assert(p.getPosX()==1&&p.getPosY()==1);
    assert(p.getArgent()==100.0);
    cout<<"Constructeur par copie OK ..."<<endl;
    p.affichePersonnage();

}
