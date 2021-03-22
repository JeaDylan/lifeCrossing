#ifndef _ENSEMBLE_JARDIN
#define _ENSEMBLE_JARDIN
#include "Jardin.h"

#include <vector>
#include <ctime>
#include <iostream>
using namespace std;



class EnsembleJardin{
private:
    vector<Jardin> * tabJardin;
    unsigned int dimX;
    unsigned int dimY;
    Point2D position;
    EnsembleFruitLeg banqueFruitLeg;
    
public:
    EnsembleJardin();

    ~EnsembleJardin();

    unsigned int getDimX();

    unsigned int getDimY();

    void setDimX(unsigned int dx);

    void setDimY(unsigned int dy);

    void addJardin(unsigned int nx, unsigned int ny);

    void suppJardin(unsigned int nx, unsigned int ny);

    bool planter(string nomGraine);


}


#endif