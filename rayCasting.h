#ifndef rayCasting_H
#define rayCasting_H

#include <iostream>
#include <vector>
#include "polygon.h"
#include "point.h"
#include <algorithm>

class rayCasting {

public:
    rayCasting(POINTS &points): points(points) {}
    ~rayCasting() {}

    bool inside = false;
	int polygonId;
    //Point point;
	POINTS &points;
    SIDES sides;

    void virtual isInsidePolygon(SIDES sides, int polygonId){
        inside = false;

		this->polygonId = polygonId;
        this->sides = sides;

        processEvents();
    }

    // Métodos
    void setIsInside(bool isInside);
    bool getIsInside();
    void processEvents();
};

#endif
