#include<bits/stdc++.h>
#include<point.h>
#include<vector.h>
#include<geoUtils.h>
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
}