#include<bits/stdc++.h>
#include<angle.h>

float ashmit::AngleLines2D(const Line2D&l1, const Line2D&l2){
    auto l1_mag = l1.getDir().magnitude();
    auto l2_mag = l1.getDir().magnitude();
    
    auto dot = dotProduct(l1.getDir(),l2.getDir());

    auto theta = acos(fabs(dot)/(l1_mag*l2_mag));
    return RadianceToDegrees(theta);
}

float ashmit::AngleLines3D(const Line3D&l1, const Line3D&l2){
    auto l1_mag = l1.getDir().magnitude();
    auto l2_mag = l1.getDir().magnitude();
    
    auto dot = dotProduct(l1.getDir(),l2.getDir());

    auto theta = acos(fabs(dot)/(l1_mag*l2_mag));
    return RadianceToDegrees(theta);
}

float ashmit::AngleLinesPlane(const Line3D& l1, const Planef&p1){
    auto dot = dotProduct(l1.getDir(), p.getNormal());
    auto theta = acos(fabs(dot));
    auto angle = RadianceToDegrees(theta);
    return 90-angle; 
}