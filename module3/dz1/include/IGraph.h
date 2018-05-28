//
// Created by Родион Фаррахов on 27.05.2018.
//

#ifndef DZ1_IGRAPH_H
#define DZ1_IGRAPH_H

#include <vector>

using std::vector;

struct IGraph {
    virtual ~IGraph () {}

    // Добавление ребра от from к to.
    virtual void AddEdge ( int from, int to ) = 0;

    virtual unsigned int VerticesCount () const  = 0;

    virtual void GetNextVertices ( int vertex, vector<int>& vertices ) const = 0;
    virtual void GetPrevVertices ( int vertex, vector<int>& vertices ) const = 0;
};

#endif //DZ1_IGRAPH_H
