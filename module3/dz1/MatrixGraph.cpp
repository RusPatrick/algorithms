//
// Created by Родион Фаррахов on 27.05.2018.
//

#include "MatrixGraph.h"

MatrixGraph::MatrixGraph ( unsigned int count ) {
    edges.resize(count);
    for (int edge = 0; edge < edges.size(); ++edge) {
        edges[edge].resize(count, false);
    }
}

MatrixGraph::MatrixGraph ( const IGraph&  graph ) {
    edges.resize(graph.VerticesCount());
    for (int i = 0; i < edges.size(); ++i) {
        edges[i].resize(graph.VerticesCount());
    }

    for (int i = 0; i < verticesCount; i++) {
        vector<int> vertices;
        graph.GetNextVertices(i, vertices);
        for (int j : vertices)
            AddEdge(i, j);
    }
}

void MatrixGraph::AddEdge ( int from, int to ) {
    edges[from][to] = true;
}

unsigned int MatrixGraph::VerticesCount () const {
    return verticesCount;
}

void MatrixGraph::GetNextVertices ( int vertex, std::vector<int>& vertices ) const {
    vertices.clear();

    for (int i = 0; i < verticesCount; ++i) {
        if ( edges[vertex][i] ) {
            vertices.push_back( i );
        }
    }
}

void MatrixGraph::GetPrevVertices ( int vertex, std::vector<int>& vertices ) const {
    vertices.clear();

    for (int i = 0; i < verticesCount; ++i) {
        if (edges[i][vertex]) {
            vertices.push_back( i );
        }
    }
}


