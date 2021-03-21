#ifndef _JARDIN
#define _JARDIN
#include "Point2D.h"
#include "FruiLegume.h"

class Jardin{
private:
    FruitLegume plant;
    Point2D position;
    bool occupe;
    bool pret;

public:
    Jardin(); // ??
    ~Jardin();
    bool getOccupe()const;    
    bool getPret()const; 
    
    void setOccupe(bool occ);
    void setPret(bool prt);
    
};



#endif //_JARDIN