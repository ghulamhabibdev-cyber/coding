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
    vector<vector<pair<int, int>>> adj;
    void resizeGraph(int src, int dist)
    {
        int maxi = max(dist, src);
        if (maxi >= adj.size())
        {
            adj.resize(maxi + 1);
        }
    }

public:
    void addDirectedEdges(int src, int dist, int wt)
    {
        resizeGraph(src, dist);
        adj[src].push_back({dist, wt});
    }
    void addUndirectedEdges(int src, int dist, int wt)
    {
        addDirectedEdges(src, dist, wt);
        adj[dist].push_back({src, wt});
    }
    vector<int> bellManFord(int src)
    {
        int n = adj.size();
        if (src >= n)
        {
            return {-1};
        }
        vector<int> res(n, 1e8);
        res[src] = 0;
        for (int i = 0; i < n - 1; i++)
        {
            for (int u = 0; u < n; u++)
            {
                for (int j = 0; j < adj[u].size(); j++)
                {
                    pair<int, int> p = adj[u][j];
                    int v = p.first;
                    int wt = p.second;
                    if (res[u] != 1e8 && res[v] > res[u] + wt)
                    {
                        res[v] = res[u] + wt;
                    }
                }
            }
        }
        for (int u = 0; u < n; u++)
        {
            for (int j = 0; j < adj[u].size(); j++)
            {
                pair<int, int> p = adj[u][j];
                int v = p.first;
                int wt = p.second;
                if (res[u] != 1e8 && res[v] > res[u] + wt)
                {
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
    g.addDirectedEdges(0, 1, 100);
    g.addDirectedEdges(0, 2, 20);
    g.addDirectedEdges(1, 2, 2);
    g.addDirectedEdges(1, 6, 20);
    g.addDirectedEdges(1, 5, 12);
    g.addDirectedEdges(2, 4, 100);
    g.addDirectedEdges(2, 3, 2);
    g.addDirectedEdges(4, 5, 1);
    g.addDirectedEdges(5, 6, 2);
    vector<int> res = g.bellManFord(0);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}
