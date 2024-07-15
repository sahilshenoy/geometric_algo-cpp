#ifndef PLANESWEEP_H
#define PLANESWEEP_H

#include <set>
#include <vector>
#include <algorithm>

struct Point {
    float x, y;
    Point(float x = 0, float y = 0) : x(x), y(y) {}
    bool operator<(const Point& other) const {
        return x < other.x || (x == other.x && y < other.y);
    }
};

struct Event {
    Point p;
    int type; // 0 for left endpoint, 1 for right endpoint
    size_t segmentIndex;
    Event(Point p, int type, size_t segmentIndex) : p(p), type(type), segmentIndex(segmentIndex) {}
    bool operator<(const Event& other) const {
        return p < other.p;
    }
};

class LineSegment {
public:
    Point p1, p2;
    LineSegment(const Point& p1, const Point& p2) : p1(p1), p2(p2) {}
    bool intersects(const LineSegment& other) const;
};

class PlaneSweep {
public:
    PlaneSweep(const std::vector<LineSegment>& segments);
    std::vector<std::pair<Point, Point>> findIntersections();

private:
    std::vector<LineSegment> segments;
    std::vector<Event> events;
    std::set<size_t> activeSegments;

    bool doIntersect(const LineSegment& s1, const LineSegment& s2);
    Point intersectionPoint(const LineSegment& s1, const LineSegment& s2);
};

#endif // PLANESWEEP_H