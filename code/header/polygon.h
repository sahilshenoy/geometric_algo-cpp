#include<vector.h>
#include<point.h>
#include<list>

template<class T, size_t dim>
struct Vertex{
    ashmit::Vector<T,dim> point;
    Vertex* next;
    Vertex* prev;

     Vertex(ashmit::Vector<T,dim>&_point, Vertex<T,dim>* _next, Vertex<T,dim>* _prev)
     :point(_point),next(_next),prev(_prev){}
};
template<class T, size_t dim = DIM3> 
class Polygon {
    std::vector<Vertex<T, dim>> vertex_list;
    public:
    Polygon(std::list<ashmit::Vector<T,dim>>&points){
        const int size = points.size();
         
         if(size<3){
            std:: cout << "Not enough points to construct a polygon" << "\n";
            return;
         }
         for(auto _point: points){
            vertex_list.push_back(Vertex(_point));
         }
         for(size_t i = 0; i < size ; i++){
            vertex_list[i].next = vertex_list[(i+1)%size];
            if(i!=0){
                vertex_list[i].prev = &vertex_list[i-1];
            }
            else{
                vertex_list[i].prev = &vertex_list[size-1];
            }
         }
    }

};

typedef Polygon<float,DIM2> Polygons2D;
typedef Polygon<float,DIM3> Polygons3D;



