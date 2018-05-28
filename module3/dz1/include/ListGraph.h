//
// Created by Родион Фаррахов on 27.05.2018.
//

#ifndef DZ1_LISTGRAPH_H
#define DZ1_LISTGRAPH_H

#include <vector>
#include "IGraph.h"

using std::vector;

class ListGraph : public IGraph {
public:
    ListGraph ( unsigned int count );
    ListGraph ( const IGraph&  graph );

    // Добавление ребра от from к to.
    virtual void AddEdge ( int from, int to ) override ;

    virtual unsigned int VerticesCount () const override ;

    virtual void GetNextVertices ( int vertex, std::vector<int>& vertices ) const override ;
    virtual void GetPrevVertices ( int vertex, std::vector<int>& vertices ) const override ;
private:
    unsigned int verticesCount;

    vector<vector<int>> in;
    vector<vector<int>> out;
};

#endif //DZ1_LISTGRAPH_H
