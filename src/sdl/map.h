/*!
* \brief Map est une classe qui qui contient toutes les informations des cartes utilisées dans le jeu
*/

#ifndef _MAP
#define _MAP
#include <cstdlib>
class Map{
public:
    int **carte1;
    int **carte2;
    int **carte3;
    int **carte4;
    int **carte5;
    int **interfaceJardin;
    int **interfaceInventaire;

    /*! @brief Constructeur : allocation dynamique et initialisation des 7 cartes utilisées
    */
    Map();

    /*! @brief Destructeur : libère les pointeurs et l'espace mémoire utilisé
    */
    ~Map();
};

#endif //_MAP