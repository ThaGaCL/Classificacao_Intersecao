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

void SweepLine::processEvents() {
    for (int i = 0; i < events.size(); i++){
        if (events[i].isStart){
            addEvent(events[i].index);
        }
        else {
            removeEvent(events[i].index);
        }

        int cross = 0;
        for (const auto &index : activeSegments) {
            const auto &side = activeEvents[index];
            printf("side: (%d, %d) (%d, %d)\n", side.first.x, side.first.y, side.second.x, side.second.y);
            printf("point: (%d, %d)\n", point.x, point.y);
            if (point.x >= side.first.x && point.x <= side.second.x && point.y >= std::min(side.first.y, side.second.y) && point.y <= std::max(side.first.y, side.second.y)){
                cross++;
            }
        }

        printf("cross: %d\n", cross);

        if (cross % 2 != 0) {
            setIsInside(true);
            break;
        }
    }

}


