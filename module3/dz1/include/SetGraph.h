//
// Created by Родион Фаррахов on 27.05.2018.
//

#ifndef DZ1_SETGRAPH_H
#define DZ1_SETGRAPH_H

#include "IGraph.h"
#include <unordered_set>

using std::unordered_set;

class SetGraph : public IGraph {
public:
    SetGraph ( unsigned int count );
    SetGraph ( IGraph& graph );

    virtual void AddEdge ( int from, int to) override ;

    virtual unsigned int VerticesCount () const override ;

    virtual void GetNextVertices ( int vertex, std::vector<int>& vertices ) const override ;
    virtual void GetPrevVertices ( int vertex, std::vector<int>& vertices ) const override ;
private:
    unsigned int verticesCount;
    vector<unordered_set<int>> in;
    vector<unordered_set<int>> out;
};



#endif //DZ1_SETGRAPH_H
