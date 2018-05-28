#include <vector>
#include <queue>
#include <list>
#include <iostream>


using std::vector;
using std::queue;
using std::list;
using std::cin;
using std::cout;


struct Vertex {
    Vertex();

    int depth;
    int cPaths;
};


Vertex::Vertex()
{
    depth = 0;
    cPaths = 0;
}


class CListGraph {
public:
    CListGraph(unsigned int verticesNumber);

    void addEdge(int from, int to);
    void getNextVertices(int vertex, vector<int> & vertices) const;
    int countPaths(int from, int to);

private:
    unsigned int verticesNumber_;
    vector<list<int>> out_;
};


CListGraph::CListGraph(unsigned int verticesNumber):
        verticesNumber_(verticesNumber),
        out_(verticesNumber_) {}


void CListGraph::addEdge(int from, int to)
{
    for (int i : out_[from])
        if(i == to)
            return;

    out_[to].push_back(from);
    out_[from].push_back(to);
}


void CListGraph::getNextVertices(int vertex, vector<int> & vertices) const
{
    for(int i : out_[vertex])
        vertices.push_back(i);
}


int CListGraph::countPaths(int from, int to)
{
    vector<Vertex> states(verticesNumber_);

    queue<int> q;
    q.push(from);
    states[from].cPaths = 1;

    while(!q.empty()) {
        vector<int> nextVertices;

        int v = q.front();
        q.pop();
        getNextVertices(v, nextVertices);

        for (int i : nextVertices) {
            if (states[i].cPaths == 0) {
                q.push(i);
                states[i].depth = states[v].depth + 1;
                states[i].cPaths = states[v].cPaths;
            } else if(states[i].depth == states[v].depth + 1) {\
                states[i].cPaths += states[v].cPaths;
            }
        }
    }
    return states[to].cPaths;
}


int main()
{
    unsigned int v = 0;
    cin >> v;
    CListGraph CListGraph(v);

    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        CListGraph.addEdge(a, b);
    }

    int from = 0;
    int to = 0;
    cin >> from >> to;

    cout << CListGraph.countPaths(from, to);
}