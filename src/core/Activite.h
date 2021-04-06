/** @brief Module gérant une activité
    @file Activite.h
*/

#ifndef _ACTIVITE
#define _ACTIVITE
#include "Point2D.h"
#include <iostream>
#include <strings.h>
using namespace std ;


/*! @brief une Activite : une activité proposée au joueur pour gagner une récompense
*/
class Activite{
private:
    
    string nom;
    unsigned int prix;
    Point2D position;
    unsigned int recompense;
    string typeRecompense; // parmi un nom de fruit OU un nom de legume OU "xp" OU "vie"
    

public:
    /*! @brief Constructeur : initialise une activité
    */
    Activite(); 

    /*! @brief Constructeur par copie: initialise une activité
        @param nomA nom de l'activité
        @param prixA prix de l'activité
        @param positionA position de l'activité
        @param recompenseA recompense de l'activité
        @param typeRecompenseA type de recompense de l'activité
    */
    Activite(string nomA, unsigned int prixA, Point2D positionA, unsigned int recompenseXpA, string typeRecompenseA);

    /*! @brief Destructeur: réinitialise une activité
    */
    ~Activite();    

    /*! @brief Accesseur: renvoie le nom de l'activité
    */
    string getNom()const;

    /*! @brief Accesseur: renvoie le prix de l'activité
    */
    unsigned int getPrix()const;

    /*! @brief Accesseur: renvoie la position de l'activité
    */
    Point2D getPosition()const;

    /*! @brief Accesseur: renvoie la récompense de l'activité
    */
    unsigned int getRecompense()const;
    
    /*! @brief Accesseur: renvoie le type de récompense de l'activité
    */
    string getTypeRecompense()const;

    /*! @brief Mutateur : modifie le nom de l'activité
        @param newNom le nouveau nom de l'activité
    */
    void setNom(string newNom);

    /*! @brief Mutateur : modifie le prix de l'activité
        @param newPrix le nouveau prix de l'activité
    */
    void setPrix(unsigned int newPrix);

    /*! @brief Mutateur : modifie la position de l'activité
        @param newPosition la nouvelle position de l'activité
    */
    void setPosition(Point2D newPosition);

    /*! @brief Mutateur : modifie la récompense de l'activité
        @param newRecompense la nouvelle récompense de l'activité
    */
    void setRecompense(unsigned int newRecompense);    

    /*! @brief Mutateur : modifie le type de récompense de l'activité
        @param newTypeRecompense le nouveau type de récompense de l'activité
    */
    void setTypeRecompense(string newTypeRecompense);  
    
    /*! @brief Retourne si l'activité a été acceptée et effectuée par le joueur
    */
    bool activiteEffectuee() const;
    
    /*! @brief Affiche les données de l'activité */
    void afficheActivite() const;
    
    /*! @brief Teste toutes les fonctions du module
    */
    void testRegression();
    
};



#endif //_JEU
