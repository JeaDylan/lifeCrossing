/**
    @brief Module gérant un FruitLegume
    @file FruitLegume.h

*/
#ifndef _FRUIT_LEGUME
#define _FRUIT_LEGUME
#include <strings.h>
#include <cassert>
#include <iostream>
using namespace std;

/*! @class un FruitLegume = une graine qui donne un fruit ou un legume definit par un nom, un type(fruit ou legume),
    un prix,un gain et un temps de récolte
*/
class FruitLegume {
private:
    string nomGraine;
    string typeGraine;
    float prixGraine;
    float prixVente;
    int gainEnergie;
    unsigned int tempsRecolte;
 
    


public:
    /*! @brief Constructeur par défaut : valeur par défaut d'un FruitLegume 
    */
    FruitLegume();

    /*! @brief Consturcteur par copie : initialise les caractéristiques d'un fruit ou légume
    @param nomG nom d'une graine
    @param typeG type d'une graine (fruit ou legume)
    @param prixG prix d'achat d'une graine
    @param prixV prix de vente au marché d'une graine
    @param gainE points de faim en plus
    @param tempsR temps de récolte 
    */
    FruitLegume(string nomG, string typeG, float prixG, float prixV, int gainE, unsigned int tempsR);
    
  
    /*! @brief Accesseur : récupère le nom d'une graine */
    string getNomGraine() const;
    
    /*! @brief Accesseur : récupère le type d'une graine */
    string getTypeGraine() const;

    /*! @brief Accesseur : récupère le prix d'achat d'une graine */
    float getPrixGraine() const;

    /*! @brief Accesseur : récupère le prix de vente d'une graine */
    float getPrixVente() const;
    
    /*! @brief Accesseur : récupère le gain d'énergie d'une graine */
    int getGainEnergie() const;

    /*! @brief Accesseur : récupère le temps de récolte d'une graine
    */
    unsigned int getTempsRecolte()const;


    /*! @brief Mutateur : modifie le nom d'une graine
        @param nom nomGraine est remplacé par nom */
    void setNomGraine(string nom);

    /*! @brief Mutateur : modifie le type d'une graine
        @param type typeGraine est remplacé par type */ 
    void setTypeGraine(string type);

    /*! @brief Mutateur : modifie le prix d'achat d'une graine
        @param prixGr prixGraine est remplacé par prixGr */
    void setPrixGraine(float prixGr);

      /*! @brief Mutateur : modifie le prix de vente d'une graine
          @param prixVe prixVente est remplacé par prixVe */
    void setPrixVente(float prixVe);

    /*! @brief Mutateur : modifie le gain d'energie d'un fruit ou légume
        @param gain gainEnergie est remplacé par gain */
    void setGainEnergie(int gain);

    /*! @brief Mutateur : modifie le temps de récolte d'une graine
        @param temps tempsRecolte est remplacé par temps
    */
    void setTempsRecolte(unsigned int temps);
     
    /*! @brief Test des fonctions du module*/
    void testRegression()const;



};







#endif //_FRUIT_LEGUME