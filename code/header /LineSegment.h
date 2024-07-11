#ifndef LINESEGMENT_H
#define LINESEGMENT_H

#include <iostream>

struct Point {
    float x, y;
    Point(float x = 0, float y = 0) : x(x), y(y) {}
};

class LineSegment {
public:
    Point p1, p2;
    LineSegment(const Point& p1, const Point& p2) : p1(p1), p2(p2) {}

    bool intersects(const LineSegment& other) const;

private:
    int orientation(const Point& p, const Point& q, const Point& r) const;
    bool onSegment(const Point& p, const Point& q, const Point& r) const;
};

#endif // LINESEGMENT_H