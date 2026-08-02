#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <list>
#include <limits>
#include <list>
using namespace std;

class graph
{
public:
    unordered_map<int, list<int>> adj;
    void addEdg(int u, int v, bool direction)
    {
        // 0-> undirected graph
        // 1-> directed graph
        // create a edge from u to v
        adj[u].push_back(v);
        if (direction == 0)
            adj[v].push_back(u);
    }
    void printAdj()
    {
        for (auto i : adj)
        {
            cout << i.first << "->";
            for (auto j : i.second)
            {
                cout << j << ", ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int n;
    cout << "Enter the No of Nodes: ";
    cin >> n;
    int m;
    cout << "Enter The no of edges : \n";
    cin >> m;
    graph g;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cout << "Enter the edge u and v: ";
        cin >> u >> v;
        // create an undired graph 
        g.addEdg(u, v, 0);
    }

    g.printAdj();
    return 0;
}