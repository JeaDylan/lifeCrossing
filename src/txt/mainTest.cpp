#include <iostream>
#include "../core/Meuble.h"
#include "../core/EnsembleFruitLeg.h"
#include "../core/Jardin.h"

using namespace std;

int main() {

    Point2D p;
    Meuble m;
    FruitLegume fruit;
    EnsembleFruitLeg ensemble;
    Jardin jardin;
    p.testRegression();
    m.testRegression();
    fruit.testRegression();
    ensemble.testRegression();
    jardin.testRegression();

   return 0;
}
