#include <iostream>
#include <omp.h>
#include <chrono>
#include "Polygon.h"

int main() {
    // Start measuring time
    auto start = std::chrono::high_resolution_clock::now();

    // OpenMP parallel block to confirm parallel execution
    #pragma omp parallel
    {
        #pragma omp critical
        {
            std::cout << "Thread " << omp_get_thread_num() << " is working" << std::endl;
        }
    }

    // End measuring time
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    std::cout << "Time taken: " << elapsed.count() << " seconds" << std::endl;
    
    // POLYGON PARITIONING BY EAR CLIPPING METHOD
    std::vector<Point> points = {
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
    }
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
   // DCEL REPRESENTATION 
    /*dcel.addVertex(0, 0);
    dcel.addVertex(1, 0);
    dcel.addVertex(1, 1);
    dcel.addVertex(0, 1);

    // Adding edges
    dcel.addEdge(dcel.vertices[0], dcel.vertices[1]);
    dcel.addEdge(dcel.vertices[1], dcel.vertices[2]);
    dcel.addEdge(dcel.vertices[2], dcel.vertices[3]);
    dcel.addEdge(dcel.vertices[3], dcel.vertices[0]);

    // Printing the DCEL structure
    dcel.printDCEL();*/
    // CONVEX HULL 
    /*std::vector<Point> points = {
        {0, 3}, {2, 2}, {1, 1}, {2, 1}, {3, 0}, {0, 0}, {3, 3}
    };

    std::vector<Point> hull = ConvexHull::giftWrapping(points);

    std::cout << "The points in the convex hull are:\n";
    ConvexHull::printPoints(hull);
    return 0;*/
}