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
const EnsembleMeuble& meubles,const EnsemblePortail& portails) {
    dimX=x;
    dimY=y;
    nom=nomTerrain;
    for(unsigned int i=0;i<dimX;i++) {
        for(unsigned int j=0;j<dimY;j++) {
            for(unsigned int k=0;k<meubles.tabMeuble.size();k++){
                if(i==meubles.tabMeuble[k].dimension.x&&j==meubles.tabMeuble[k].dimension.y) {
                    terr[i][j]=meubleChar[0];
                    break;
                }
                else {
                    terr[i][j]=videChar[0];
                }
            }
        }
    }
    meublesTerrain=meubles;
    portailsTerrain=portails;
}

bool Terrain::estPositionPersoValide (unsigned int x,unsigned int y){
	return (x>=0 && x<dimX && y>=0 && y<dimY && terr[x][y]!='x');
}

unsigned int Terrain::getdimX () const {
    return dimX;
}

unsigned int Terrain::getdimY () const {
    return dimX;
}

void Terrain::setChar(unsigned int x,unsigned int y,char symbole){
            terr[x][y] = symbole;
}

EnsembleMeuble Terrain::getMeubles () const {
    return meublesTerrain;
}

EnsemblePortail Terrain::getPortails () const {
    return portailsTerrain;
}

string Terrain::getNom () const {
    return nom;
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

char Terrain::getXY (unsigned int x,unsigned int y) const {
	assert(x>=0);
	assert(y>=0);
	//assert(x<dimX);
	//assert(y<dimY);
	return terr[y][x];
}

void Terrain::testRegression() {
    cout<<"Tests pour le module Terrain :"<<endl;
    EnsembleMeuble ensembleMeuble;
    EnsemblePortail ensemblePortail;
    ensembleMeuble.banqueDeMeubleMaison();
    Terrain maison(10,10,"maison",ensembleMeuble,ensemblePortail);
    maison.afficheTerrain();
    assert(dimX==15&&dimY==25);
    assert(nom=="nouveauTerrain");
    assert(maison.meublesTerrain.tabMeuble.size()==4);
    assert(maison.getdimX()==10&&maison.getdimY()==10);
    assert(maison.getMeubles().tabMeuble.size()==4);
    afficheTerrain();
    assert(maison.estPositionPersoValide(0,0));
    assert(maison.estPositionPersoValide(4,4)==false);
    cout<<"test Regression Terrain OK ..."<<endl;
}
