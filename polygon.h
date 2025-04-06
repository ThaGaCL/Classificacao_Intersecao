#ifndef POLYGON_H
#define POLYGON_H
#include <iostream>
#include <vector>
#include <string>
#include <utility> 
#include "point.h"

using SIDE = std::pair<Point, Point>;
using SIDES = std::vector<SIDE>;
using POINTS = std::vector<Point>;

typedef enum POLYGON_TYPE
{
    CONVEX,
    CONCAVE,
    COMPLEX,
    SIMPLE
} POLYGON_TYPE;

class Polygon
{
    private:
    POINTS points;
    SIDES sides;

    POLYGON_TYPE convexOrConcave;
    POLYGON_TYPE simpleOrComplex;
    int numPoints;
    int numSides;

    public:

    // construtor e destrutor
    Polygon(){};
    ~Polygon(){};

    POINTS getPoints();
    void addPoint(Point points); 
    
    SIDES getSides();
    void setSides(SIDES sides); 
    void addSide(SIDE side);

    SIDE getSide(int index);
    void setSide(SIDE side);

    POLYGON_TYPE getConvexOrConcave();
    void setConvexOrConcave(POLYGON_TYPE type);

    POLYGON_TYPE getSimpleOrComplex();
    void setSimpleOrComplex(POLYGON_TYPE type);

    int getNumPoints();
    void setNumPoints(int index);

    int getNumSides();
    void setNumSides(int numSides);

    bool isPolygonConvex();
    bool isPolygonSimple();
};




#endif