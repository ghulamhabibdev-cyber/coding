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

public:
    void addEdges(int src, int dist)
    {
        adj[src].push_back(dist);
        adj[dist].push_back(src);
    }
    void printGraph()
    {
        for (int i = 0; i < adj.size(); i++)
        {
            cout << i << "->";
            for (int j = 0; j < adj[i].size(); j++)
            {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }
    void dfs(vector<int> &res, unordered_map<int, bool> &vis, int node)
    {
        res.push_back(node);
        vis[node] = true;
        vector<int> neig = adj[node];
        int n = neig.size();
        for (int i = 0; i < n; i++)
        {
            int neigbourNode = neig[i];
            if (!vis[neigbourNode])
            {
                dfs(res, vis, neigbourNode);
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
    cout<<"========== Graph Print ======= \n";
    g.printGraph();
    int st = 0;
    vector<int> res;
    unordered_map<int, bool> mp;
    g.dfs(res, mp, st);
    cout << "========== Depth First Search ========== \n";
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}