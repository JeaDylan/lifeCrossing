#include "Vie.h"
#include <cassert>


int Vie::getPtsDeVie()const{ return ptsDeVie.getNiveau(); }

int Vie::getFaim()const{ return faim.getNiveau(); }


int Vie::getSoif()const{ return soif.getNiveau(); }

int Vie::getFatigue()const{  return fatigue.getNiveau(); }

void Vie::setPtsDeVie(int vi){ ptsDeVie.setNiveau(vi); }
    
void Vie::setFaim(int fa){ faim.setNiveau(fa); }
    
void Vie::setSoif(int so){ soif.setNiveau(so); }

void Vie::setFatigue(int fat){ fatigue.setNiveau(fat); }



void Vie::testRegression(){
    cout <<"Debut test resgression Module Vie..."<<endl;
    assert(getPtsDeVie() == 0);
    assert(getFaim() == 0);
    assert(getSoif() == 0);
    setFaim(50);
    assert(getFaim() == 50);
    cout<<"Tout est OK!"<<endl;

}
