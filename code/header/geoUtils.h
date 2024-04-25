#include<bits/stdc++.h>
#include<point.h>
#include<vector.h>
namespace ashmit { 
    double areaTriangle2D(const Point2d& a, const Point2d& b , const Point2d& c); 

    int orientation2D(const Point2d&a, const Point2d&b, const Point2d&c);
    // Predicate to determine whether the point C is to the left of the segment [AB]
    bool left(const Point2d &a, const Point2d& b, const Point2d &c);
    // Predicate to determine whether the point C is the right of the segment
    bool right(const Point2d &a, const Point2d &b, const Pont2d &c);
    // to determine whether the point C is beyond 
    bool leftOrBeyond(const Point2d& a, const Point2d &b, const Point2d &c);
    bool rightOrBeyond(const Point2d& a, const Point2d& b, const Point2d &c);
    // to determine whether the point C is between
    bool leftOrBetween(const Point2d &a, const Point2d &b, const Point2d &c);
}