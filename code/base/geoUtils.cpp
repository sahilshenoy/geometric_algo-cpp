#include<bits/stdc++.h>
#include<geoUtils.h>
#include<vector.h>
#include<core.h>
double ashmit::areaTriangle2D(const Point2d& a, const Point2d& b, const Point2d &c){
    auto AB = b - a;
    auto AC = c - a;
    auto result = crossProduct2D(AB,AC);
    return result/2;
}

double ashmit::orientation2d(const Point2d& a, const Point2d& b, const Point2d& c){
    auto area = areaTriangle2D(a,b,c);

    if(area>  0 && area < TOLERANCE){
        area=0;
    }
    if(area<0 && area > TOLERANCE){
        area=0;
    }
    Vector2f ab  = b-a;
    Vector2f ac = c-a;
    if(area>0){
        return LEFT;
    }
    if(area<0){
        return RIGHT;
    }
    if(ab[X]*ac[X]<0 || ab[Y]*ac[Y]<0){
        return BEHIND;
    }
    if(ab.magnitude() < ac.magnitude()){
        return BEYOND;
    }
    if(a==c){
        return ORIGIN;
    }
    if(b==c){
        return DESTINATION;
    }
    return BETWEEN;
}

bool ashmit::left(const Point3d&a,const Point3d&b, const Point3d&c){
    return orientation2D(a,b,c) == RELATIVE_POSITION::LEFT;
}
bool ashmit::left(const Point3d&a,const Point3d&b, const Point3d&c){
    return orientation2D(a,b,c) == RELATIVE_POSITION::RIGHT;
}
bool ashmit::leftOrBeyond(const Point3d&a,const Point3d&b, const Point3d&c){
    int position = orientation2D(a,b,c);
    return (position == RELATIVE_POSITION::LEFT || RELATIVE_POSITION::BEYOND)
}
bool ashmit::rightOrBeyond(const Point3d&a,const Point3d&b, const Point3d&c){
    int position = orientation2D(a,b,c);
    return (position == RELATIVE_POSITION::RIGHT || RELATIVE_POSITION::BEYOND)
}
bool ashmit::leftOrBetween(const Point3d&a,const Point3d&b, const Point3d&c){
    int position = orientation2D(a,b,c);
    return (position == RELATIVE_POSITION::LEFT || RELATIVE_POSITION::BETWEEN)
}

bool ashmit::colinear(const Vector3f&v1,const Vector3f&v2){
    float value = scalerTripleProduct(a,b,c);

    return isEqualD(value,ZERO);
}

bool ashmit::coplanar(const Point3d&a, const Point3d&b, const Point3d&c,const Point3d&d){
    auto AB = a-b;
    auto AC = a-d;
    auto AD = d-a;
    return coplanar(AB,AC,AD);
}