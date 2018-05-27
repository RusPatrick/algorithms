//
// Created by Родион Фаррахов on 27.05.2018.
//

#ifndef DZ1_ARCGRAPH_H
#define DZ1_ARCGRAPH_H

#include "IGraph.h"


class Edge {
public:
    Edge(int from, int to);

    int from;
    int to;
};


Edge::Edge(int from, int to)
{
    this->from = from;
    this->to = to;
}


class ArcGraph : public IGraph {
public:
    ArcGraph(unsigned int count);
    ArcGraph(const IGraph& graph);

    virtual void AddEdge(int from, int to) override;
    virtual unsigned int VerticesCount() const override;

    virtual void GetNextVertices(int vertex, vector<int> & vertices) const override;
    virtual void GetPrevVertices(int vertex, vector<int> & vertices) const override;
private:

    unsigned int verticesCount;

    vector<Edge> edges;
};

#endif //DZ1_ARCGRAPH_H
