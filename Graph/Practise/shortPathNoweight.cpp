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
    vector<vector<int>> edges;
    void resizeGraph(int src, int dist)
    {
        int maxi = max(src, dist);
        if (maxi >= edges.size())
        {
            edges.resize(maxi + 1);
        }
    }

public:
    void addEdges(int src, int dist)
    {
        resizeGraph(src, dist);
        edges[src].push_back(dist);
        edges[dist].push_back(src);
    }
    void addDirectedEdges(int src, int dist)
    {
        resizeGraph(src, dist);
        edges[src].push_back(dist);
    }
    vector<int> findShortPath(int src, int dist)
    {
        int n = edges.size();
        if (src >= n || dist >= n)
        {
            return {-1};
        }
        vector<int> res(n, INT_MAX);
        queue<pair<int, int>> q;
        vector<bool> vis(n, 0);
        q.push({src, 0});
        vis[src] = true;
        while (!q.empty())
        {
            pair<int, int> p = q.front();
            q.pop();
            int node = p.first;
            int dist = p.second;
            vis[node] = true;
            res[node] = dist;
            for (int j = 0; j < edges[node].size(); j++)
            {
                int neigh = edges[node][j];
                if (!vis[neigh])
                {
                    q.push({neigh, dist + 1});
                }
            }
        }
        return res;
    }
};
int main()
{
    Graph g;
    g.addEdges(0, 1);
    g.addEdges(0, 2);
    g.addEdges(0, 10);
    g.addEdges(10, 11);
    g.addEdges(11, 9);
    g.addEdges(1, 4);
    g.addEdges(4, 5);
    g.addEdges(2, 3);
    g.addEdges(3, 5);
    g.addEdges(5, 6);
    g.addEdges(6, 7);
    g.addEdges(6, 8);
    vector<int> res = g.findShortPath(0, 7);
    for (int i = 0; i < res.size(); i++)
    {
        cout << i << " : " << res[i] << endl;
    }
    return 0;
}