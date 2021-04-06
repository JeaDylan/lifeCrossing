#include "EnsemblePnj.h"
#include <cassert>


EnsemblePnj::EnsemblePnj(){
    tabPnj.empty();
}

EnsemblePnj::~EnsemblePnj() {
    tabPnj.clear();
    tabPnj.shrink_to_fit ();
}

void EnsemblePnj::ajouterPnj(const Pnj & Pnj) {
    tabPnj.push_back(Pnj);
}

void EnsemblePnj::suppPnj(string nomPnj) {
    int taille = tabPnj.size();
    for(int i = 0; i < taille ; i++){
        if(nomPnj == tabPnj[i].getNom()) {
                tabPnj.erase(tabPnj.begin() + i);
    
        }
    }
}

void EnsemblePnj::afficheListePnj()const {
    cout << "Pnjs et leurs positions : " <<endl;
    int taille = tabPnj.size();
    for(int i = 0; i < taille; i++){
        tabPnj[i].affichePNJ();
    }
}

EnsemblePnj EnsemblePnj::operator= (const EnsemblePnj & copiePnjs) {
    tabPnj = copiePnjs.tabPnj;
    return *this;
}

void EnsemblePnj::banqueDePnj() {
    // Création d'une table de PNJ
    Point2D PNJp1(10,3);
    //Mission Mission1;
    Point2D PNJp2(10,8);
    //Mission Mission2;
    Pnj PNJ1("Jean-Eudes", "Salut à toi jeune entrepreneur"/*, Mission1*/, PNJp1);
    Pnj PNJ2("Lucas", "Enchanté"/*, Mission2*/, PNJp2);
    tabPnj.push_back(PNJ1);
    tabPnj.push_back(PNJ2);
}

void EnsemblePnj::testRegression() {
   cout<<"Tests pour le module EnsemblePnj :"<<endl;
   EnsemblePnj test;
   EnsemblePnj testBanque;
   assert(test.tabPnj.size() == 0);
   cout<<"Constructeur par Défaut OK ..."<<endl;

   //création d'un Pnj
   Point2D PNJPoints1(0,1);
   Point2D PNJPoints2(1,1);
   //Mission Mission1;
   //Mission Mission2;
   Pnj PNJ1("PNJ1","Bonjour"/*, Mission1*/, PNJPoints1);
   Pnj PNJ2("PNJ2","Au Revoir"/*, Mission2*/,PNJPoints2);
   assert(PNJ1.getNom()=="PNJ1"&&PNJ2.getNom()=="PNJ2");
   assert(PNJ1.getPosition().getX()==0&&PNJ1.getPosition().getY()==1);
   assert(PNJ2.getPosition().getX()==1&&PNJ2.getPosition().getY()==1);
   assert(PNJ1.getDialogue()=="Bonjour"&&PNJ2.getDialogue()=="Au Revoir");
   //assert(PNJ1.getMission()==Mission1&&PNJ2.getMission()==Mission2);
   PNJ1.affichePNJ();
   PNJ2.affichePNJ();
   cout<<"Constructeur par copie OK ..."<<endl;
   test.ajouterPnj(PNJ1);
   test.ajouterPnj(PNJ2);
   assert(test.tabPnj.size() == 2);
   assert(test.tabPnj[0].getNom() == "PNJ1");
   assert(test.tabPnj[1].getNom() == "PNJ2");
   test.suppPnj("PNJ1");
   assert(test.tabPnj.size()==1);
   test.tabPnj[0].affichePNJ();
   cout<<"Suppression OK ..."<<endl;
   testBanque.banqueDePnj();
   assert(testBanque.tabPnj.size()==2);
   test.afficheListePnj();
   cout<<"Test Regression EnsemblePnj OK ..."<<endl;

}
