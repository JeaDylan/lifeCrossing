#include "Jardin.h"


Jardin::Jardin(){
    //position.getX() = 0 et position.getY()=0 par défaut
    occupe = false;
    pret = false;
}

Jardin::Jardin(unsigned int nx, unsigned int ny){
     position.setX(nx);
     position.setY(ny);
     occupe = false;
     pret = false;
}

unsigned int Jardin::getPosX()const{ return position.getX(); }

unsigned int Jardin::getPosY()const{ return position.getY(); }

void Jardin::setPosX(unsigned int nx){ position.setX(nx); }

void Jardin::setPosY(unsigned int ny){ position.setY(ny); }

FruitLegume Jardin::getPlant()const{ return plant; }

void Jardin::setPlant(const FruitLegume & fruitLeg){
    plant.setNomGraine(fruitLeg.getNomGraine());
    plant.setTypeGraine(fruitLeg.getTypeGraine());
    plant.setPrixGraine(fruitLeg.getPrixGraine());
    plant.setPrixVente(fruitLeg.getPrixVente());
    plant.setGainEnergie(fruitLeg.getGainEnergie());
    plant.setTempsRecolte(fruitLeg.getTempsRecolte());
}


bool Jardin::getOccupe()const{ return occupe; }

bool Jardin::getPret()const{ return pret; }

void Jardin::setOccupe(bool occ){ occupe = occ;}

void Jardin::setPret(bool prt){ pret = prt; }

void Jardin::testRegression(){
       cout <<"Debut test regression Module Jardin ..."<< endl;    
       assert(occupe == false);
       assert(pret == false);
       assert(plant.getNomGraine() == "NULL");
       assert(plant.getTypeGraine() == "NULL");
       assert(plant.getPrixGraine() == 0);
       cout << "Constructeur par défaut...OK"<<endl;
       setOccupe(true);
       assert(getOccupe() == true );
       setPret(true);
       assert(getPret() == true);
       cout << "setFonction() ...OK" <<endl;
       FruitLegume fraise("fraise","fruit",4,6,25,5);
       setPlant(fraise);
       assert(plant.getNomGraine() == "fraise");
       assert(plant.getTypeGraine() == "fruit");
       assert(plant.getPrixGraine() == 4);
       assert(plant.getPrixVente() == 6 );
       assert(plant.getGainEnergie()== 25);
       assert(plant.getTempsRecolte() == 5);
       cout << "Mutateur plant setPlant(const FruitLeg &)...OK" << endl;
       Jardin test(10,11);
       assert(test.position.getX() == 10);
       assert(test.position.getY() == 11);
       assert(test.getOccupe() == false);
       cout <<"Constructeur par copie...ok"<<endl;
       test.position.setX(12);
       assert(test.position.getX()== 12);
       cout << "setPosX()...OK" << endl;

       cout <<"Fin du test. Tout est OK. "<<endl;


}