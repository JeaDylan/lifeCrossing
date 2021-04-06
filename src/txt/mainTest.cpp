#include <iostream>
#include "../core/EnsembleFruitLeg.h"
#include "../core/EnsembleMeuble.h"
#include "../core/Jardin.h"
#include "../core/EnsembleTerrain.h"
#include "../core/Personnage.h"
#include "../core/EnsemblePnj.h"
#include "../core/Jauge.h"
#include "../core/EnsembleActivite.h"


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
    EnsemblePnj ensemblePNJ;
    Activite a;
    EnsembleActivite ensembleActivite;
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
    ensemblePNJ.testRegression();
    jauge.testRegression();
    a.testRegression();
    ensembleActivite.testRegression();
   return 0;
}
