/*!
* \brief Terrain est une classe qui crée des terrains ou le joueur peut se déolacer.
*
*/

#ifndef _TERRAIN
#define _TERRAIN

#include <strings.h>
#include <iostream>
#include "EnsembleMeuble.h"


class Terrain {
private:
   
    unsigned int dimX,dimY; 
    char terr[100][100] ;
    string nom;
    //EnsemblePnj ;
    //EnsembleActivite ;
    //EnsemblePortail ;
    EnsembleMeuble meublesTerrain;
 
public:
   
    /*! @brief Constructeur par defaut: initialise un terrain vide.
    */
    Terrain();
    
    /*! @brief Destructeur: réinitialise un terrain en terrain vide.
    */
    ~Terrain();

    /*! @brief Constructeur avec paramètres
        @param x longueur du terrain
        @param y largeur du terrain
        @param nomTerrain nom du Terrain
        @param pnj Ensemble de Pnj
        @param activites Ensemble d'Activite
        @param portails Ensemble de Portail
        @param meubles Ensemble de Meuble
    */
    Terrain(unsigned int x, unsigned int y, string nomTerrain,/*EnsemblePnj pnj, EnsembleActivite activites,
    EnsemblePortail portails, */EnsembleMeuble meubles);

    /*!
    @brief Renvoie vrai si on peut positionnner un personnage aux coordonnées (x,y), faux sinon
    @param x : abs de la case à tester
    @param y : ordonnée de la case à tester
    */
    bool estPositionPersoValide (const int x, const int y) const;

    /*! @brief Accesseur : récupère la composante dimX du Terrain
    */
    unsigned int getdimX () const;

    /*! @brief Accesseur : récupère la composante dimY du Terrain
    */
    unsigned int getdimY () const;

    /*! @brief Accesseur : récupère les pnj du Terrain
    */
    //EnsemblePnj getPnj () const;

    /*! @brief Accesseur : récupère les activitées du Terrain
    */
    //EnsembleActivite getActivites () const;

    /*! @brief Accesseur : récupère les portails du Terrain
    */
    //EnsemblePortail getPortails () const;

    /*! @brief Accesseur : récupère les meubles du Terrain
    */
    EnsembleMeuble getMeubles () const;

    /*! @brief Accesseur : récupère le nom du Terrain
    */
    string getNom () const;
    
    /*!
    @brief Renvoie le type d'objet se trouvant en (x,y)
    @param x : numero de ligne de la case de l'objet
    @param y : numero de colonne de la case de l'objet
    */
    char getXY (const unsigned int x, const unsigned int y) const;

    /*! @brief Affiche le Terrain*/
    void afficheTerrain();

    void setChar(unsigned int x,unsigned int y,char symbole);
    
    /*! @brief Test des fonctions du module*/
    void testRegression();

};
#endif // _TERRAIN
