#include <cassert>
#include "Meuble.h"


Meuble::Meuble() {
    nom="sansnom";
    dimension= new vector<Point2D>;
}

Meuble::Meuble(string nomM,const vector<Point2D> & dim) {
    nom=nomM;
    dimension = new vector<Point2D>;
    dimension->assign(dim.begin(),dim.end());
}

Meuble::~Meuble() {
    dimension->clear();
    dimension->shrink_to_fit ();
    delete dimension;
    dimension=NULL;
}

string Meuble::getNomMeuble() const {
    return nom;
}

vector<Point2D>* Meuble::getDimension() const {
    return dimension;
}


void Meuble::testRegression() {
    cout<<"Tests pour le module Meuble :"<<endl;
    assert(nom == "sansnom");
    assert(dimension->empty());
    cout<<"Constructeur par défaut OK ..."<<endl;
    Point2D p1(1,2);
    Point2D p2(3,5);
    dimension->push_back(p1);
    dimension->push_back(p2);
    assert(dimension->size()==2);
    cout<<"Ajout de Point2D OK ..."<<endl;
    Meuble m1("table",*dimension);
    assert(m1.getNomMeuble()=="table");
    assert(m1.dimension->size()==2);
    assert(m1.dimension->at(0).getX()==1&&m1.dimension->at(0).getY()==2);
    assert(m1.dimension->at(1).getX()==3&&m1.dimension->at(1).getY()==5);
    cout<<"Constructeur par copie OK ..."<<endl;
}
