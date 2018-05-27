//
// Created by Родион Фаррахов on 27.05.2018.
//
#include "ListGraph.h"

ListGraph::ListGraph ( int count ) {
    adjacencyLists.resize ( count );
}

ListGraph::ListGraph ( const IGraph& graph ) {
    adjacencyLists.resize ( graph.VerticesCount() );
    for ( int from = 0; from < adjacencyLists.size(); ++from ) {
        graph.GetNextVertices( from, adjacencyLists[from] );
    }
}

void ListGraph::AddEdge ( int from , int to ) {
    adjacencyLists[from].push_back(to);
}

unsigned int ListGraph::VerticesCount () const {
    return adjacencyLists.size ();
}

void ListGraph::GetNextVertices ( int vertex, std::vector<int>& vertices ) const {
    vertices = adjacencyLists[vertex];
}

void ListGraph::GetPrevVertices ( int vertex, std::vector<int>& vertices ) const {
    vertices.clear();

    for ( int from = 0; from < adjacencyLists.size (); ++from ) {
        for ( int i = 0; i < adjacencyLists[from].size (); ++i ) {
            if ( adjacencyLists[from][i] == vertex ) {
                vertices.push_back(from);
            }
        }
    }
}
