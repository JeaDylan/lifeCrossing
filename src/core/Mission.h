/*!
*  @brief Module gérant une mission
* @file Mission.h
*/

#ifndef _MISSION
#define _MISSION
#include <strings.h>
#include <iostream>
using namespace std;

/*! @brief Mission : classe qui représente une mission que le joueur peut
* accomplir. Chaque mission est présentée par un PNJ (Personnage Non Joueur).
*/
class Mission {
private:
   
    int recompense; 
    string objectif;
    bool active;    
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

    /*! @brief Accesseur: renvoie si la mission est active
    */
    bool getActive()const;

    /*! @brief Accesseur: renvoie si la mission est finie
    */
    bool getFini()const;

    /*! @brief Accesseur: renvoie l'objectif de la mission
    */
    string getObjectif()const;

    /*! @brief Mutateur : modifie la récompense de la mission
        @param newRecompense la nouvelle récompense de la mission
    */
    void setRecompense(unsigned int newRecompense);
    
    /*! @brief Mutateur: modifie la donnée membre active
        @param actif un booleen qui dit si la mission est active ou non
    */
    void setActive(bool actif);

    /*! @brief Mutateur: modifie la donnée membre fini
        @param fini un booleen qui dit si la mission est finie ou non
    */
    void setFini(bool fin);
    
    /*! @brief Si la mission est terminée, le booleen "fini" passe à false et "active" repasse à false
    */
    void missionFinie();
    
    /*! @brief Teste toutes les fonctions du module
    */
    void testRegression();
    
};
#endif // _MISSION
