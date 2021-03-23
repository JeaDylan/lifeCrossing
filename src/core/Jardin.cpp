#include "Jardin.h"


Jardin::Jardin(){
    
   // position à déterminer;
    occupe = false;
    pret = false;
}



bool Jardin::getOccupe()const{ return occupe; }

bool Jardin::getPret()const{ return pret; }

void Jardin::setOccupe(bool occ){ occupe = occ;}

void Jardin::setPret(bool prt){ pret = prt; }

void Jardin::testRegression(){
    
       assert(occupe == false);
       assert(pret == false);
       assert(plant.getNomGraine() == "NULL");
       assert(plant.getTypeGraine() == "NULL");
       assert(plant.getPrixGraine() == 0);
       setOccupe(true);
       assert(getOccupe() == true );
       setPret(true);
       assert(getPret() == true);


}