/*!
* @brief Mission est une classe qui représente une mission que le joueur peut
* accomplir. Chaque mission est présentée par un PNJ (Personnage Non Joueur).
* @file Mission.h
*/

#ifndef _MISSION
#define _MISSION
#include <strings.h>
#include <iostream>
using namespace std;

class Mission {
private:
   
    int recompense; 
    string objectif;
    bool fini;    
 
public:
    /*! @brief Constructeur : initialise une mission
    */
    Mission();
    
    /*! @brief Constructeur par copie: initialise une mission
        @param newRecompense recompense de la mission
        @param obj objectif de la mission
    */
    Mission(int newRecompense, string obj);

    /*! @brief Destructeur : supprime la mission 
    */
    ~Mission();

    /*! @brief Accesseur: renvoie la récompense de la mission
    */
    unsigned int getRecompense()const;

    /*! @brief Accesseur: renvoie fini de la mission
    */
    bool getFini()const;

    /*! @brief Accesseur: renvoie l'objectif de la mission
    */
    string getObjectif()const;

    /*! @brief Mutateur : modifie la récompense de la mission
        @param newRecompense la nouvelle récompense de la mission
    */
    void setRecompense(unsigned int newRecompense);

    /*! @brief Mutateur: modifie la donnée membre fini
    */
    void setFini(bool fin);
    
    /*! @brief Teste toutes les fonctions du module
    */
    void testRegression();
    
};
#endif // _MISSION
