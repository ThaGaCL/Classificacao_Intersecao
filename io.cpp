#include "io.h"

void classifyPolygon(Polygon &polygon){
    if(polygon.isPolygonSimple()){
        polygon.setSimpleOrComplex(SIMPLE);

        if (polygon.isPolygonConvex()){
            polygon.setConvexOrConcave(CONVEX);
        } else {
            polygon.setConvexOrConcave(CONCAVE);
        }
    } else {
        polygon.setSimpleOrComplex(COMPLEX);
        polygon.setConvexOrConcave(CONCAVE);
    }
}

void IO::read(POLYGON_LIST &polygons, POINTS &points){
    int m,n; // m poligonos, n pontos
    std::cin >> m >> n;
    

    for(int i=0; i < m; i++){
        int numPoints;
        std::cin >> numPoints;
        
        if(numPoints < 3){
            return;
        }

        polygons.push_back(Polygon());
        
        polygons[i].setNumSides(numPoints);
        polygons[i].setNumPoints(numPoints);

        for(int j=0; j < numPoints; j++){
            Point p;
            std::cin >> p.x >> p.y;
            polygons[i].addPoint(p);
        }

        classifyPolygon(polygons[i]);
    }

    for(int i=0; i < n; i++){
        Point p;
        std::cin >> p.x >> p.y;
        p.polygonIndex.clear(); 
        points.push_back(p);
    }

    
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

    for(int i=0; i < polygons.size(); i++){
        printf("%d", i+1);
        switch (polygons[i].getSimpleOrComplex()) {
            case SIMPLE:
                printf(" simples");
                break;
            case COMPLEX:
                printf(" nao simples");
                break;
        }

        switch (polygons[i].getConvexOrConcave()) {
            case CONVEX:
                printf(" e convexo");
                break;
            case CONCAVE:
                printf(" e nao convexo");
                break;
        }
        printf("\n");
    }

    for(int i=0; i < points.size(); i++){
        printf("%d: ", i+1);
        for(int j=0; j < points[i].polygonIndex.size(); j++){
            printf("%d ", points[i].polygonIndex[j]);
        }
        printf("\n");
    }
}

void IO::classifyPoints(POLYGON_LIST &polygons, POINTS &points){
    SweepLine sweep(points);

    for (int i = 0; i < polygons.size(); i++){
        polygons[i].preProcess();
		sweep.isInsidePolygon(polygons[i].getSides(), i);
	}
}
