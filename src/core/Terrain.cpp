#include "Terrain.h"
#include <cassert>

using namespace std;

const char videChar[2] = ".";
const char meubleChar[2] = "x";

Terrain::Terrain() {
    dimX=15;
    dimY=25;
    nom="nouveauTerrain";
    for(unsigned int i=0;i<dimX;i++) {
        for(unsigned int j=0;j<dimY;j++) {
            terr[i][j]=videChar[0];
        }
    }
}

Terrain::~Terrain(){
    dimX=0;
    dimY=0;
    nom="";
}

Terrain::Terrain(unsigned int x, unsigned int y, string nomTerrain,
EnsembleMeuble meubles) {
    dimX=x;
    dimY=y;
    nom=nomTerrain;
    meubles.afficheListeMeuble();
    for(unsigned int i=0;i<dimX;i++) {
        for(unsigned int j=0;j<dimY;j++) {
            for(unsigned int k=0;k<meubles.tabMeuble.size();k++){
                if(i==meubles.tabMeuble[k].getDimension().getX()&&j==meubles.tabMeuble[k].getDimension().getY()) {
                    terr[i][j]=meubleChar[0];
                    break;
                }
                else {
                    terr[i][j]=videChar[0];
                } 
            }
        }
    }
    // Stockage de la banqueDeMeuble pour fonctionnalitées du Jeu
    meublesTerrain=meubles;
}

unsigned int Terrain::getdimX () const {
    return dimX;
}

unsigned int Terrain::getdimY () const {
    return dimX;
}

EnsembleMeuble Terrain::getMeubles () const {
    return meublesTerrain;
}

string Terrain::getNom () const {
    return nom;
}

char Terrain::getXY (const unsigned int x, const unsigned int y) const {
    assert(x>=0);
	assert(y>=0);
	assert(x<dimX);
	assert(y<dimY);
	return terr[x][y];
}

void Terrain::afficheTerrain() {
    cout<<"Voici le terrain "<<nom<<" : "<<endl;
    for(unsigned int i=0;i<dimX;i++) {
        for(unsigned int j=0;j<dimY;j++) {
            cout<<terr[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}

void Terrain::testRegression() {
    cout<<"Tests pour le module Terrain :"<<endl;
    EnsembleMeuble ensembleMeubleMaison;
    ensembleMeubleMaison.banqueDeMeubleMaison();
    Terrain maison(10,10,"maison",ensembleMeubleMaison);
    maison.afficheTerrain();
    assert(dimX==15&&dimY==25);
    assert(nom=="nouveauTerrain");
    assert(maison.meublesTerrain.tabMeuble.size()==4);
    assert(maison.getdimX()==10&&maison.getdimY()==10);
    assert(maison.getMeubles().tabMeuble.size()==4);
    assert(maison.getNom()=="maison");
    assert(maison.getXY(3,3)==meubleChar[0]);
    afficheTerrain();
    cout<<"test Regression Terrain OK ..."<<endl;
    EnsembleMeuble ensembleMeubleQuartier;
    ensembleMeubleQuartier.banqueDeMeubleQuartier();
    Terrain quartier(20,15,"quartier",ensembleMeubleQuartier);
    quartier.afficheTerrain();
}
