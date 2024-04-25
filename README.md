# What is Computational Geometry ?

Computational geometry is a branch of **computer science that is dedicated to the study of algorithms** which can be stated in terms of geometry. One of the most common use cases of computational geometry is collision detection in computer games

Suppose there are two objects, for the two objects to collide, the co-ordinates of both the objects need to overlap, this condition can be called as collision

This is the first and most basic computational geometry, that is to check whether two objects in 2D or 3D Space have the same co-ordinate, if they do have the same co-ordinate, they are said to be in collision

For collision detection, we use two objects, of a simple shape, let's say a cube, if these two shapes collide, then we can say that the collision occured, however we need to know that such simple shapes may cause computational overhead, for this we prefer using convex hull

Convex Hull - A convex hull or convex envelope is the closure of a shape with the smallest convex set that can contain it

### Applications of Computational Geometry Algorithms

- Computer Graphics
- CAD
- GPS / Navigation Systems etc

### Basic Terms in Computational Geometry

### Point

A point represents a position in the space, it has values which we refer to as co-ordinates, which represent a length between this point and the reference point ( we usually take the reference point to be as the origin )

In 2D Space a point will have two values

- X co-ordinate
- Y co-orindate

In 3D Space it would have another co-ordinate which will the Z co-ordinate, these co-ordinate are basically the length from the reference point, we use

### Line

Line is a 1D figure, which is made up infinite consecutive points, lines can be straight or curved, however for our simplicity line means straight line

**Difference between Line and Line Segment**

Line has infinity as ends, there is no mention of it's start or end, line segment on the other hand has two points that define the bounds of the line, a line segment is made up of two points and are connected

**Line Ray and Line Segment**

A line which only has one point defined, is called a ray, it is usually a line that projected from a point and is pointing towards infinity

### Polygon

Polygon is a planar figure, that is bounded by line segments, do note for a shape to be a polygon, all the line segments should be in the same plane

The line segments of the polygon are referred to as edges, the points of connection are referred to as vertices and the area enclosed is the polygon

There are two major types of polygons

- Simple Polygon
    - Simple Polygons are polygons which do not have any intersecting lines forming the polygon boundary
    - They are of further two types
        - Convex Polygon
            - Every internal angle of the polygon is convex ( less than 180 degree )
        - Concave Polygon
            - Atleast one internal angle of the polygon is exceeding 180 degrees
- Complex Polygon
    - Complex Polygons are polygons which have a intersecting line segments forming the polygon boundary

# Introduction to Vector Algebra

**Categories of Physical Properites**

- Scalars
    - These are single value properties, only a numerical value is enough, for e.g - Mass, Temperature, Distance
- Vectors
    - These are entities which need more than one parameter to be defined, for example velocity needs 2 parameters to be defined, one is the speed and the other is the direction in which the object is moving , these are multi-value properties

### Equivalent Vectors

Two vectors are said to be equivalent in nature, if they have the same magnitude and are in the same direction. We can notate vectors in the following ways

- u ( 4, 3 )
- u ( 4i + j )

### Vector Addition

Suppose there is an object, which has a velocity of 4 units in X direction and 3 units in Y direction and there is another object which has a velocity of 6 units in X direction and 1 unit in Y direction, vector addition of these two objects will simply be the addition of the components of these 2 vectors

that is if we have two vectors

|v| = √(v₁² + v₂²)

### Vector Subtraction

We consider subtration as the addition of a negative vector, that is we are adding a negative vector to a positive vectors instead of subtracting a positive vector from another positive vector,

we can say u  - v can be written as u + (-v)

### Vector Multiplication

For vector multiplication, we are only considering multiplication with scalars, for example we have a vector v and a scalar k, then

k * v(u₁, u₂, u₃) = v(ku₁, ku₂, ku₃)


This only changes the magnitude of the vector, this does not change the direction of the vector

### Magnitude of a vector

Suppose we have vector v which is v(u1,u2), the magnitude of this vector will be the square root of the sum of square of component of the vector

|v| = √(v₁² + v₂²)


Note that the magnitude of two vectors is always going to be a positive value

### Vector Dot Product

Dot product of two vectors is defined as 

$|v| = |u1|*|u2|*cos(@)$ Dot product of two vectors gives us the scalar value, the result of this can be positive or negative depending upon the angle between the components of the vector, since cosine function is positive in the first quadrant, negative in the second

If two vectors are in the same direction, then the dot product will be 

v(u₁, u₂, u₃) * w(v₁, v₂, v₃) = u₁*v₁ + u₂*v₂ + u₃*v₃


### Vector Cross Product

Cross product of two vectors, results in a new vector that is perpendicular to the direction of both the vectors that are being multiplied

u * v = |u| * |v| * sin(θ)


Cross product is generally considered for 3D spaces

Another way of calculating cross product is for 2D and 3D cases is by taking determinant of a matrix containing both of the vectors

u(u₁, u₂) * v(v₁, v₂) = u₁ * v₂ - u₂ * v₁
 ( Determinant of the matrix formed by the vectors )

## Implementing the Vector Class

Vector that we are going to define in code is an entity whose elements are n tuples of numbers from the domain of real numbers. A vector v is thus given as v = (v1,v2,v3...)

### Position Vector

A point is defined as a position in space, This space is defined by the co-ordinate system which has a reference point or origin

Points in N dimension can be defined by X1,X2,X3,X4...Xn wherer Xi is the distance of the point from the axis

**Difference between Direction Vector and Position Vector**

- Directional Vectors - Has magnitude and direction
- Position Vector - is a uniquely defined reference to the origin

The vector class that we are going to define should be a generic implementation
