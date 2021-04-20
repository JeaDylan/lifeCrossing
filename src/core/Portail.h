/*!
* \brief Meuble est une class qui qui contient des Meubles qui apparaitront sur les terrain.
* Eléments de décoration.
*/

#ifndef _PORTAIL
#define _PORTAIL
#include <iostream>
#include <vector>
#include <strings.h>
#include "Point2D.h"

using namespace std;

class Portail {
private:
    


public:

    string nom;
    Point2D position;
    
    /*! @brief Consturcteur par defaut : initialise les caractéristiques d'un portail
    @param nomP Pas de nom (identifiant)
    @param pos Pas de Position 2D 
    */
    Portail();

    /*! @brief Consturcteur par copie : initialise les caractéristiques d'un portail
    @param nomP nom du meuble (identifiant)
    @param pos Position 2D dans le terrain correspondant
    */
    Portail(string nomP,const Point2D & pos);
    
    /*! @brief Destructeur: suppression d'un portail
    */
    ~Portail();

    /*! @brief Accesseur : récupère le nom d'un portail */
    string getNomPortail() const;
    
    /*! @brief Accesseur : récupère la position d'un portail */
    Point2D getPosition() const;

    /*! @brief Affiche le nom du portail et sa position */
    void affichePortail() const;
     
    /*! @brief Test des fonctions du module*/
    void testRegression();

};

#endif