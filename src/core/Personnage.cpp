#include <cassert>
#include "Personnage.h"

const char persoChar[3]  = "P";

Personnage::Personnage() {
    nom="sansNom";
    avatar=persoChar[0];
    argent=0;
    //vie.Vie();
    position.setX(0);
    position.setY(0);
    //niveau.setNiveau(0);    
    //niveau.setNiveauMax(100);
    //xp.setNiveau(0);
    //xp.setNiveauMax(100);
    //inventaire.Inventaire();
}

Personnage::Personnage(string nomP, unsigned int argentPerso,Point2D positionPerso) {
    nom=nomP;
    avatar=persoChar[0];
    argent=argentPerso;
    position=positionPerso;
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

unsigned int Personnage::getArgent() const {
    return argent;
}

void Personnage::setNom(string nomP) {
    nom=nomP;
}

void Personnage::setAvatar(char avatarP) {
    avatar=avatarP;
}

void Personnage::gainArgent(unsigned int gain) {
    argent+=gain;
}

void Personnage::perteArgent(unsigned int perte) {
    argent-=perte;
}
/*
void Personnage::gauche (const Terrain & t) {
    if (t.estPositionPersoValide(position.getX()-1,position.getY())) position.setX(position.getX()-1);
}

void Personnage::droite (const Terrain & t) {
    if (t.estPositionPersoValide(position.getX()+1,position.getY())) position.setX(position.getX()+1);
}

void Personnage::bas (const Terrain & t) {
    if (t.estPositionPersoValide(position.getX(),position.getY()-1)) position.setY(position.getY()-1);
}

void Personnage::haut (const Terrain & t) {
    if (t.estPositionPersoValide(position.getX(),position.getY()+1)) position.setY(position.getY()+1);
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
*/
void Personnage::affichePersonnage() const {
    cout<<" - " << nom << " : ("<< avatar << "," << argent<<")"<<endl;
}

void Personnage::testRegression() {
    cout<<"Tests pour le module Personnage :"<<endl;
    assert(nom == "sansNom");
    assert(avatar == persoChar[0]);
    assert(argent == 0);
    assert(position.getX()==0);
    assert(position.getY()==0);
    //assert(niveau.niveauActuel==0);    
    //assert(niveau.niveauMax==100);
    //assert(xp.niveauActuel==0);
    //assert(xp.niveauMax==100);
    cout<<"Constructeur par défaut OK ..."<<endl;
    Point2D posPerso(10,10);
    Personnage p("Alpha", 100,posPerso);
    assert(p.getNom()=="Alpha");
    //assert(p.getAvatar()=="P");
    assert(p.position.getX()==10&&p.position.getY()==10);
    assert(p.getArgent()==100);
    cout<<"Constructeur par copie OK ..."<<endl;
    p.affichePersonnage();
}
