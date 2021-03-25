#include "Mission.h"



Mission::Mission(){
    argent = xp = vie = 0;
    objectif ="INVALID";
    declenche = false;
    fini = false;
    pfm = NULL;

}

Mission::Mission(unsigned int arg,unsigned int xP,unsigned int vI,unsigned int nuM,string obj,bool dec,bool fin,void(*pf)(void)){
    argent = arg;
    xp = xP;
    vie = vI;
    num = nuM,
    objectif = obj;
    declenche = dec;
    fini = fin;
    pfm = pf;

}

unsigned int Mission::getArgent()const{ return argent; }

unsigned int Mission::getXp()const{ return xp; }

unsigned int Mission::getVie()const{ return vie; }

unsigned int Mission::getNum()const{ return num; }

string Mission::getObjectif()const{ return objectif; }

bool Mission::getDeclenche()const{ return declenche; }

bool Mission::getFini()const{ return fini; }

void (*pfm)(void) Mission::getPfm()const{ return pfm; }

void Mission::setArgent(unsigned int arg){ argent = arg ;}

void Mission::setXp(unsigned int xP){ xp = xP; }

void Mission::setVie(unsigned int vI){ vie = vI; }

void Mission::setNum(unsigned int nuM){ num = nuM; }

void Mission::setObjectif(string obj){ objectif = obj; }

void Mission::setDeclenche(bool dec){ declenche = dec; }

void Mission::setFini(bool fin){ fini = fin; }

void Mission::setPfm(void(*pf)(void)){ pfm = pf; }

/* dans la classe Perso
void Mission::mission_1(){
//gagner 10 points de vie en mangeant 2 tomates
// pdv_debut = getPdv() du perso
//while pdv_debut != pdv_debut + 10
// sleep(1)
//setFini(true);
// sous = getArgent();
//setArgent(sous + 10);    

}
*/

