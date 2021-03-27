/** @brief Module gérant un parcelle de jardin
    @file Jardin.h
*/

#ifndef _JARDIN
#define _JARDIN
#include "Point2D.h"
#include "FruitLegume.h"


/*! @brief un Jardin = une parcelle de Jardin
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

    /*! @brief Constructeur par copie: initialise une parcelle de jardin
    */
    Jardin(unsigned int nx, unsigned int ny);

    /*! @brief Accesseur: renvoit la position x du jardin
    */
    unsigned int getPosX()const;

    /*! @brief Accesseur: renvoit la position y du jardin
    */
    unsigned int getPosY()const;

    /*! @brief Acesseur : renvoit le fruitLegume (la graine) présente sur le jardin
    */
    FruitLegume getPlant()const;

    /*! @brief Mutateur : modifie la position en x du jardin
    */
    void setPosX(unsigned int nx);

    /*! @brief Mutateur : modifie la position en y du jardin
    */
    void setPosY(unsigned int ny);
    
    /*! @brief Mutateur : modifie la graine présente sur le jardin
    */
    void setPlant(const FruitLegume & fruitLeg);


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