#include <iostream>
#include "../core/EnsembleFruitLeg.h"
#include "../core/EnsembleMeuble.h"
#include "../core/Jardin.h"
#include "../core/Terrain.h"

using namespace std;

int main() {

    Point2D p;
    Meuble m;
    FruitLegume fruit;
    EnsembleFruitLeg ensemble;
    EnsembleMeuble ensembleMeuble;
    Jardin jardin;
    Terrain t;
    p.testRegression();
    m.testRegression();
    ensembleMeuble.testRegression();
    fruit.testRegression();
    ensemble.testRegression();
    jardin.testRegression();
    t.testRegression();

   return 0;
}
