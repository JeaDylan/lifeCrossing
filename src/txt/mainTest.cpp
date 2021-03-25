#include <iostream>
#include "../core/EnsembleFruitLeg.h"
#include "../core/EnsembleMeuble.h"
#include "../core/Jardin.h"
#include "../core/EnsembleTerrain.h"
#include "../core/Personnage.h"
#include "../core/Pnj.h"
#include "../core/Jauge.h"


using namespace std;

int main() {

    Point2D p;
    Meuble m;
    FruitLegume fruit;
    EnsembleFruitLeg ensemble;
    EnsembleMeuble ensembleMeuble;
    EnsembleTerrain ensembleTerrain;
    Jardin jardin;
    Terrain t;
    Personnage perso;
    Pnj PNJ;
    Jauge jauge;
    p.testRegression();
    m.testRegression();
    ensembleMeuble.testRegression();
    fruit.testRegression();
    ensemble.testRegression();
    jardin.testRegression();
    t.testRegression();
    ensembleTerrain.testRegression();
    perso.testRegression();
    PNJ.testRegression();
    jauge.testRegression();
   return 0;
}
