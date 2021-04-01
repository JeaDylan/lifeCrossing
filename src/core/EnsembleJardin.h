/** @brief Module gérant tout le jardin
    @file EnsembleJardin.h
*/
#ifndef _ENSEMBLE_JARDIN
#define _ENSEMBLE_JARDIN
#include "Jardin.h"
#include "EnsembleFruitLeg.h"



/*! @brief un EnsembleJardin = un tableau dynamique de Jardin 
*/
class EnsembleJardin{
public:
    vector<Jardin> * tabJardin;
    unsigned int dimX;
    unsigned int dimY;
    Point2D position;
    EnsembleFruitLeg banqueFruitLeg;
    

    /*! @brief Constructeur : alloue un tableau dynamique de Jardin sur le tas 
    */
    EnsembleJardin();
    /*! @brief Destructeur : desalloue le tableau 
    */
    ~EnsembleJardin();

    /*! @brief Accesseur : renvoit la dimension X du Jardin
    */
    unsigned int getDimX();

    /*! @brief Accesseur : renvoit la largeur du Jardin
    */
    unsigned int getDimY();


    /*! @brief Mutateur : modifie la longueur du Jardin
        @param dx modifie la coordonnée x
    */
    void setDimX(unsigned int dx);

    /*! @brief Mutateur : modifie la largeur du Jardin
        @param dy modifie la coordonnée y
    */
    void setDimY(unsigned int dy);

    /*! @brief Ajoute une parcelle de Jardin 
        @param jardin est ajouté au tableau dynamique
    */
    void ajouterJardin(const Jardin & jardin);

    /*! @brief Supprime une parcelle de Jardin aux coordonnées (nx,ny) du Jardin
        @param nx coordonnée en x de la parcelle à supprimer
        @param ny coordonnée en y de la parcelle à supprimer
    */
    void suppJardin(unsigned int nx, unsigned int ny);

    /*! @brief Renvoit l'indice dans le tableau du Jardin de coordonnées (nx,ny)
    */
    int recupIndice(unsigned int nx, unsigned int ny);

    /*! @brief Renvoit true si la parcelle de jardin aux coordonnées (x,y) est recoltable
    */
    bool estRecoltable(unsigned int x,unsigned int y);

  

    /** @brief lorsque le perso plante une graine la parcelle de jardin qui est initiallement vide est rempli
    *   avec les données du jardin en parametre, est utilisé dans Jeu::planter()
    */
    void assignerFruitLeg(string nom, unsigned int indice);

    /*! @brief Teste toutes les fonctions du module
    */
    void testRegression();


};


#endif //_ENSEMBLE_JARDIN