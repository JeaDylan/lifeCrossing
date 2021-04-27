#include "EnsembleTerrain.h"
#include "EnsemblePortail.h"
#include "EnsembleJardin.h"
#include "EnsembleActivite.h"
#include <cassert>

using namespace std;

EnsembleTerrain::EnsembleTerrain() {
    tabTerrain.empty();
}

EnsembleTerrain::~EnsembleTerrain() {
    tabTerrain.clear();
    tabTerrain.shrink_to_fit();
}

void EnsembleTerrain::afficheTerrains() {
    cout<<"Voici l'ensemble des terrains du Jeu :"<<endl;
    int taille = tabTerrain.size();
    for(int i=0;i<taille;++i) {
        tabTerrain[i].afficheTerrain();
    }
}

void EnsembleTerrain::banqueDeTerrain() {

    // Création des Portails
    EnsemblePortail ensemblePortailQuartier;
    EnsemblePortail ensemblePortailMaison;
    ensemblePortailQuartier.banqueDePortailQuartierFichier
    ("./data/banquePortailQuartier.txt");
    ensemblePortailMaison.banqueDePortailQuartierFichier
    ("./data/banquePortailMaison.txt");

    // Création Maison du personnage
    EnsembleMeuble ensembleMeubleMaison;
    ensembleMeubleMaison.banqueDeMeubleFichier
    ("./data/banqueMeubleMaison.txt");
    Terrain maison
    (20,20,"maison",ensembleMeubleMaison,ensemblePortailMaison);
    tabTerrain.push_back(maison);

    // Création Quartier du personnage
    EnsembleMeuble ensembleMeubleQuartier;
    ensembleMeubleQuartier.banqueDeMeubleFichier
    ("./data/banqueMeubleQuartier.txt");
    Terrain quartier
    (20,20,"quartier",ensembleMeubleQuartier,ensemblePortailQuartier);
    tabTerrain.push_back(quartier);

    // ajout Portails
    tabTerrain[0].setChar
    (ensemblePortailMaison.tabPortail[0].getPosition().x
    ,ensemblePortailMaison.tabPortail[0].getPosition().y,'e');
    tabTerrain[1].setChar
    (ensemblePortailQuartier.tabPortail[0].getPosition().x
    ,ensemblePortailQuartier.tabPortail[0].getPosition().y,'e');

    // ajout Jardin
    tabTerrain[1].setChar(1,3,'j');
    tabTerrain[1].setChar(2,3,'j');
    tabTerrain[1].setChar(1,2,'j');
    tabTerrain[1].setChar(2,2,'j');

    // ajout Activites
    tabTerrain[1].setChar(7,14,'a');

    // ajout PNJ
    tabTerrain[1].setChar(7,12,'i');
    tabTerrain[1].setChar(15,6,'i');

    // ajout Activités
    tabTerrain[1].setChar(7,14,'a');

    // ajout Commerce
    tabTerrain[1].setChar(15,4,'c');

    // ajout 'manger'
    tabTerrain[0].setChar(4,4,'n');

    // ajout 'dormir'
    tabTerrain[0].setChar(7,5,'d');    

    terrCourant = tabTerrain[0];
}

void EnsembleTerrain::testRegression() {
    cout<<"Tests pour le module EnsembleTerrain :"<<endl;
    assert(tabTerrain.size()==0);
    EnsembleTerrain ensembleTerrain;
    ensembleTerrain.banqueDeTerrain();
    assert(ensembleTerrain.tabTerrain[0].getNom()=="maison");
    assert(ensembleTerrain.tabTerrain[1].getNom()=="quartier");
    ensembleTerrain.afficheTerrains();
    cout<<"Test Régression EnsembleTerrain OK ..."<<endl;
}
