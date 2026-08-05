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
    Graph(int n)
    {
        adj.resize(n);
    }
    void addEdges(int src, int dist)
    {
        adj[src].push_back(dist);
        adj[dist].push_back(src);
    }
    void printGraph()
    {
        for (int i = 0; i < adj.size(); i++)
        {
            cout << i << "-> ";
            for (int j = 0; j < adj[i].size(); j++)
            {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }
    void BFS(vector<int> &res, unordered_map<int, bool> vis, int st)
    {
        queue<int> q;
        q.push(st);
        vis[st] = true;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            res.push_back(node);
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
    }
};
int main()
{
    
    Graph g(5);
    g.addEdges(0, 1);
    g.addEdges(0, 4);
    g.addEdges(0, 3);
    g.addEdges(1, 3);
    g.addEdges(2, 4);
    g.addEdges(3, 4);
    cout << "========= Graph Print ======\n";
    g.printGraph();
    vector<int> res;
    unordered_map<int, bool> mp;

    int st = 0;
    g.BFS(res, mp, st);
    cout << "========= BFS Traversal =======\n";
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}