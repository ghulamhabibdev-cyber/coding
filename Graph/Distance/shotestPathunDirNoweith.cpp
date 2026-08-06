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
    vector<vector<int>> adj;

public:
    void resize(int src, int dist)
    {
        int maxi = max(src, dist);
        if (maxi >= adj.size())
        {
            adj.resize(maxi + 1);
        }
    }
    void addEdges(int src, int dist)
    {
        resize(src, dist);
        adj[src].push_back(dist);
        adj[dist].push_back(src);
    }
    void printGraph()
    {
        for (int i = 0; i < adj.size(); i++)
        {
            cout << i << " -> ";
            vector<int> arr = adj[i];
            for (int num : arr)
            {
                cout << num << " ";
            }
            cout << endl;
        }
    }
    void bfs()
    {
        int n = adj.size();
        queue<int> q;
        vector<bool> vis(n, 0);
        q.push(0);
        vis[0] = true;
        vector<int> res;
        while (!q.empty())
        {
            int node = q.front();
            res.push_back(node);
            q.pop();
            for (int i = 0; i < adj[node].size(); i++)
            {
                int neigh = adj[node][i];
                if (!vis[neigh])
                {
                    q.push(neigh);
                    vis[neigh] = true;
                }
            }
        }
        for (int num : res)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    vector<int> findShortestPath()
    {
        int n = adj.size();
        vector<int> path(n, INT_MAX);
        vector<bool> vis(n, 0);
        queue<pair<int, int>> q;
        q.push({0, 0});
        vis[0] = true;
        while (!q.empty())
        {
            pair<int, int> p = q.front();
            q.pop();
            int node = p.first;
            int dist = p.second;
            path[node] = dist;
            for (int i = 0; i < adj[node].size(); i++)
            {
                int neigh = adj[node][i];
                if (!vis[neigh])
                {
                    q.push({neigh, dist + 1});
                    vis[neigh] = true;
                }
            }
        }
        return path;
    }
};
int main()
{
    // 
    Graph g;
    g.addEdges(0, 1);
    g.addEdges(1, 2);
    g.addEdges(1, 3);
    g.addEdges(1, 4);
    g.addEdges(2, 5);
    g.addEdges(3, 6);
    g.addEdges(3, 7);
    g.addEdges(4, 8);
    // g.printGraph();

    vector<int> res = g.findShortestPath();
    for (int i = 0; i < res.size(); i++)
    {
        cout << "Node : " << i << " dist : " << res[i] << endl;
    }
    return 0;
}