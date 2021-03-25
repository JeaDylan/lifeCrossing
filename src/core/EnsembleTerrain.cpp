#include "EnsembleTerrain.h"
#include <cassert>

using namespace std;

EnsembleTerrain::EnsembleTerrain() {
    tabTerrain.empty();
    terrCourant = new Terrain;
}

EnsembleTerrain::~EnsembleTerrain() {
    tabTerrain.clear();
    tabTerrain.shrink_to_fit();
    delete terrCourant;
    terrCourant = NULL;
}

void EnsembleTerrain::afficheTerrains() {
    cout<<"Voici l'ensemble des terrains du Jeu :"<<endl;
    int taille = tabTerrain.size();
    for(int i=0;i<taille;++i) {
        tabTerrain[i].afficheTerrain();
    }
}

void EnsembleTerrain::banqueDeTerrain() {

    // Création Maison du personnage
    EnsembleMeuble ensembleMeubleMaison;
    ensembleMeubleMaison.banqueDeMeubleMaison();
    Terrain maison(20,15,"maison",ensembleMeubleMaison);
    tabTerrain.push_back(maison);

    // Création Quartier du personnage
    EnsembleMeuble ensembleMeubleQuartier;
    ensembleMeubleQuartier.banqueDeMeubleQuartier();
    Terrain quartier(20,15,"quartier",ensembleMeubleQuartier);
    tabTerrain.push_back(quartier);

}

void EnsembleTerrain::testRegression() {
    cout<<"Tests pour le module EnsembleTerrain :"<<endl;
    assert(tabTerrain.size()==0);
    EnsembleTerrain ensembleTerrain;
    ensembleTerrain.banqueDeTerrain();
    assert(ensembleTerrain.tabTerrain[0].getNom()=="maison");
    assert(ensembleTerrain.tabTerrain[1].getNom()=="quartier");
    //ensembleTerrain.afficheTerrains();
    cout<<"Test Régression EnsembleTerrain OK ..."<<endl;
}
