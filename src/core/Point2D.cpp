#include <iostream>
#include <cassert>
#include "Point2D.h"

using namespace std ;

Point2D::Point2D() {
    x=0;
    y=0;
}

Point2D::~Point2D() {
    x=0;
    y=0;
}

Point2D::Point2D(unsigned int nx, unsigned int ny) {
    assert(nx>=0&&ny>=0);
    x=nx;
    y=ny;
}

unsigned int Point2D::getX() const {
    return x;
}

unsigned int Point2D::getY() const {
    return y;
}

void Point2D::setX(unsigned int nx) {
    assert(nx>=0);
    x=nx;
}

void Point2D::setY(unsigned int ny) {
    assert(ny>=0);
    y=ny;
}

Point2D Point2D::operator= (const Point2D & p) {
    x=p.getX();
    y=p.getY();
    return *this;
}

void Point2D::testRegression() {
    cout<<"Tests pour le module Point2D : "<<endl;
    assert(x==0&&y==0);
    cout<<"constructeur par défaut OK ..."<<endl;
    Point2D p1(2,5);
    Point2D p2;
    assert(p1.getX()==2&&p1.getY()==5);
    cout<<"constructeur par copie et accesseurs OK ..."<<endl;
    p1.setX(3);
    p1.setY(1);
    assert(p1.getX()==3&&p1.getY()==1);
    cout<<"Mutateurs OK ..."<<endl;
    p2=p1;
    assert(p2.getX()==p1.getX());
    assert(p2.getY()==p1.getY());
    cout<<"Operator= OK ..."<<endl;
}