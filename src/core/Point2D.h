/*!
* \brief Point2D est une classe qui crée des points à deux dimensions.
*
* Les Points2D servent à situer les éléments du jeu dans l'espace
*/

#ifndef _POINT2D
#define _POINT2D

class Point2D {
private:
    
 
public:

    unsigned int x,y;
   
    /*! @brief Constructeur par defaut: initialise le point à (0,0).
    */
    Point2D();
    
    /*! @brief Destructeur: initialise le point à (0,0).
    */
    ~Point2D();

    /*! @brief Constructeur de la classe: initialise x,y
        @param nx numéro de ligne (entre 0 et taille du terrain)
        @param ny numéro de colonne(entre 0 et taille du terrain)
    */
    Point2D(unsigned int nx, unsigned int ny);

    /*! @brief Accesseur : récupère la composante x du Point2D
    */
    unsigned int getX () const;

    /*! @brief Accesseur : récupère la composante y du Point2D
    */
    unsigned int getY () const;

    /*! @brief Mutateur : modifie la composante x du Point2D
        @param nx composante x du Point2D
    */
    void setX (unsigned int nx);

    /*! @brief Mutateur : modifie la composante y du Point2D
        @param ny composante y du Point2D
    */
    void setY (unsigned int ny);

    /*! @brief affectation pour un Point2D
        @param p Point2D
    */
    Point2D operator= (const Point2D & p);
    
    /*! @brief Test des fonctions du module*/
    void testRegression();

};
#endif // _Point2D
