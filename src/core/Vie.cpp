#include "Vie.h"
#include <cassert>


Jauge Vie::getPtsDeVie()const{ return ptsDeVie; }

Jauge Vie::getFaim()const{ return faim; }

Jauge Vie::getSoif()const{ return soif; }

Jauge Vie::getFatigue()const{  return fatigue; }

void Vie::setPtsDeVie(int vi){ ptsDeVie.setNiveau(vi); }
    
void Vie::setFaim(int fa){ faim.setNiveau(fa); }
    
void Vie::setSoif(int so){ soif.setNiveau(so); }

void Vie::setFatigue(int fat){ fatigue.setNiveau(fat); }

void Vie::varieAuto() {
    setFaim(getFaim().getNiveau()+1);
    setFatigue(getFatigue().getNiveau()+1);
    setSoif(getSoif().getNiveau()+1);       
}

void Vie::testRegression(){
    cout <<"Debut test resgression Module Vie..."<<endl;
    assert(getPtsDeVie().getNiveau() == 0);
    assert(getFaim().getNiveau() == 0);
    assert(getSoif().getNiveau() == 0);
    setFaim(50);
    assert(getFaim().getNiveau() == 50);
    cout<<"Tout est OK!"<<endl;

}
