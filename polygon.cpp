#include "polygon.h"
#include <iostream>

using namespace std;

POINTS Polygon::getPoints() {
    return points;
}

void Polygon::addPoint(Point point) {
    points.push_back(point);
}

SIDES Polygon::getSides() {
    return sides;
}

void Polygon::setSides(SIDES sides) {
    this->sides = sides;
}

void Polygon::addSide(SIDE side) {
    sides.push_back(side);
}

SIDE Polygon::getSide(int index) {
    return sides[index];
}

void Polygon::setSide(SIDE side) {
    sides.push_back(side);
}

void Polygon::setNumPoints(int numPoints) {
    this->numPoints = numPoints;
}

int Polygon::getNumPoints() {
    return numPoints;
}

void Polygon::setNumSides(int numSides) {
    this->numSides = numSides;
}

int Polygon::getNumSides() {
    return numSides;
}

POLYGON_TYPE Polygon::getConvexOrConcave() {
    return convexOrConcave;
}

void Polygon::setConvexOrConcave(POLYGON_TYPE type) {
    this->convexOrConcave = type;
}

POLYGON_TYPE Polygon::getSimpleOrComplex() {
    return simpleOrComplex;
}

void Polygon::setSimpleOrComplex(POLYGON_TYPE type) {
    this->simpleOrComplex = type;
}

