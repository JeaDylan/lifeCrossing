/**
    @brief Module gérant une jauge
    @file Jauge.h
*/

/*!
* \brief Jauge est une class qui gère le système de niveau (xp, santé, faim...) dans le jeu
*/

#ifndef _JAUGE
#define _JAUGE
#include <iostream>
#include <strings.h>

using namespace std;

class Jauge {
private:
    int niveauActuel;
    int niveauMax;

public:
    /*! @brief Constructeur par defaut : initialise les caractéristiques d'une jauge
    */
    Jauge();

    /*! @brief Constructeur par copie : initialise les caractéristiques d'une jauge
    @param nivActuel niveau actuel de la jauge
    @param nivMax niveau max de la jauge
    */
    Jauge(int nivActuel, int nivMax);
    
    /*! @brief Destructeur: suppression d'une jauge
    */
    ~Jauge();

    /*! @brief Accesseur : récupère le niveau actuel de la jauge */
    int getNiveau() const;

    /*! @brief Accesseur : récupère le niveau max de la jauge */
    int getNiveauMax() const;

    /*! @brief Mutateur : modifie le niveau actuel de la jauge
    @param newNiveau niveauActuel est remplacé par newNiveau */
    void setNiveau(int newNiveau);

    /*! @brief Mutateur : modifie le niveau max de la jauge
    @param newNiveauMax niveauMax est remplacé par newNiveauMax */
    void setNiveauMax(int newNiveauMax);

    /*! @brief test si la jauge est remplie en renvoyant true si elle l'est */
    bool jaugeRemplie() const;
    
    /*! @brief Affiche les données de la jauge */
    void afficheJauge() const;

    /*! @brief Renvoie les données de la jauge en chaîne de caractères */
    string afficheJeuTxt() const;
     
    /*! @brief Test des fonctions du module*/
    void testRegression();

};

#endif //_JAUGE
