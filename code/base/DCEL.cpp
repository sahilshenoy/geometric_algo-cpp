#include "DCEL.h"

DCEL::~DCEL() {
    for (auto vertex : vertices) delete vertex;
    for (auto edge : halfEdges) delete edge;
    for (auto face : faces) delete face;
}

void DCEL::addVertex(float x, float y) {
    vertices.push_back(new Vertex(x, y));
}

void DCEL::addEdge(Vertex* v1, Vertex* v2) {
    HalfEdge* e1 = new HalfEdge();
    HalfEdge* e2 = new HalfEdge();

    e1->origin = v1;
    e2->origin = v2;

    e1->twin = e2;
    e2->twin = e1;

    halfEdges.push_back(e1);
    halfEdges.push_back(e2);

    v1->incidentEdge = e1;
    v2->incidentEdge = e2;

    // Set the next and prev pointers
    if (v1->incidentEdge->next == nullptr) {
        v1->incidentEdge->next = e1;
        e1->prev = v1->incidentEdge;
    } else {
        e1->next = v1->incidentEdge->next;
        v1->incidentEdge->next->prev = e1;
        v1->incidentEdge->next = e1;
        e1->prev = v1->incidentEdge;
    }

    if (v2->incidentEdge->prev == nullptr) {
        v2->incidentEdge->prev = e2;
        e2->next = v2->incidentEdge;
    } else {
        e2->prev = v2->incidentEdge->prev;
        v2->incidentEdge->prev->next = e2;
        v2->incidentEdge->prev = e2;
        e2->next = v2->incidentEdge;
    }
}

void DCEL::printDCEL() const {
    std::cout << "Vertices:\n";
    for (auto vertex : vertices) {
        std::cout << "(" << vertex->x << ", " << vertex->y << ")\n";
    }

    std::cout << "HalfEdges:\n";
    for (auto edge : halfEdges) {
        std::cout << "Origin: (" << edge->origin->x << ", " << edge->origin->y << ") ";
        if (edge->next) std::cout << "Next: (" << edge->next->origin->x << ", " << edge->next->origin->y << ") ";
        if (edge->prev) std::cout << "Prev: (" << edge->prev->origin->x << ", " << edge->prev->origin->y << ") ";
        std::cout << "\n";
    }

    std::cout << "Faces:\n";
    for (auto face : faces) {
        if (face->outerComponent) {
            std::cout << "Outer Component: (" << face->outerComponent->origin->x << ", " << face->outerComponent->origin->y << ")\n";
        }
        for (auto inner : face->innerComponents) {
            std::cout << "Inner Component: (" << inner->origin->x << ", " << inner->origin->y << ")\n";
        }
    }
}