#include <iostream>
#include <vector>
#include <set>
#include <list>


using std::vector;
using std::set;
using std::pair;
using std::make_pair;
using std::list;
using std::cin;
using std::cout;


typedef unsigned int uint;


class CListGraph {
public:
    CListGraph(uint verticesNumber);

    void addEdge(uint from, uint to, uint weight);
    void getRelated(uint vertex, vector<pair<uint, uint>> &vertices) const;
    uint getSize() const;

private:
    uint size_;
    vector<list<pair<uint, uint>>> edges_;
};


CListGraph::CListGraph(uint size) :
        size_(size),
        edges_(size_, list<pair<uint, uint>>()) {}


void CListGraph::addEdge(uint from, uint to, uint weight)
{
    edges_[from].push_back(make_pair(to, weight));
    edges_[to].push_back(make_pair(from, weight));
}


uint CListGraph::getSize() const
{
    return size_;
}


void CListGraph::getRelated(uint vertex, vector<pair<uint, uint>> &vertices) const
{
    vertices.clear();
    for (const pair<uint, uint> &i : edges_[vertex])
        vertices.push_back(i);
}


const uint maxValue = 4294967295;

int dijkstra(CListGraph const &CListGraph, int from, int to)
{
    // Извлечена ли вершина
    vector<bool> used(CListGraph.getSize(), false);
    // Длина пути к вершине
    vector<uint> path(CListGraph.getSize(), maxValue);
    path[from] = 0;

    // Очередь с приоритетом
    set<pair<uint, uint>> queue;
    queue.emplace(make_pair(0, from));

    while (!queue.empty()) {
        // Достаем вершину с минимальным путем
        uint v = (queue.begin())->second;
        queue.erase(queue.begin());
        used[v] = true;

        // Берем все связанные вершины
        vector<pair<uint, uint>> paths;
        CListGraph.getRelated(v, paths);

        for (pair<uint, uint> c : paths) {
            if (path[c.first] > path[v] + c.second) {
                // Удаляем старое значение из очереди
                if (path[c.first] != maxValue)
                    queue.erase(make_pair(path[c.first], c.first));
                // Обновляем путь и вставляем в очередь
                path[c.first] = path[v] + c.second;
                queue.emplace(pair<int, int>(path[c.first], c.first));
            }
        }
    }

    if (path[to] != maxValue)
        return (int)(path[to]);
    else
        return -1;
}


int main() {

    uint n = 0;
    uint m = 0;
    cin >> n >> m;

    CListGraph CListGraph(n);

    for (uint i = 0; i < m; i++) {
        uint s = 0;
        uint t = 0;
        uint w = 0;
        cin >> s >> t >> w;
        CListGraph.addEdge(s, t, w);
    }

    uint from = 0;
    uint to = 0;
    cin >> from >> to;

    cout << dijkstra(CListGraph, from, to);

    return 0;
}

