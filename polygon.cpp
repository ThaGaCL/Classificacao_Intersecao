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

void Polygon::setSides() {
    for (int i = 0; i < numPoints; i++) {
        SIDE side;
        side.first = points[i];
        side.second = points[(i + 1) % numPoints];
        addSide(side);
    }
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

int orientation(Point p1, Point p2, Point p3){
    return (p2.y - p1.y) * (p3.x - p2.x) - (p2.x - p1.x) * (p3.y - p2.y);
}

bool lineIntersection(Point p1, Point p2, Point p3, Point p4) {
    int o1 = orientation(p1, p2, p3);
    int o2 = orientation(p1, p2, p4);
    int o3 = orientation(p3, p4, p1);
    int o4 = orientation(p3, p4, p2);

    if (o1 * o2 < 0 && o3 * o4 < 0) {
        return true; 
    }

    return false;
}

bool Polygon::isPolygonSimple() {
    for (int i = 0; i < numPoints; i++) {
        for (int j = i + 1; j < numPoints; j++) {
            if (lineIntersection(points[i], points[(i + 1) % numPoints], points[j], points[(j + 1) % numPoints])) {
                return false;
            }
        }
    }

    return true;
}

bool Polygon::isPolygonConvex() {
    int sign = 0;

    for (int i = 0; i < numPoints; i++) {
        int dx1 = points[(i+1) % numPoints].x - points[i].x;
        int dy1 = points[(i+1) % numPoints].y - points[i].y;
        int dx2 = points[(i+2) % numPoints].x - points[(i+1) % numPoints].x;
        int dy2 = points[(i+2) % numPoints].y - points[(i+1) % numPoints].y;

        int crossProduct = dx1 * dy2 - dy1 * dx2;

        if (crossProduct == 0) {
            continue; 
        }

        if (sign == 0) {
            sign = (crossProduct > 0) ? 1 : -1;
        } else if ((crossProduct > 0 && sign < 0) || (crossProduct < 0 && sign > 0)) {
            return false;
        }
    }

    return true;
}