#include <iostream>
#include "../core/EnsembleFruitLeg.h"
#include "../core/EnsembleMeuble.h"
#include "../core/Jardin.h"
#include "../core/EnsembleTerrain.h"

using namespace std;

int main() {

    Point2D p;
    Meuble m;
    FruitLegume fruit;
    Jardin jardin;
    Terrain t;
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

   return 0;
}
