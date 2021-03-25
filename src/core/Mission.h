/*!
* @brief Mission est une classe qui représente une mission que le joueur peut
* accomplir. Chaque mission est présentée par un PNJ (Personnage Non Joueur).
*/

#ifndef _MISSION
#define _MISSION


#include <strings.h>
#include <cassert>
#include <iostream>
using namespace std;

class Mission {
private:
   
    unsigned int argent,xp,vie; //recompense
    unsigned int num; //n° de mission =>identifiant 
    string objectif; //intitulé de la mission
    bool declenche; //utile pour declencher des missions a partir du tableau de mission
    bool fini;    
    void (*pfm)(void); //pointeur fonction mission pour attribuer une fonction a la mission 
 
public:

    Mission();
    
    Mission(unsigned int arg,unsigned int xP,unsigned int vI,unsigned int nuM,bool dec,bool fin,void(*pf)(void));
    

    unsigned int getArgent()const;

    unsigned int getXp()const;

    unsigned int getVie()const;

    unsigned int getNum()const;

    string getObjectif()const;

    bool getDeclenche()const;

    bool getFini()const;

    int getPfm()const;

    void setArgent(unsigned int arg);

    void setXp(unsigned int xP);

    void setVie(unsigned int vI);

    void setNum(unsigned int nuM);

    void setDeclenche(bool dec);

    void setFini(bool fin);

    void setPfm(void(*pf)(void));
    

};
#endif // _MISSION
