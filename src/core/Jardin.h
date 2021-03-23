/** @brief Module gérant un parcelle de jardin
    @file Jardin.h
*/

#ifndef _JARDIN
#define _JARDIN
#include "Point2D.h"
#include "FruitLegume.h"


/*! @class un Jardin = une parcelle de Jardin
*/
class Jardin{
private:
    
    FruitLegume plant; //FruitLegume par défaut
    Point2D position;
    bool occupe;
    bool pret;

public:
    /*! @brief Constructeur : initialise une parcelle de jardin
    */
    Jardin(); 

    /*! @brief Accesseur : renvoie la valeur du booléen occupe
    */
    bool getOccupe()const;   

    /*! @brief Accesseur : renvoit la valeur du booléen pret
    */ 
    bool getPret()const; 
    
    /*! @brief Mutateur : modifie la valeur du booléen occupe
        @param occ la valeur de occupe est remplacée par occ
    */
    void setOccupe(bool occ);
    
    /*! @brief Mutateur : modifie la valeur du booléen pret
        @param prt la valeur de pret est remplacée par prt
    */
    void setPret(bool prt);

    /*! @brief Teste toutes les fonctions du module
    */
    void testRegression();
    
};



#endif //_JARDIN