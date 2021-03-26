#include <cassert>
#include "Personnage.h"

const char persoChar[3]  = "P";

Personnage::Personnage() {
    nom="sansNom";
    avatar=persoChar[0];
    argent=0.0;
    //vie.Vie();
    position.setX(0);
    position.setY(0);
    //niveau.setNiveau(0);    
    //niveau.setNiveauMax(100);
    //xp.setNiveau(0);
    //xp.setNiveauMax(100);
    //inventaire.Inventaire();
}

Personnage::Personnage(string nomP, float argentPerso,Point2D positionPerso) {
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
