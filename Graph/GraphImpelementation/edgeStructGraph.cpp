#include <iostream>
#include <vector>
using namespace std;

struct Edge
{
    int u, v;
};

class Graph
{
private:
    vector<Edge> adj;

public:
    void addEdge(Edge ed)
    {
        adj.push_back(ed);
    }

    void print()
    {
        cout << "Edge List:\n";

        for (const Edge &e : adj)
        {
            cout << e.u << " --> " << e.v << endl;
        }
    }
};

int main()
{
    Graph g;

    g.addEdge({0, 1});
    g.addEdge({0, 2});
    g.addEdge({1, 3});
    g.addEdge({2, 4});

    g.print();

    return 0;
}