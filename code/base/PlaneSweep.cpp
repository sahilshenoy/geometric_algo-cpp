#include "PlaneSweep.h"

// Helper function to find the orientation of the ordered triplet (p, q, r)
int orientation(const Point& p, const Point& q, const Point& r) {
    float val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;
    return (val > 0) ? 1 : 2;
}

// Helper function to check if point q lies on line segment 'pr'
bool onSegment(const Point& p, const Point& q, const Point& r) {
    if (q.x <= std::max(p.x, r.x) && q.x >= std::min(p.x, r.x) &&
        q.y <= std::max(p.y, r.y) && q.y >= std::min(p.y, r.y))
        return true;
    return false;
}

// Function to check if two line segments intersect
bool LineSegment::intersects(const LineSegment& other) const {
    Point p1 = this->p1, q1 = this->p2;
    Point p2 = other.p1, q2 = other.p2;

    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    if (o1 != o2 && o3 != o4)
        return true;

    if (o1 == 0 && onSegment(p1, p2, q1)) return true;
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;

    return false;
}

// Constructor to initialize the plane sweep algorithm with the segments
PlaneSweep::PlaneSweep(const std::vector<LineSegment>& segments) : segments(segments) {
    for (size_t i = 0; i < segments.size(); ++i) {
        events.emplace_back(segments[i].p1, 0, i);
        events.emplace_back(segments[i].p2, 1, i);
    }
    std::sort(events.begin(), events.end());
}

// Function to find intersections using the plane sweep algorithm
std::vector<std::pair<Point, Point>> PlaneSweep::findIntersections() {
    std::vector<std::pair<Point, Point>> intersections;

    for (const auto& event : events) {
        if (event.type == 0) {
            activeSegments.insert(event.segmentIndex);
            auto it = activeSegments.find(event.segmentIndex);

            if (it != activeSegments.begin()) {
                auto prev = std::prev(it);
                if (segments[*prev].intersects(segments[*it])) {
                    intersections.push_back({segments[*prev].p1, segments[*prev].p2});
                    intersections.push_back({segments[*it].p1, segments[*it].p2});
                }
            }

            auto next = std::next(it);
            if (next != activeSegments.end()) {
                if (segments[*it].intersects(segments[*next])) {
                    intersections.push_back({segments[*it].p1, segments[*it].p2});
                    intersections.push_back({segments[*next].p1, segments[*next].p2});
                }
            }
        } else {
            auto it = activeSegments.find(event.segmentIndex);

            if (it != activeSegments.begin() && std::next(it) != activeSegments.end()) {
                auto prev = std::prev(it);
                auto next = std::next(it);
                if (segments[*prev].intersects(segments[*next])) {
                    intersections.push_back({segments[*prev].p1, segments[*prev].p2});
                    intersections.push_back({segments[*next].p1, segments[*next].p2});
                }
            }

            activeSegments.erase(event.segmentIndex);
        }
    }

    return intersections;
}