#include <cassert>
#include "Mission.h"

Mission::Mission(){
    recompense = 0;
    objectif ="INVALID";
    fini = false;
}

Mission::Mission(int newRecompense, string obj){
    recompense=newRecompense;
    objectif = obj;
    fini = false;
}

Mission::~Mission(){
    recompense=0;
    objectif = "";
    fini = false;
}

unsigned int Mission::getRecompense()const{ return recompense; }

bool Mission::getFini()const{return fini;}

string Mission::getObjectif()const{ return objectif; }

void Mission::setRecompense(unsigned int newRecompense){ recompense = newRecompense; }

void Mission::setFini(bool fin){ fini = fin; }

void Mission::testRegression() {
    cout<<"Tests pour le module Mission :"<<endl;
    assert(objectif == "INVALID");
    assert(recompense == 0);
    assert(fini==false);
    cout<<"Constructeur par défaut OK ..."<<endl;
    Mission a(100, "test");
    assert(a.getObjectif()=="test");
    assert(a.getRecompense()==100);
    cout<<"Constructeur par copie OK ..."<<endl;
    setRecompense(0);
    setFini(true);
    assert(fini==true);
    assert(recompense==0);
    cout<<"Mutateurs OK ..."<<endl;
}
