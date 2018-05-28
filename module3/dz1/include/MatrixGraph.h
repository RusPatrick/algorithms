//
// Created by Родион Фаррахов on 27.05.2018.
//

#ifndef DZ1_MATRIXGRAPH_H
#define DZ1_MATRIXGRAPH_H

#include <vector>
#include "IGraph.h"

using std::vector;

class MatrixGraph : public IGraph {
public:
    MatrixGraph ( unsigned int count );
    MatrixGraph ( const IGraph&  graph );

    // Добавление ребра от from к to.
    virtual void AddEdge ( int from, int to ) override ;

    virtual unsigned int VerticesCount () const override ;

    virtual void GetNextVertices ( int vertex, std::vector<int>& vertices ) const override ;
    virtual void GetPrevVertices ( int vertex, std::vector<int>& vertices ) const override ;
private:
    vector<vector<bool>> edges;
    unsigned int verticesCount;
};

#endif //DZ1_MATRIXGRAPH_H
