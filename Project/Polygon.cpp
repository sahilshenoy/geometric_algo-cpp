#include <omp.h>
#include "Polygon.h"

// Constructor to initialize the polygon vertices
Polygon::Polygon(const std::vector<Point>& points) : vertices(points) {}

// Helper function to check if a point is in a triangle
bool Polygon::isPointInTriangle(const Point& p, const Point& p1, const Point& p2, const Point& p3) {
    float d1 = crossProduct(Point(p.x - p1.x, p.y - p1.y), Point(p2.x - p1.x, p2.y - p1.y));
    float d2 = crossProduct(Point(p.x - p2.x, p.y - p2.y), Point(p3.x - p2.x, p3.y - p2.y));
    float d3 = crossProduct(Point(p.x - p3.x, p.y - p3.y), Point(p1.x - p3.x, p1.y - p3.y));
    return (d1 >= 0 && d2 >= 0 && d3 >= 0) || (d1 <= 0 && d2 <= 0 && d3 <= 0);
}

// Helper function to compute the cross product of two points
float Polygon::crossProduct(const Point& p1, const Point& p2) {
    return p1.x * p2.y - p1.y * p2.x;
}

// Helper function to check if three points make a convex angle
bool Polygon::isConvex(const Point& p1, const Point& p2, const Point& p3) {
    return crossProduct(Point(p2.x - p1.x, p2.y - p1.y), Point(p3.x - p2.x, p3.y - p2.y)) > 0;
}

// Helper function to check if a vertex is an ear
bool Polygon::isEar(const Point& p1, const Point& p2, const Point& p3) {
    if (!isConvex(p1, p2, p3)) return false;
    for (const auto& point : vertices) {
        if (point.x == p1.x && point.y == p1.y) continue;
        if (point.x == p2.x && point.y == p2.y) continue;
        if (point.x == p3.x && point.y == p3.y) continue;
        if (isPointInTriangle(point, p1, p2, p3)) return false;
    }
    return true;
}

// // Function to triangulate the polygon using ear clipping
// std::vector<std::vector<Point> > Polygon::triangulate() {
//     std::vector<std::vector<Point> > triangles;
//     std::vector<Point> remainingVertices = vertices;

//     while (remainingVertices.size() > 3) {
//         bool earFound = false;
//         for (size_t i = 0; i < remainingVertices.size(); ++i) {
//             size_t prev = (i + remainingVertices.size() - 1) % remainingVertices.size();
//             size_t next = (i + 1) % remainingVertices.size();
//             const Point& p1 = remainingVertices[prev];
//             const Point& p2 = remainingVertices[i];
//             const Point& p3 = remainingVertices[next];

//             if (isEar(p1, p2, p3)) {
//                 triangles.push_back({p1, p2, p3});
//                 remainingVertices.erase(remainingVertices.begin() + i);
//                 earFound = true;
//                 break;
//             }
//         }
//         if (!earFound) {
//             throw std::runtime_error("No ear found. The polygon might be degenerate or not simple.");
//         }
//     }
//     if (remainingVertices.size() == 3) {
//         triangles.push_back(remainingVertices);
//     }
//     return triangles;
// }

// Function to triangulate the polygon using parallelized ear clipping
std::vector<std::vector<Point> > Polygon::triangulate() {
    std::vector<std::vector<Point> > triangles;
    std::vector<Point> remainingVertices = vertices;

    while (remainingVertices.size() > 3) {
        bool earFound = false;
        
        #pragma omp parallel for // Parallelize the ear-checking loop
        for (size_t i = 0; i < remainingVertices.size(); ++i) {
            size_t prev = (i + remainingVertices.size() - 1) % remainingVertices.size();
            size_t next = (i + 1) % remainingVertices.size();
            const Point& p1 = remainingVertices[prev];
            const Point& p2 = remainingVertices[i];
            const Point& p3 = remainingVertices[next];

            if (isEar(p1, p2, p3)) {
                #pragma omp critical // Ensure only one thread modifies the data
                {
                    if (!earFound) {  // Make sure only one ear is found at a time
                        triangles.push_back({p1, p2, p3});
                        remainingVertices.erase(remainingVertices.begin() + i);
                        earFound = true;
                    }
                }
            }
        }
        if (!earFound) {
            throw std::runtime_error("No ear found. The polygon might be degenerate or not simple.");
        }
    }
    
    if (remainingVertices.size() == 3) {
        triangles.push_back(remainingVertices);
    }

    return triangles;
}