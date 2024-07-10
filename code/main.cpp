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

    return 0;
}