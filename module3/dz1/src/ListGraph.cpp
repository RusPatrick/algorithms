//
// Created by Родион Фаррахов on 27.05.2018.
//
#include "../include/ListGraph.h"

ListGraph::ListGraph ( unsigned int count ) :
    verticesCount(count),
    in(verticesCount),
    out(verticesCount)
{}

ListGraph::ListGraph ( const IGraph& graph ) :
    verticesCount(graph.VerticesCount()),
    in(verticesCount),
    out(verticesCount)
{
    for (int i = 0; i < verticesCount; ++i) {
        vector<int> vertices;
        graph.GetNextVertices(i, vertices);
        for ( int j : vertices ) {
            AddEdge( i, j );
        }
    }
}

void ListGraph::AddEdge ( int from , int to ) {
    in[to].push_back(from);
    out[from].push_back(to);
}

unsigned int ListGraph::VerticesCount () const {
    return verticesCount;
}

void ListGraph::GetNextVertices ( int vertex, std::vector<int>& vertices ) const {
    vertices = out[vertex];
}

void ListGraph::GetPrevVertices ( int vertex, std::vector<int>& vertices ) const {
    vertices = in[vertex];
}
