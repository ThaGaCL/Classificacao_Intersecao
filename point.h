#ifndef POINT_H
#define POINT_H
#include <iostream>
#include <vector>

using namespace std;

typedef struct Point
{
    int x;
    int y;
    vector<int> polygonIndex; // índice do polígono ao qual o ponto pertence
} Point;

#endif
