#include "sweep.h"

void SweepLine::orderSides(){
   std::sort(events.begin(), events.end(), [](const Event &a, const Event &b) {
        if (a.point.x != b.point.x) {
            return a.point.x < b.point.x;
        }
        return a.point.y < b.point.y;
    }); 
} 

void SweepLine::addEvent(int index) {
   activeSegments.push_back(index); 
}

void SweepLine::removeEvent(int index){
    auto it = std::find(activeSegments.begin(), activeSegments.end(), index);
    if (it != activeSegments.end()) activeSegments.erase(it);
}

void SweepLine::setIsInside(bool isInside){
    this->inside = isInside;
}

bool SweepLine::getIsInside(){
    return this->inside;
}

void SweepLine::clearArrays(){
    events.clear();
    activeEvents.clear();
    activeSegments.clear();
}

bool intersection (Point point, SIDE side) {
    Point p1 = side.first;
    Point p2 = side.second;

    if ((p1.y > point.y) == (p2.y > point.y)) {
        return false; 
    }

    float xIntersection = p1.x + (point.y - p1.y) * (p2.x - p1.x) / (p2.y - p1.y);

    return xIntersection > point.x;
}

void SweepLine::processEvents() {
	for (int i = 0; i < events.size(); i++) {
		if (events[i].isStart) {
			addEvent(events[i].index);
		} else {
			removeEvent(events[i].index);
		}

		for (auto &point : points) {
			int cross = 0; 
			for (const auto &index : activeSegments) {
				const auto &side = activeEvents[index];

				if (intersection(point, side)) {
					cross++;
				}
			}

			if (cross % 2 != 0) {
				point.polygonIndex.push_back(polygonId+1);
			}
		}
	}
}


