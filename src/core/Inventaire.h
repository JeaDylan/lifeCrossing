/*!
* \brief Inventaire est une class qui qui contient les resources du personnage.
* Eléments achetés par le personnage.
*/

#ifndef _INVENTAIRE
#define _INVENTAIRE
#include <iostream>
#include <vector>
#include <strings.h>
#include "Jauge.h"
#include "EnsembleFruitLeg.h"

using namespace std;

class Inventaire {
private:

    Jauge stockFruitLeg, stockEau,stockManger;


public:
    EnsembleFruitLeg inventaireFruitLeg;

    /*! @brief Consturcteur par defaut : initialise les stocks à 5/50
    @param stockFruitLeg le nombre de fruits et legumes que possède le personnage
    @param stockEau la quantité d'eau que le personnage possède
    @param stockManger La quantité de nourriture que le personnage possède
    */
    Inventaire();
    
    /*! @brief Destructeur: suppression d'un inventaire
    */
    ~Inventaire();

    /*! @brief Accesseur : récupère le stock de fruit et legumes */
    Jauge getFruitLeg() const;
    
    /*! @brief Accesseur : récupère le stock d'eau */
    Jauge getEau() const;

    /*! @brief Accesseur : récupère le stock de nourriture  */
    Jauge getManger() const;

    /*! @brief Accesseur : récupère le tableau qui stocke les fruits et legumes  */
    EnsembleFruitLeg getInventaireFruitLeg() const;

    /*! @brief Mutateur : modifie le stock de fruit et legumes  */
    void setFruitLeg(int nouveau, bool augmente);

    /*! @brief Mutateur : modifie le stock d'eau  */
    void setEau(int nouveau, bool augmente);

    /*! @brief Mutateur : modifie le stock de nourriture  */
    void setManger(int nouveau, bool augmente);

    /*! @brief Affiche les stocks du personnage */
    void afficheInventaire() const;

    /*! @brief Ajoute un fruitLeg à l'inventaire du perso */
    void ajouterFruitLeg(const FruitLegume & fruitLeg);

    /*! @brief Supprime un fruitLeg à l'inventaire du perso */
    void suppFruitLeg(string fruitLeg,string type);
     
    /*! @brief Test des fonctions du module*/
    void testRegression();

};

#endif