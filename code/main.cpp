#include <iostream>
#include 'Polygon.h'

int main() {
    // POLYGON PARITIONING BY EAR CLIPPING METHOD
    /*std::vector<Point> points = {
        {0, 0}, {5, 0}, {6, 2}, {3, 5}, {0, 3}
    };

    Polygon polygon(points);
    auto triangles = polygon.triangulate();

    for (const auto& triangle : triangles) {
        std::cout << "Triangle: ";
        for (const auto& point : triangle) {
            std::cout << "(" << point.x << ", " << point.y << ") ";
        }
        std::cout << std::endl;
    }*/
   // MONOTONE POLYGON PARTITIONING 
   /*std::vector<Point> points = {
        {0, 0}, {5, 0}, {6, 2}, {3, 5}, {0, 3}
    };

    MonotonePolygon polygon(points);
    auto triangles = polygon.partitionAndTriangulate();

    for (const auto& triangle : triangles) {
        std::cout << "Triangle: ";
        for (const auto& point : triangle) {
            std::cout << "(" << point.x << ", " << point.y << ") ";
        }
        std::cout << std::endl;
    }*/
   // LINE SEGEMENT INTERSECTION 
   /*
   LineSegment segment1(Point(1, 1), Point(10, 1));
    LineSegment segment2(Point(1, 2), Point(10, 2));

    if (segment1.intersects(segment2)) {
        std::cout << "The segments intersect." << std::endl;
    } else {
        std::cout << "The segments do not intersect." << std::endl;
    }

    LineSegment segment3(Point(10, 0), Point(0, 10));
    LineSegment segment4(Point(0, 0), Point(10, 10));

    if (segment3.intersects(segment4)) {
        std::cout << "The segments intersect." << std::endl;
    } else {
        std::cout << "The segments do not intersect." << std::endl;
    }
   */
  // PLANE SWEEP ALGORITHM
  /*    std::vector<LineSegment> segments = {
        LineSegment(Point(1, 1), Point(10, 1)),
        LineSegment(Point(1, 2), Point(10, 2)),
        LineSegment(Point(10, 0), Point(0, 10)),
        LineSegment(Point(0, 0), Point(10, 10))
    };

    PlaneSweep sweep(segments);
    auto intersections = sweep.findIntersections();

    for (const auto& intersection : intersections) {
        std::cout << "Intersection between segments: "
                  << "(" << intersection.first.x << ", " << intersection.first.y << ") and "
                  << "(" << intersection.second.x << ", " << intersection.second.y << ")" << std::endl;
    }*/
    return 0;
}