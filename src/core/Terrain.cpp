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
                    terr[i-1][j-1]=meubleChar[0];
                }
                else {
                    terr[i][j]=videChar[0];
                }
            }
        }
    }
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

void Terrain::afficheTerrain() {
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
    EnsembleMeuble ensembleMeuble;
    ensembleMeuble.banqueDeMeubleMaison();
    Terrain maison(10,10,"maison",ensembleMeuble);
    maison.afficheTerrain();
    assert(dimX==15&&dimY==25);
    assert(nom=="nouveauTerrain");
    assert(maison.meublesTerrain.tabMeuble.size()==4);
    assert(maison.getdimX()==10&&maison.getdimY()==10);
    assert(maison.getMeubles().tabMeuble.size()==4);
    afficheTerrain();
    cout<<"test Regression Terrain OK ..."<<endl;
}
