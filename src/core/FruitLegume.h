#ifndef _FRUIT_LEGUME
#define _FRUIT_LEGUME
#include <strings.h>
#include <cassert>
#include <iostream>
using namespace std;


class FruitLegume {
private:
    string nomGraine;
    string typeGraine;
    int prixGraine;
    int prixVente;
    int gainEnergie;


public:
    /*! @brief Consturcteur par copie : initialise les caractéristiques d'un fruit ou légume
    @param nomG nom d'une graine
    @param typeG type d'une graine (fruit ou legume)
    @param prixG prix d'achat d'une graine
    @param prixV prix de vente au marché d'une graine
    @param gainE points de faim en plus
    */
    FruitLegume(string nomG, string typeG, int gainE, int prixG, int prixV);
    
    /*! @brief Destructeur: suppression d'un fruit ou légume
    */
    ~FruitLegume();

    /*! @brief Accesseur : récupère le nom d'une graine */
    string getNomGraine() const;
    
    /*! @brief Accesseur : récupère le type d'une graine */
    string getTypeGraine() const;

    /*! @brief Accesseur : récupère le prix d'achat d'une graine */
    int getPrixGraine() const;

    /*! @brief Accesseur : récupère le prix de vente d'une graine */
    int getPrixVente() const;
    
    /*! @brief Accesseur : récupère le gain d'énergie d'une graine */
    int getGainEnergie() const;

    /*! @brief Mutateur : modifie le nom d'une graine
        @param nom nomGraine est remplacé par nom */
    void setNomGraine(string nom);

    /*! @brief Mutateur : modifie le type d'une graine
        @param type typeGraine est remplacé par type */ 
    void setTypeGraine(string type);

    /*! @brief Mutateur : modifie le prix d'achat d'une graine
        @param prixGr prixGraine est remplacé par prixGr */
    void setPrixGraine(int prixGr);

      /*! @brief Mutateur : modifie le prix de vente d'une graine
          @param prixVe prixVente est remplacé par prixVe */
    void setPrixVente(int prixVe);

    /*! @brief Mutateur : modifie le gain d'energie d'un fruit ou légume
        @param gain gainEnergie est remplacé par gain */
    void setGainEnergie(int gain);
     
    /*! @brief Test des fonctions du module*/
    void testRegression();



};







#endif