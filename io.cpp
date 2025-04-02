#include "io.h"


void IO::read(POLYGON_LIST &polygons, POINTS &points){
    int m,n; // m poligonos, n pontos
    std::cin >> m >> n;
    

    for(int i=0; i < m; i++){
        int numPoints;

        // printf("\nLendo polígono %d...\n", i+1);
        
        std::cin >> numPoints;
        
        if(numPoints < 3){
            // printf("Número de pontos inválido! O polígono deve ter pelo menos 3 pontos.\n");
            return;
        }

        polygons.push_back(Polygon());
        
        // printf("Número de pontos do polígono %d: %d\n", i+1, numPoints);
        
        polygons[i].setNumSides(numPoints);
        polygons[i].setNumPoints(numPoints);

        for(int j=0; j < numPoints; j++){
            Point p;
            std::cin >> p.x >> p.y;
            polygons[i].addPoint(p);
            // printf("Ponto %d do polígono %d lido com sucesso!\n", j+1, i+1);
        }

        // printf("Polígono %d lido com sucesso!\n", i+1);
    }

    // printf("Polígonos lidos com sucesso!\n");

    for(int i=0; i < n; i++){
        Point p;
        std::cin >> p.x >> p.y;
        p.polygonIndex.clear(); // Limpa o vetor de índices do ponto
        points.push_back(p);
    }

    // printf("Pontos lidos com sucesso!\n");
    
}

void IO::print(POLYGON_LIST &polygons, POINTS &points){
    printf("Polígonos:\n");
    for(int i=0; i < polygons.size(); i++){
        printf("Polígono %d:\n", i+1);
        POINTS p = polygons[i].getPoints();
        for(int j=0; j < p.size(); j++){
            printf("Ponto %d: (%d, %d)\n", j+1, p[j].x, p[j].y);
        }
    }

    printf("Pontos:\n");
    for(int i=0; i < points.size(); i++){
        printf("Ponto %d: (%d, %d)\n", i+1, points[i].x, points[i].y);
    }
}

void IO::printOut(POLYGON_LIST &polygons, POINTS &points){
    printf("Polígonos:\n");
    for(int i=0; i < polygons.size(); i++){
        printf("Polígono %d:", i+1);
        printf(" %d", polygons[i].getSimpleOrComplex());
        printf(" %d", polygons[i].getConvexOrConcave());
        printf("\n");
    }

    printf("Poligonos que contem os pontos:\n");
    for(int i=0; i < points.size(); i++){
        printf("Ponto %d: ", i+1);
        for(int j=0; j < points[i].polygonIndex.size(); j++){
            printf("%d ", points[i].polygonIndex[j]);
        }
        printf("\n");
    }
}