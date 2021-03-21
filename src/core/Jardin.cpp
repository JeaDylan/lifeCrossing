#include "Jardin.h"


Jardin::Jardin(){
    
   // position à déterminer;
    occupe = false;
    pret = false;
}

/*Jardin::~Jardin()
{

}*/

bool Jardin::getOccupe()const{ return occupe; }

bool Jardin::getPret()const{ return pret; }

void Jardin::setOccupe(bool occ){ occupe = occ;}

void Jardin::setPret(bool prt){ pret = prt; }