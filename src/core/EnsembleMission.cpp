#include "EnsembleMission.h"
#include <cassert>



EnsembleMission::EnsembleMission(){
    tabMission = new vector<Mission>;
}

EnsembleMission::~EnsembleMission(){
    tabMission->clear();
    tabMission->shrink_to_fit ();
    delete tabMission;
    tabMission = NULL;  
}


void EnsembleMission::ajouterMission(const Mission & mission){
    tabMission->push_back(mission);
}

void EnsembleMission::banqueMission() {
    ajouterMission(Mission(2,"Remplir stock Fruit/Leg")); 
}

void EnsembleMission::testRegression() {
   cout<<"Tests pour le module EnsembleMission :"<<endl;
   EnsembleMission test;
   assert(test.tabMission->size() == 0);
   cout<<"Constructeur par Défaut OK ..."<<endl;
   test.banqueMission();
   assert(test.tabMission->size() == 1);
   assert(test.tabMission->at(0).getObjectif() == "Remplir stock Fruit/Leg");
   assert(test.tabMission->at(0).getRecompense() == 2);
   cout<<"Test Regression EnsembleActivite OK ..."<<endl;
}

