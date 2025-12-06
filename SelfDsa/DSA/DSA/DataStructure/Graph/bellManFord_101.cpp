#include <bits/stdc++.h>
using namespace std;
class a
{
public:
};
int bellManFordAlgo(int n, int m, int src, int dest, vector<vector<int>> edges)
{
    vector<int> dist(n + 1, 1e9);
    dist[src] = 0;
    for (int i = 1; i < n; i++)
    {
        // traverse all edges list
        for (int j = 0; j < m; j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];
            if (dist[u] != 1e9 && (dist[u] + wt < dist[v]))
            {
                dist[v] = dist[u] + wt;
            }
        }
    }
    bool flag = 0;
    for (int j = 0; j < m; j++)
    {
        int u = edges[j][0];
        int v = edges[j][1];
        int wt = edges[j][2];
        if (dist[u] != 1e9 && (dist[u] + wt < dist[v]))
        {
            flag = 1;
        }
    }

    // check for negative cyle
    if (flag == 0)
    {
        return dist[dest];
    }
    return -1;
}
int main()
{
    int n = 5, m = 8; // example graph
    vector<vector<int>> edges = {
        {1, 2, -1}, {1, 3, 4}, {2, 3, 3}, {2, 4, 2}, {2, 5, 2}, {4, 2, 1}, {4, 3, 5}, {5, 4, -3}};

    int src = 1, dest = 3;
    int ans = bellManFordAlgo(n, m, src, dest, edges);

    if (ans == -1)
        cout << "Negative cycle detected\n";
    else
        cout << "Shortest distance from " << src << " to " << dest << " = " << ans << "\n";

    // int n = 3, m = 3;
    // vector<vector<int>> edges = {
    //     {1, 2, 4},
    //     {2, 3, -10},
    //     {3, 1, 3}};
    // int src = 1, dest = 3;
    // int ans = bellManFordAlgo(n, m, src, dest, edges);

    // if (ans == -1)
    //     cout << "Negative cycle detected\n";
    // else
    //     cout << "Shortest distance from " << src << " to " << dest << " = " << ans << "\n";




    return 0;
}