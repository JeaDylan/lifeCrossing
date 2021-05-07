#include "Vie.h"
#include <cassert>


Jauge Vie::getPtsDeVie()const{ return ptsDeVie; }

Jauge Vie::getFaim()const{ return faim; }

Jauge Vie::getSoif()const{ return soif; }

Jauge Vie::getFatigue()const{  return fatigue; }

void Vie::setPtsDeVie(int vi){
    ptsDeVie.setNiveau(vi); 
}
    
void Vie::setFaim(int fa){
    assert(fa>=0);
    faim.setNiveau(fa); 
}
    
void Vie::setSoif(int so){
    assert(so>=0);
    soif.setNiveau(so);
}

void Vie::setFatigue(int fat){
    assert(fat>=0);
    fatigue.setNiveau(fat); 
}

void Vie::varieAuto() {
    if(getFaim().jaugeVide()) {
        setFaim(10000);
        setPtsDeVie(getPtsDeVie().getNiveau()-5);
    }
    if(getFatigue().jaugeVide()) {
        setFatigue(10000);
        setPtsDeVie(getPtsDeVie().getNiveau()-5);
    }
    if(getSoif().jaugeVide()) {
        setSoif(10000);
        setPtsDeVie(getPtsDeVie().getNiveau()-5);
    }
    setFaim(getFaim().getNiveau()-5);
    setFatigue(getFatigue().getNiveau()-5);
    setSoif(getSoif().getNiveau()-5);       
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
