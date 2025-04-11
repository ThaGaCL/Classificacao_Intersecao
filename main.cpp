#include "io.h"
#include "polygon.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    POLYGON_LIST polygons;
    POINTS points;
    IO io;

    // printf("Iniciando leitura de polígonos e pontos...\n");
    // Cria os polígonos
    io.read(polygons, points);

    io.classifyPoints(polygons, points);
    
    // Classifica os polígonos

    // Imprime o resultado
    io.printOut(polygons, points);

    return 0;
}