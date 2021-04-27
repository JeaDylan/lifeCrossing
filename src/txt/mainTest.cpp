#include <iostream>
#include "../core/EnsembleFruitLeg.h"
#include "../core/EnsembleMeuble.h"
#include "../core/Jardin.h"
#include "../core/EnsembleTerrain.h"
#include "../core/Personnage.h"
#include "../core/EnsemblePnj.h"
#include "../core/Jauge.h"
#include "../core/EnsembleActivite.h"
#include "../core/Inventaire.h"
#include "../core/EnsemblePortail.h"
#include "../core/EnsembleMission.h"


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
    Portail portail;
    EnsemblePortail portails;
    Mission mission;
    EnsembleMission missions;
    p.testRegression();
    m.testRegression();
    ensembleMeuble.testRegression();
    fruit.testRegression();
    ensemble.testRegression();
    jardin.testRegression();
    t.testRegression();
    ensembleTerrain.testRegression();
    perso.testRegression(t);
    PNJ.testRegression();
    ensemblePNJ.testRegression();
    jauge.testRegression();
    a.testRegression();
    ensembleActivite.testRegression();
    portail.testRegression();
    portails.testRegression();
    mission.testRegression();
    missions.testRegression();

   return 0;
}
