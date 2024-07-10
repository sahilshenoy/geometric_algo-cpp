#include <iostream>
#include 'Polygon.h'

int main() {
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

    return 0;
}