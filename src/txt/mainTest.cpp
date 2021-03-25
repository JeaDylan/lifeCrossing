#include <iostream>
#include "../core/EnsembleFruitLeg.h"
#include "../core/EnsembleMeuble.h"
#include "../core/Jardin.h"
#include "../core/EnsembleTerrain.h"
#include "../core/Personnage.h"

using namespace std;

int main() {

    Point2D p;
    Meuble m;
    FruitLegume fruit;
    Jardin jardin;
    Terrain t;
    Personnage perso;
    EnsembleFruitLeg ensembleFruitLeg;
    EnsembleMeuble ensembleMeuble;
    EnsembleTerrain ensembleTerrain;

    p.testRegression();
    m.testRegression();
    ensembleMeuble.testRegression();
    fruit.testRegression();
    ensembleFruitLeg.testRegression();
    jardin.testRegression();
    t.testRegression();
    ensembleTerrain.testRegression();
    perso.testRegression();

   return 0;
}
