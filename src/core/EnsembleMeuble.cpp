#include "EnsembleMeuble.h"
#include <cassert>


EnsembleMeuble::EnsembleMeuble(){
    tabMeuble.empty();
}

EnsembleMeuble::~EnsembleMeuble() {
    tabMeuble.clear();
    tabMeuble.shrink_to_fit ();
}

void EnsembleMeuble::ajouterMeuble(const Meuble & meuble) {
    tabMeuble.push_back(meuble);
}

void EnsembleMeuble::suppMeuble(string nomMeuble) {
    int taille = tabMeuble.size();
    for(int i = 0; i < taille ; i++){
        if(nomMeuble == tabMeuble[i].getNomMeuble()) {
                tabMeuble.erase(tabMeuble.begin() + i);
    
        }
    }
}

void EnsembleMeuble::afficheListeMeuble()const {
    cout << "Meubles et leurs dimensions : " <<endl;
    int taille = tabMeuble.size();
    for(int i = 0; i < taille; i++){
        tabMeuble[i].afficheMeuble();
    }
}

EnsembleMeuble EnsembleMeuble::operator= (const EnsembleMeuble & copieMeubles) {
    tabMeuble = copieMeubles.tabMeuble;
    return *this;
}

void EnsembleMeuble::banqueDeMeubleMaison() {
    // Création d'une table dans la Maison
    Point2D table1MaisonP(3,3);
    Point2D table2MaisonP(3,4);
    Point2D table3MaisonP(4,3);
    Point2D table4MaisonP(4,4);
    Meuble table1Maison("table1Maison",table1MaisonP);
    Meuble table2Maison("table2Maison",table2MaisonP);
    Meuble table3Maison("table3Maison",table3MaisonP);
    Meuble table4Maison("table4Maison",table4MaisonP);
    tabMeuble.push_back(table1Maison);
    tabMeuble.push_back(table2Maison);
    tabMeuble.push_back(table3Maison);
    tabMeuble.push_back(table4Maison);
}

void EnsembleMeuble::banqueDeMeubleQuartier() {
    // Création des Maisons du Quartier du Personnage
    Point2D maison1P1(1,1);
    Point2D maison1P2(1,2);
    Point2D maison1P3(2,1);
    Point2D maison1P4(2,2);

    Point2D maison2P1(5,1);
    Point2D maison2P2(5,2);
    Point2D maison2P3(6,1);
    Point2D maison2P4(6,2);

    Point2D maison3P1(9,1);
    Point2D maison3P2(9,2);
    Point2D maison3P3(10,1);
    Point2D maison3P4(10,2);

    Meuble maison1_1("maison1_1",maison1P1);
    Meuble maison1_2("maison1_2",maison1P2);
    Meuble maison1_3("maison1_3",maison1P3);
    Meuble maison1_4("maison1_4",maison1P4);

    Meuble maison2_1("maison2_1",maison2P1);
    Meuble maison2_2("maison2_2",maison2P2);
    Meuble maison2_3("maison2_3",maison2P3);
    Meuble maison2_4("maison2_4",maison2P4);

    Meuble maison3_1("maison3_1",maison3P1);
    Meuble maison3_2("maison3_2",maison3P2);
    Meuble maison3_3("maison3_3",maison3P3);
    Meuble maison3_4("maison3_4",maison3P4);

    tabMeuble.push_back(maison1_1);
    tabMeuble.push_back(maison1_2);
    tabMeuble.push_back(maison1_3);
    tabMeuble.push_back(maison1_4);

    tabMeuble.push_back(maison2_1);
    tabMeuble.push_back(maison2_2);
    tabMeuble.push_back(maison2_3);
    tabMeuble.push_back(maison2_4);

    tabMeuble.push_back(maison3_1);
    tabMeuble.push_back(maison3_2);
    tabMeuble.push_back(maison3_3);
    tabMeuble.push_back(maison3_4);

}

void EnsembleMeuble::banqueDeMeubleFichier (string nom_fichier)
    {
        int i,taille ;
        ifstream monFichier (nom_fichier) ;
        Meuble vide;
        if (monFichier.is_open())
        {
            monFichier >> taille  ;
        for (i=0 ;i<taille ;i++)
        {
            tabMeuble.push_back(vide);
            monFichier >> tabMeuble[i].dimension.x >> tabMeuble[i].dimension.y >> tabMeuble[i].nom; 
        }
        } 
        else cout <<" le fichier n'est pas ouvert "<<endl;
        monFichier.close() ;
    }


void EnsembleMeuble::testRegression() {
   cout<<"Tests pour le module EnsembleMeuble :"<<endl;
   EnsembleMeuble test;
   EnsembleMeuble testBanque;
   EnsembleMeuble testBanqueF;
   assert(test.tabMeuble.size() == 0);
   cout<<"Constructeur par Défaut OK ..."<<endl;

   //création d'un meuble
   Point2D tablePoints1(0,1);
   Point2D tablePoints2(1,1);
   Meuble table1("table1",tablePoints1);
   Meuble table2("table2",tablePoints2);
   assert(table1.getNomMeuble()=="table1"&&table2.getNomMeuble()=="table2");
   assert(table1.getDimension().getX()==0&&table1.getDimension().getY()==1);
   assert(table2.getDimension().getX()==1&&table2.getDimension().getY()==1);
   table1.afficheMeuble();
   table2.afficheMeuble();
   cout<<"Constructeur par copie OK ..."<<endl;
   test.ajouterMeuble(table1);
   test.ajouterMeuble(table2);
   assert(test.tabMeuble.size() == 2);
   assert(test.tabMeuble[0].getNomMeuble() == "table1");
   assert(test.tabMeuble[1].getNomMeuble() == "table2");
   test.suppMeuble("table1");
   assert(test.tabMeuble.size()==1);
   test.tabMeuble[0].afficheMeuble();
   cout<<"Suppression OK ..."<<endl;
   testBanque.banqueDeMeubleMaison();
   assert(testBanque.tabMeuble.size()==4);
   test.afficheListeMeuble();
   testBanqueF.banqueDeMeubleFichier("./data/banqueMeubleQuartier.txt");
   testBanqueF.afficheListeMeuble();
   cout<<"Test Regression EnsembleMeuble OK ..."<<endl;

}
