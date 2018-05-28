#ifndef TASK1_CARCGRAPH_H
#define TASK1_CARCGRAPH_H

#include "IGraph.h"


struct Edge {

    Edge(int from, int to);

    int from;
    int to;
};


Edge::Edge(int from_, int to_)
{
    from = from_;
    to = to_;
}


class CArcGraph : public IGraph {
public:

    CArcGraph(unsigned int verticesNumber);
    CArcGraph(const IGraph* graph);

    virtual void AddEdge(int from, int to) override;
    virtual int VerticesCount() const override;

    virtual void GetNextVertices(int vertex, vector<int> & vertices) const override;
    virtual void GetPrevVertices(int vertex, vector<int> & vertices) const override;

private:

    unsigned int verticesNumber_;

    vector<Edge> edges_;
};

#endif