/*!
* \brief Map est une classe qui qui contient toutes les informations des cartes utilisées dans le jeu
*/

#ifndef _MAP
#define _MAP
#include <cstdlib>
class Map{
public:
    int **carte1; //terrain principal
    int **carte2; // jardin
    int **carte3; // marché
    int **carte4; // maison personnage
    int **carte5; // maison png
    int **interfaceJardin; //utilisée pour interfaceMarcheAchat et interfaceMarcheVente
    int **interfaceInventaire;
    int **carte10; // plage
    int **carte11; // sous l'eau

    /*! @brief Constructeur : allocation dynamique et initialisation des 7 cartes utilisées
    */
    Map();

    /*! @brief Destructeur : libère les pointeurs et l'espace mémoire utilisé
    */
    ~Map();
};

#endif //_MAP