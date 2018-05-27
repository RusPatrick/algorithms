//
// Created by Родион Фаррахов on 27.05.2018.
//

#include "ArcGraph.h"

ArcGraph::ArcGraph(unsigned int count) {
    edges.resize(count);
    verticesCount = count;
}

ArcGraph::ArcGraph(const IGraph& graph) {
    verticesCount = graph.VerticesCount();

    for ( int i = 0; i < verticesCount; ++i ) {
        vector<int> vertices;
        graph.GetNextVertices(i, vertices);
        for (int j : vertices)
            AddEdge(i, j);
    }
}

void ArcGraph::AddEdge(int from, int to) {
    for (const Edge & i : edges) {
        if (i.from == from && i.to == to){
            return;
        }
    }

    Edge edge(from, to);
    edges.push_back(edge);
}

unsigned int ArcGraph::VerticesCount() const {
    return verticesCount;
}

void ArcGraph::GetNextVertices(int vertex, vector<int> & vertices) const {
    vertices.clear();

    for ( const Edge & i : edges ) {
        if ( i.from == vertex ) {
            vertices.push_back(i.to);
        }
    }
}

void ArcGraph::GetPrevVertices(int vertex, vector<int> & vertices) const {
    vertices.clear();

    for (const Edge & i : edges) {
        if ( i.to == vertex ) {
            vertices.push_back(i.from);
        }
    }
}

