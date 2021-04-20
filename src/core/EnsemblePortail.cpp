#include "EnsemblePortail.h"
#include <cassert>


EnsemblePortail::EnsemblePortail(){
    tabPortail.empty();
}

EnsemblePortail::~EnsemblePortail() {
    tabPortail.clear();
    tabPortail.shrink_to_fit ();
}

void EnsemblePortail::ajouterPortail(const Portail & Portail) {
    tabPortail.push_back(Portail);
}

void EnsemblePortail::suppPortail(string nomPortail) {
    int taille = tabPortail.size();
    for(int i = 0; i < taille ; i++){
        if(nomPortail == tabPortail[i].getNomPortail()) {
                tabPortail.erase(tabPortail.begin() + i);
    
        }
    }
}

void EnsemblePortail::afficheListePortail()const {
    cout << "Portails et leurs positions : " <<endl;
    int taille = tabPortail.size();
    for(int i = 0; i < taille; i++){
        tabPortail[i].affichePortail();
    }
}

EnsemblePortail EnsemblePortail::operator= (const EnsemblePortail & copiePortails) {
    tabPortail = copiePortails.tabPortail;
    return *this;
}

void EnsemblePortail::banqueDePortailQuartierFichier (string nom_fichier)
    {
        int i,taille ;
        ifstream monFichier (nom_fichier) ;
        Portail vide;
        if (monFichier.is_open())
        {
            monFichier >> taille  ;
        for (i=0 ;i<taille ;i++)
        {
            tabPortail.push_back(vide);
            monFichier >> tabPortail[i].position.x >> tabPortail[i].position.y >> tabPortail[i].nom; 
        }
        } 
        else cout <<" le fichier n'est pas ouvert "<<endl;
        monFichier.close() ;
    }


void EnsemblePortail::testRegression() {
   cout<<"Tests pour le module EnsemblePortail :"<<endl;
   EnsemblePortail test;
   EnsemblePortail testBanque;
   EnsemblePortail testBanqueF;
   assert(test.tabPortail.size() == 0);
   cout<<"Constructeur par Défaut OK ..."<<endl;

   //création d'un Portail
   Point2D tablePoints1(0,1);
   Point2D tablePoints2(1,1);
   Portail table1("table1",tablePoints1);
   Portail table2("table2",tablePoints2);
   assert(table1.getNomPortail()=="table1"&&table2.getNomPortail()=="table2");
   assert(table1.getPosition().getX()==0&&table1.getPosition().getY()==1);
   assert(table2.getPosition().getX()==1&&table2.getPosition().getY()==1);
   table1.affichePortail();
   table2.affichePortail();
   cout<<"Constructeur par copie OK ..."<<endl;
   test.ajouterPortail(table1);
   test.ajouterPortail(table2);
   assert(test.tabPortail.size() == 2);
   assert(test.tabPortail[0].getNomPortail() == "table1");
   assert(test.tabPortail[1].getNomPortail() == "table2");
   test.suppPortail("table1");
   assert(test.tabPortail.size()==1);
   test.tabPortail[0].affichePortail();
   cout<<"Suppression OK ..."<<endl;
   test.afficheListePortail();
   testBanqueF.banqueDePortailQuartierFichier("./data/banquePortailQuartier.txt");
   testBanqueF.afficheListePortail();
   cout<<"Test Regression EnsemblePortail OK ..."<<endl;

}
