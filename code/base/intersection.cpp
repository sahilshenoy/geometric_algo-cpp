#include<bits/stdc++.h>
#include<vector.h>
#include<core.h>
#include<line.h>
#include<point.h>
namespace ashmit{
    bool intersection(const ashmit::Point2d&a,const ashmit::Point2d&b,const ashmit::Point2d&c,const ashmit::Point2d&d){
        auto ab_c=ashmit::orientation2d(a,b,c);
        auto ab_d=ashmit::orientation2d(a,b,d);
        auto cd_a=ashmit::orientation2d(c,b,d);
        auto cd_b=ashmit::orientation2d(c,d,b);

        if(ab_c==BETWEEN || ab_c == ORIGIN || ab_c==DESTINATION
          || ab_d==BETWEEN || ab_d == ORIGIN || ab_d==DESTINATION
          || cb_a==BETWEEN || cd_a == ORIGIN || cd_a==DESTINATION
          || cd_b==BETWEEN || cd_b == ORIGIN || cd_b==DESTINATION){
            return true;
          }
        return _xor(ab_c==LEFT, ab_d==LEFT)&& _xor(cd_a==LEFT,cd_b==LEFT);
    }
    bool intersectionPoint(const ashmit::Point2d&a,const ashmit::Point2d&b,const ashmit::Point2d&c,const ashmit::Point2d&d){
        Vector2f AB = b-a;
        Vector2f CD = d-c;
        Vector2f n(CD[Y],-CD[X]);

        auto deno = dotProduct(n,AB);
        if(isEqualD(deno,ZERO)){
            auto AC = c-a;
            auto num = dotProduct(n,AC);
            auto t = num/deno;
            auto x = a[X]+t*AB[X];
            auto y = a[Y]+t*AB[Y];
            intersection.assign(X,x);
            intersection.assign(Y,x);
            
        }
        else{
            return false;
        }
    }
    bool intersectionLine(const ashmit::Line2D&l1,const ashmit::Line2D&l2, ashmit::Point2d& intersection){
        auto l1_start=l1.getPoint();
        auto l1_end=l1_start+l1.getDir();
        auto l2_start=l2.getPoint();
        auto l2_end=l2_start+l2.getDir();     
        return intersectionPoint(l1_start,l1_end,l2_end,intersection); 
    }
}