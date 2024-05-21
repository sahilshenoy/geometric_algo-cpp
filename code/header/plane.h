#include<bits/stdc++.h>
#include<vector.h>

namespace ashmit{
    template<class coord_type>
    class Plane{
        Vector3f normal;
        float d =0;

        public:
            Plane(){}
            Plane(Vector3f &_normal,float _constant):normal(_normal),d(_constant){
                normal.normalize();
            }
            Plane(Point3d& p1, Point3d& p2, Point3d& p3){
                auto v12 = p2-p1;

                auto v13 = p3-p1;
                normal = crossProduct3D(v12,v13);
                normal.normalize();
                d = dotProduct(normal,p1);

            }

            Vector3f getNormal() const {
                return normal;
            }
    };

    typedef Plane<float> Planef;
}