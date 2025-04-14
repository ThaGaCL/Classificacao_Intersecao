#include "rayCasting.h"

void rayCasting::setIsInside(bool isInside){
    this->inside = isInside;
}

bool rayCasting::getIsInside(){
    return this->inside;
}

bool intersection(Point point, SIDE side) {
    Point p1 = side.first;
    Point p2 = side.second;

    if (p1.y == p2.y) return false;

    if ((p1.y > point.y) == (p2.y > point.y))
        return false;

    float xIntersect = p1.x + (point.y - p1.y) * (p2.x - p1.x) / (p2.y - p1.y);
    return xIntersect > point.x;
}

bool polygonHasPoint(Point point, int polygonId) {
    return std::find(point.polygonIndex.begin(), point.polygonIndex.end(), polygonId) != point.polygonIndex.end();
}

void rayCasting::processEvents() {
    int cross;
    for (int i = 0; i < points.size(); i++){
        cross = 0;
        if (polygonHasPoint(points[i], polygonId + 1))
            continue;

        for (auto &side : sides){
            if ((side.first.x == points[i].x && side.first.y == points[i].y) || (side.second.x == points[i].x && side.second.y == points[i].y)){
                points[i].polygonIndex.push_back(polygonId + 1);
                cross = 0;
                break;
            }

            if (intersection(points[i], side)){
                cross++;
            }
        }

        if (cross % 2 == 1)
        {
            points[i].polygonIndex.push_back(polygonId + 1);
        }
    }
}


