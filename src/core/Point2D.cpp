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
    x=nx;
}

void Point2D::setY(unsigned int ny) {
    y=ny;
}