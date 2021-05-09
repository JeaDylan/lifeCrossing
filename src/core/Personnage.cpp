#include <cassert>
#include "Personnage.h"

const char persoChar[3]  = "P";

Personnage::Personnage() {
    nom="sansNom";
    avatar=persoChar[0];
    argent=500;
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
   
}

Personnage::Personnage(string nomP) {
    nom=nomP;
    avatar=persoChar[0];
    argent=0.0;
    position.setX(0);
    position.setY(0);
    vie.setPtsDeVie(100);
    vie.setFaim(0);
    vie.getFaim().setNiveauMax(100);
    vie.setSoif(0);
    vie.getSoif().setNiveauMax(100);
    vie.setFatigue(0);
    vie.getFatigue().setNiveauMax(100);
    niveau.setNiveau(0);
    niveau.setNiveauMax(100);
    xp.setNiveau(0);
    xp.setNiveauMax(100);
  
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

int Personnage::getArgent() const {
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

Vie Personnage::getVie() const{
    return vie;
}

void Personnage::setAvatar(char avatarP) {
    avatar=avatarP;
}

void Personnage::gainArgent(int gain) {
    argent+=gain;
}

void Personnage::perteArgent(int perte) {
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

void Personnage::varieAuto() { 
    if(xp.jaugeRemplie()) {
        int niv = xp.getNiveau()/100;
        int newXP = xp.getNiveau()%100;
        xp.setNiveau(newXP);
        niveau.setNiveau(niveau.getNiveau()+niv);
        cout << xp.getNiveau() << endl;
    }    
}

bool Personnage::possedeFruitLeg(string fruitLeg, string type) const{
    bool b = false;
    int taille = inventaire.inventaireFruitLeg.tabFruitLeg ->size();
    
    for(int i = 0; i<taille; i++){
        string typeI = inventaire.inventaireFruitLeg.tabFruitLeg->at(i).getTypeGraine();
        string nom = inventaire.inventaireFruitLeg.tabFruitLeg->at(i).getNomGraine() ;
        if(nom == fruitLeg && typeI == type ){            
            b = true;
        }
    }
    return b;
}


void Personnage::testRegression(Terrain terrain) {
    cout<<"Tests pour le module Personnage :"<<endl;
    assert(nom == "sansNom");
    assert(avatar == persoChar[0]);
    assert(argent == 500);
    assert(position.getX()==0);
    assert(position.getY()==0);
    assert(niveau.getNiveau()==0);
    assert(niveau.getNiveauMax()==100);
    assert(xp.getNiveau()==0);
    assert(xp.getNiveauMax()==100);
    cout<<"Constructeur par défaut OK ..."<<endl;
    Point2D posPerso(10,10);
    Personnage p=Personnage("Alpha");
    p.gainArgent(150);
    p.perteArgent(50);
    p.bas(terrain);
    p.droite(terrain);
    p.bas(terrain);
    p.droite(terrain);
    p.gauche(terrain);
    p.haut(terrain);
    assert(p.getNom()=="Alpha");
    assert(p.getPosX()==1&&p.getPosY()==1);
    assert(p.getArgent()==100);
    cout<<"Constructeur par copie OK ..."<<endl;
    p.affichePersonnage();

}
