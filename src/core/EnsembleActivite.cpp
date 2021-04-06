#include "EnsembleActivite.h"
#include <cassert>


EnsembleActivite::EnsembleActivite(){
    tabActivite.empty();
}

EnsembleActivite::~EnsembleActivite() {
    tabActivite.clear();
    tabActivite.shrink_to_fit ();
}

void EnsembleActivite::ajouterActivite(const Activite & Activite) {
    tabActivite.push_back(Activite);
}

void EnsembleActivite::suppActivite(string nomActivite) {
    int taille = tabActivite.size();
    for(int i = 0; i < taille ; i++){
        if(nomActivite == tabActivite[i].getNom()) {
                tabActivite.erase(tabActivite.begin() + i);
    
        }
    }
}

void EnsembleActivite::afficheListeActivite()const {
    cout << "Activites et leurs dimensions : " <<endl;
    int taille = tabActivite.size();
    for(int i = 0; i < taille; i++){
        tabActivite[i].afficheActivite();
    }
}

EnsembleActivite EnsembleActivite::operator= (const EnsembleActivite & copieActivites) {
    tabActivite = copieActivites.tabActivite;
    return *this;
}

void EnsembleActivite::banqueDeActivite() {
    // Création d'une table de Activite
    Point2D Activitep1(10,4);
    Point2D Activitep2(10,9);
    Activite Activite1("Pêche", 100, Activitep1, 10, "bananes");
    Activite Activite2("Tir à l'arc", 20, Activitep2, 10, "points de vie");
    tabActivite.push_back(Activite1);
    tabActivite.push_back(Activite2);
}

void EnsembleActivite::testRegression() {
   cout<<"Tests pour le module EnsembleActivite :"<<endl;
   EnsembleActivite test;
   EnsembleActivite testBanque;
   assert(test.tabActivite.size() == 0);
   cout<<"Constructeur par Défaut OK ..."<<endl;

   //création d'un Activite
   Point2D ActivitePoints1(0,1);
   Point2D ActivitePoints2(1,1);
   Activite Activite1("Pêche", 100, ActivitePoints1, 10, "bananes");
   Activite Activite2("Tir à l'arc", 20, ActivitePoints2, 10, "points de vie");
   assert(Activite1.getNom()=="Pêche"&&Activite2.getNom()=="Tir à l'arc");
   assert(Activite1.getPrix()==100&&Activite2.getPrix()==20);
   assert(Activite1.getPosition().getX()==0&&Activite1.getPosition().getY()==1);
   assert(Activite2.getPosition().getX()==1&&Activite2.getPosition().getY()==1);
   assert(Activite1.getRecompense()==10&&Activite2.getRecompense()==10);
   assert(Activite1.getTypeRecompense()=="bananes"&&Activite2.getTypeRecompense()=="points de vie");
   Activite1.afficheActivite();
   Activite2.afficheActivite();
   cout<<"Constructeur par copie OK ..."<<endl;
   test.ajouterActivite(Activite1);
   test.ajouterActivite(Activite2);
   assert(test.tabActivite.size() == 2);
   assert(test.tabActivite[0].getNom() == "Pêche");
   assert(test.tabActivite[1].getNom() == "Tir à l'arc");
   test.suppActivite("Pêche");
   assert(test.tabActivite.size()==1);
   test.tabActivite[0].afficheActivite();
   cout<<"Suppression OK ..."<<endl;
   testBanque.banqueDeActivite();
   assert(testBanque.tabActivite.size()==2);
   test.afficheListeActivite();
   cout<<"Test Regression EnsembleActivite OK ..."<<endl;

}
