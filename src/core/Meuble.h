/*!
* \brief Meuble est une class qui qui contient des Meubles qui apparaitront sur les terrain.
* Eléments de décoration.
*/

#ifndef _MEUBLE
#define _MEUBLE
#include <strings.h>
#include <iostream>
#include <vector>
#include <strings.h>
#include "Point2D.h"

using namespace std;

class Meuble {
private:
    string nom;
    Point2D dimension;


public:
    /*! @brief Consturcteur par defaut : initialise les caractéristiques d'un meuble
    @param nomM Pas de nom (identifiant)
    @param dim Pas de Position 2D 
    */
    Meuble();

    /*! @brief Consturcteur par copie : initialise les caractéristiques d'un meuble
    @param nomM nom du meuble (identifiant)
    @param dim Position 2D dans le terrain correspondant
    */
    Meuble(string nomM,const Point2D & dim);
    
    /*! @brief Destructeur: suppression d'un meuble
    */
    ~Meuble();

    /*! @brief Accesseur : récupère le nom d'une graine */
    string getNomMeuble() const;
    
    /*! @brief Accesseur : récupère la position d'un meuble */
    Point2D getDimension() const;

    /*! @brief Affiche le nom du meuble et sa position */
    void afficheMeuble() const;
     
    /*! @brief Test des fonctions du module*/
    void testRegression();

};

#endif