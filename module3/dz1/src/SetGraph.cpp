//
// Created by Родион Фаррахов on 27.05.2018.
//

#include "../include/SetGraph.h"

SetGraph::SetGraph ( unsigned int count ) {
    verticesCount = count;
    in.resize(count);
    out.resize(count);
}

SetGraph::SetGraph ( IGraph& graph ) {
    verticesCount = graph.VerticesCount();
    in.resize(verticesCount);
    out.resize(verticesCount);

    for (int i = 0; i < verticesCount; ++i) {
        vector<int> vertices;
        graph.GetNextVertices(i ,vertices);
        for ( int j : vertices ) {
            AddEdge(i, j);
        }
    }
}

void SetGraph::AddEdge ( int from, int to) {
    in[from].insert(to);
    out[to].insert(from);
}

unsigned int SetGraph::VerticesCount () const {
    return verticesCount;
}

void SetGraph::GetNextVertices ( int vertex, std::vector<int>& vertices ) const {
    vertices.clear();

    for ( int i : out[vertex] ) {
        vertices.push_back( i );
    }
}

void SetGraph::GetPrevVertices ( int vertex, std::vector<int>& vertices ) const {
    vertices.clear();

    for ( int i : in[vertex] ) {
        vertices.push_back( i );
    }
}
