#ifndef SWEEP_H
#define SWEEP_H

#include <iostream>
#include <vector>
#include "polygon.h"
#include "point.h"
#include <algorithm>

struct Event {
    Point point;
    int index;
    bool isStart; 
};

using EVENTS = std::vector<Event>;

class SweepLine {

public:
    SweepLine(POINTS &points): points(points) {}
    ~SweepLine() {}

    bool inside = false;
    int sweep = 0;
	int polygonId;
    //Point point;
	POINTS &points;
    SIDES activeEvents; 
    std::vector<int> activeSegments;
    EVENTS events;

    void virtual isInsidePolygon(SIDES sides, int polygonId){
        inside = false;
        activeEvents = sides;

        for (int i = 0; i < sides.size(); i++){
            Event event;
            event.point = sides[i].first;
            event.index = i;
            event.isStart = true; 
            events.push_back(event);

            event.point = sides[i].second;
            event.index = i;
            event.isStart = false;
            events.push_back(event);
        }

		this->polygonId = polygonId;

        orderSides();
        processEvents();
        clearArrays();
    }

    // Métodos
    void setIsInside(bool isInside);
    bool getIsInside();

    void orderSides();
    void processEvents();
    void clearArrays();
    void addEvent(int index);
    void removeEvent(int index);
};

#endif
