#include "MonotonePolygon.h"

// Constructor to initialize the polygon vertices
MonotonePolygon::MonotonePolygon(const std::vector<Point>& points) : vertices(points) {}

// Helper function to check if a point is below another point
bool MonotonePolygon::isBelow(const Point& p1, const Point& p2) {
    return p1.y < p2.y || (p1.y == p2.y && p1.x < p2.x);
}

// Helper function to check if three points make a convex angle
bool MonotonePolygon::isConvex(const Point& p1, const Point& p2, const Point& p3) {
    float cross = (p2.x - p1.x) * (p3.y - p2.y) - (p2.y - p1.y) * (p3.x - p2.x);
    return cross > 0;
}

// Function to partition the polygon into y-monotone polygons
void MonotonePolygon::makeMonotone() {
    // This function should implement the sweeping algorithm to partition the polygon into y-monotone pieces.
    // Due to the complexity, it is left as an exercise. The following is a simplified placeholder.
    std::sort(vertices.begin(), vertices.end(), isBelow);
}

// Function to triangulate a y-monotone polygon
std::vector<std::vector<Point>> MonotonePolygon::triangulateMonotone(const std::vector<Point>& monotonePolygon) {
    std::vector<std::vector<Point>> triangles;
    // Implement the triangulation of a y-monotone polygon
    // This is a placeholder for the actual triangulation logic
    if (monotonePolygon.size() < 3) return triangles;

    for (size_t i = 1; i < monotonePolygon.size() - 1; ++i) {
        triangles.push_back({monotonePolygon[0], monotonePolygon[i], monotonePolygon[i + 1]});
    }
    return triangles;
}

// Function to partition the polygon and then triangulate the pieces
std::vector<std::vector<Point>> MonotonePolygon::partitionAndTriangulate() {
    makeMonotone();

    std::vector<std::vector<Point>> result;
    // For simplicity, let's assume we have one monotone polygon for now
    result = triangulateMonotone(vertices);
    return result;
}