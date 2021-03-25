#include "EnsembleMission.h"



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


void EnsembleMission::suppMission(unsigned int nuM){
    int taille = tabMission->size();
    for(int i=0; i<taille;i++){
        if(nuM == (*tabMission)[i].getNum()){
            tabMission->erase(tabMission->begin() + i);
        }
    }
}

Mission EnsembleMission::chercherMission(unsigned int nuM){
    int taille = tabMission->size();
    for(int i=0; i<taille;i++){
        if(nuM == (*tabMission).getNum()){
            return (*tabMission)[i];
        }
    }
    cout<<"Error : la mission n'existe pas "<<endl;
    exit(0);

}


bool EnsembleMission::declencheMission(unsigned int nuM){
      bool etat;
      Mission active = chercherMision(nuM);
      assert(active.getDeclenche() == false);
      active.setDeclenche(true);
      assert(active.getFini() == false);
      active.(*pfm)(); //declenche la fonction de la mission
      while(active.getFini() == false){
          sleep(1);
          etat = false;
      }
      assert(active.getFini()==true);
      etat = true;
      active.setDeclenche(false); //on remet les valeurs par defaut
      active.setFini(false);
      return etat;

}


