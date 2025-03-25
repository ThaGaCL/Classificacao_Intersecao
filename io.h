#ifndef I_O_H
#define I_O_H
#include <iostream>
#include <string>
#include <vector>
#include "polygon.h"

using POLYGON_LIST = std::vector<Polygon>;

class IO {
    public:

    // construtor e destrutor
    IO(int argc, char *argv[]);
    ~IO();

    // métodos

    // lê os polígonos e os pontos do arquivo de entrada
    void read(POLYGON_LIST &polygons, POINTS &points);
    
};

#endif