#ifndef MONOTONE_POLYGON_H
#define MONOTONE_POLYGON_H

#include <vector>
#include <set>
#include <algorithm>

struct Point {
    float x, y;
    Point(float x = 0, float y = 0) : x(x), y(y) {}
    bool operator<(const Point& other) const {
        return y < other.y || (y == other.y && x < other.x);
    }
};

class MonotonePolygon {
public:
    MonotonePolygon(const std::vector<Point>& points);
    std::vector<std::vector<Point>> partitionAndTriangulate();

private:
    std::vector<Point> vertices;
    void makeMonotone();
    std::vector<std::vector<Point>> triangulateMonotone(const std::vector<Point>& monotonePolygon);
    bool isConvex(const Point& p1, const Point& p2, const Point& p3);
    bool isBelow(const Point& p1, const Point& p2);
};

#endif // MONOTONE_POLYGON_H