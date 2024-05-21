#include<bits/stdc++.h>
#include<core.h>
namespace ashmit { 
    #define DIM2 2
    #define DIM3 3

    #define X 0
    #define Y 1
    #define Z 2

    template<class coordinate_type, size_t dimension = DIM3>
    // Vector class
    class Vector{  
        // assertion for the class
        static_assert(std::is_arithmetic<coordinate_type>,"Class can only store integral or floating point");
        static_assert(dimension>=DIM2,"Dimension should be more than 2");
        // co-ordinate array
        std::array<coordinate_type,dimension> coords;
        // FRIEND FUNCTION DOT PRODUCT
        template<class coordinate_type,size_t dimension>
        friend float dotProduct(const Vector<coordinate_type,dimension>&v1,const Vector<coordinate_type,dimension>&v2);

    public:
        // default constructor
        Vector() {}
        // parameter constructor to create any dimension
        Vector(std::array<coordinate_type,dimension>_coords):coords(_coords){}
        // parameter constructor to create 3 dimension 
        Vector(coordinate_type _x, coordinate_type _y, coordinate_type _z) : coords({_x,_y,_z}) {}
        // parameter constructor to create 2 dimension 
        Vector(coordinate_type _x, coordinate_type _y) : coords({_x,_y}) {}   

        // EQUALITY CHECK 
        bool operator==(const Vector<coordinate_type,dimension>&);
        // NOT EQUAL CHECK
        bool operator!=(const Vector<coordinate_type,dimension>&);
        // ADDITION
        Vector<coordinate_type, dimension> operator+(const Vector<coordinate_type, dimension> &);
        // SUBTRACTION
        Vector<coordinate_type,dimension> operator-(const Vector<coordinate_type,dimension>&);
        // LESS THAN OPERATOR 
        bool operator <(const Vector<coordinate_type,dimension>&);
        // GREATER THAN OPERATOR
        bool operator >(const Vector<coordinate_type,dimension>&);
        // INDEXING OPERATOR 
        coordinate_type operator[](int)const;
        // ASSIGN FUNCTION 
        void assign(int dim,coordinate_type value);
        // MAGNITUDE FUNCTION
        float magnitude() const;
        // NORMALIZE FUNCTION
        void normalize();
    };
    typedef Vector<float,DIM2> Vector2f;
    typedef Vector<float,DIM3> Vector3f;
    // EQUALITY CHECK OPERATOR
    template<class coordinate_type, size_t dimension>
    inline bool Vector<coordinate_type,dimension>::operator==(const Vector<coordinate_type,dimension>&){
        for(size_t=0;i<dimension;i++){
            if(isEqualD(coords[i],_other.coords[i])){
                return false;
            }
        }
        return true;
    }
    // NOT EQUAL CHECK OPERATOR
    template<class coordinate_type,size_t dimension>
    inline bool Vector<coordinate_type,dimension>::operator!=(const Vector<coordinate_type,dimension>&){
        return !(*this==_other);
    }
    // ADDITION OPERATOR
    template<class coordinate_type, size_t dimension>
    inline Vector<coordinate_type,dimension> Vector<coordinate_type,dimension>::operator+(const Vector<coordinate_type,dimension>&){
        std::array<coordinate_type,dimension> temp_array;
        for (size_t i = 0; i < dimension; i++){
            temp_array[i]=coords[i] + _other.coords[i];
        }
        
        return Vector<coordinate_type,dimension>(temp_array);
    }
    // SUBTRACTION OPERATOR
    template<class coordinate_type, size_t dimension>
    inline Vector<coordinate_type,dimension> Vector<coordinate_type,dimension>::operator-(const Vector<coordinate_type,dimension>&){
        std::array<coordinate_type,dimension> temp_array;
        for (size_t i = 0; i < dimension; i++){
            temp_array[i]=coords[i] - _other.coords[i];
        }
        
        return Vector<coordinate_type,dimension>(temp_array);
    }
    // LESS THAN OPERATOR 
    template<class coordinate_type, size_t dimension>
    inline bool Vector<coordinate_type,dimension>::operator<(const Vector<coordinate_type,dimension>&){
        for (size_t i = 0; i < dimension; i++){
            if(this->coords[i]<_other.coords[i]){
                return true;
            }
            else if(this->coords[i]>_other.coords[i]){
                return false;
            }
        }
        return false;
    }
    // GREATER THAN OPERATOR
    template<class coordinate_type, size_t dimension>
    inline bool Vector<coordinate_type,dimension>::operator>(const Vector<coordinate_type,dimension>& _other){
        for (size_t i = 0; i < dimension; i++){
            if(this->coords[i]>_other.coords[i]){
                return true;
            }
            else if(this->coords[i]<_other.coords[i]){
                return false;
            }
        }
        return false;
    }
    // INDEXING OPERATOR 
    template<class coordinate_type, size_t dimension>
    inline coordinate_type Vector<coordinate_type,dimension>::operator[](int _index) const{
        if(_index>=coords.size()){
            std::cout<<"Index out of bound";
            return coordinate_type();
        }
        return coords[_index];
    }
    // ASSIGN FUNCTION
    template<class coordinate_type, size_t dimension>
    inline void Vector<coordinate_type,dimension>::assign(int dim,coordinate_type value){
        if(_index>=coords.size()){
            std::cout << "Index out of bound";
        }
        coords[dim]=value;
    }
    // MAGNITUDE OF VECTOR FUNCTION 
    template<class coordinate_type, size_t dimension>
    inline float Vector<coordinate_type, dimension>::magnitude() const{
        float value = 0.0f;
        for (size_t i = 0; i < dimension; i++)
        {
            value += pow(coords[i],2.0);
        }
        return sqrt(value);
        
    }
    // NORMALIZE FUNCTION
    template<class coordinate_type, size_t dimension>
    inline void Vector<coordinate_type,dimension>::normalize() {
        auto mag = magnitude();

        for (size_t i = 0; i < dimension; i++)
        {
            assign(i,coords[i] / mag);
        }
        
    }
    // DOT PRODUCT OF VECTORS
    template<class coordinate_type, size_t dimension>
    float dotProduct(const Vector<coordinate_type,dimension>&v1,const Vector<coordinate_type,dimension>&v2){
        if(v1.coords.size()!=v2.coords.size()){
            return FLT_MIN;
        }   
        float product = 0.0;

        for (size_t i = 0; i < dimension; i++)
        {
            product+=v1[i]*v2[i]; 
        }
        return product;
    }
    float crossProduct2D(Vector2f v1,Vector2f v2);
    Vector3f crossProduct3D(Vector3f v1, Vector3f v2);
    float scalerTripleProduct(Vector3f v1, Vector3f v2, Vecto3f v3); 
}