#ifndef I_O_H
#define I_O_H
#include <iostream>
#include <string>
#include <vector>
#include "polygon.h"
#include "sweep.h"

using POLYGON_LIST = std::vector<Polygon>;


class IO {
    public:

    // construtor e destrutor
    IO(){};
    ~IO(){};

    // métodos

    // lê os polígonos e os pontos do arquivo de entrada
    void read(POLYGON_LIST &polygons, POINTS &points);
    void print(POLYGON_LIST &polygons, POINTS &points);
    void printOut(POLYGON_LIST &polygons, POINTS &points);  
    void classifyPoints(POLYGON_LIST &polygons, POINTS &points);
};

#endif