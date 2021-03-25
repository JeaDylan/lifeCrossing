#ifndef _ENSEMBLE_MISSION
#define _ENSEMBLE_MISSION

#include "Mission.h"
#include <vector>
#include <iostream>

using namespace std;


class EnsembleMission {
public:
    vector<Mission> * tabMission;

    EnsembleMission();

    ~EnsembleMission();

    void ajouterMission(const Mission & mission);

    void suppMission(unsigned int nuM);

    bool declencheMission(unsigned int nuM);

    void banqueMission();

    Mission chercherMision(unsigned int nuM);

    bool mission_1();

    bool mission_2();

    bool mission_3();

};

#endif //_ENSEMBLE_MISSION