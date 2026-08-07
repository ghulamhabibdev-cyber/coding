#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits>
#include <list>
using namespace std;
class A
{
};
class Graph
{
    vector<vector<pair<int, int>>> edges;
    void resizeGraph(int src, int dest)
    {
        int maxi = max(dest, src);
        if (maxi >= edges.size())
        {
            edges.resize(maxi + 1);
        }
    }
public:
    void addEdgesDirectedGraph(int src, int dest, int wt)
    {
        resizeGraph(src, dest);
        edges[src].push_back({dest, wt});
    }
    void addEdges(int src, int dest, int wt)
    {
        resizeGraph(src, dest);
        edges[src].push_back({dest, wt});
        edges[dest].push_back({src, wt});
    }
    vector<int> BelemanForm(int src)
    {
        int n = edges.size();
        vector<int> res(n, 1e8-);
        res[src] = 0;
        for (int i = 0; i < n - 1; i++)
        {
            for (int u = 0; u < n; u++)
            {
                for (auto &edge : edges[u])
                {
                    int v = edge.first;
                    int wt = edge.second;
                    if (res[u] != INT_MAX && res[u] + wt < res[v])
                    {
                        res[v] = res[u] + wt;
                    }
                }
            }
        }
        for (int u = 0; u < n; u++)
        {
            for (auto &edge : edges[u])
            {
                int v = edge.first;
                int wt = edge.second;
                if (res[u] != INT_MAX && res[u] + wt < res[v])
                {
                    cout << "Graph contains a negative weight cycle!" << endl;
                    return {-1};
                }
            }
        }
        return res;
    }
};

int main()
{
    Graph g;
    g.addEdgesDirectedGraph(0, 2, 10);
    g.addEdgesDirectedGraph(0, 1, 5);
    g.addEdgesDirectedGraph(2, 1, 2);
    g.addEdgesDirectedGraph(2, 3, 4);
    g.addEdgesDirectedGraph(1, 4, 10);
    g.addEdgesDirectedGraph(3, 4, 3);
    g.addEdgesDirectedGraph(3,5, 1);
    g.addEdgesDirectedGraph(5, 4, 2);
    vector<int> distances = g.BelemanForm(0);
    for (int i = 0; i < distances.size(); i++)
    {
        if (distances[i] == INT_MAX)
        {
            cout << "Node " << i << ": Unreachable" << endl;
        }
        else
        {
            cout << "Node " << i << ": " << distances[i] << endl;
        }
    }
    return 0;
}
