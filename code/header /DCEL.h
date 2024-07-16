#ifndef DCEL_H
#define DCEL_H

#include <vector>
#include <iostream>

struct Vertex;
struct HalfEdge;
struct Face;

struct Vertex {
    float x, y;
    HalfEdge* incidentEdge;

    Vertex(float x = 0, float y = 0) : x(x), y(y), incidentEdge(nullptr) {}
};

struct HalfEdge {
    Vertex* origin;
    HalfEdge* twin;
    HalfEdge* next;
    HalfEdge* prev;
    Face* incidentFace;

    HalfEdge() : origin(nullptr), twin(nullptr), next(nullptr), prev(nullptr), incidentFace(nullptr) {}
};

struct Face {
    HalfEdge* outerComponent;
    std::vector<HalfEdge*> innerComponents;

    Face() : outerComponent(nullptr) {}
};

class DCEL {
public:
    std::vector<Vertex*> vertices;
    std::vector<HalfEdge*> halfEdges;
    std::vector<Face*> faces;

    ~DCEL();
    void addVertex(float x, float y);
    void addEdge(Vertex* v1, Vertex* v2);
    void printDCEL() const;
};

#endif // DCEL_H