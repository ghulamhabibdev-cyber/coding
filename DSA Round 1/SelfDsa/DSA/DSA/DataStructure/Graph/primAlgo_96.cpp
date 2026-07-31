#include <bits/stdc++.h>
using namespace std;
class a
{
public:
};
// this has prim algorthtym
vector<pair<pair<int, int>, int>> calculatPrimMSt(int n, int m, vector<pair<pair<int, int>, int>> g)
{

    unordered_map<int, list<pair<int, int>>> adj;
    for (int i = 0; i < g.size(); i++)
    {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    vector<int> key(n + 1, INT_MAX);
    vector<bool> mst(n + 1, false);
    vector<int> parent(n + 1, -1);
    // let algo
    key[1] = 0;
    parent[1] = -1;
    for (int i = 0; i <= n; i++)
    {
        int mini = INT_MAX;
        int u;
        // find min node
        for (int v = 1; v <= n; v++)
        {
            if (mst[v] == false && key[v] < mini)
            {
                u = v;                
                mini = key[v];
            }
        }
        // mark min node as truel
        mst[u] = true;
        // check it neigh
        for (auto it : adj[u])
        {
            int v = it.first;
            int w = it.second;
            if (mst[v] == false && w < key[v])
            {
                parent[v] = u;
                key[v] = w;
            }
        }
    }
    vector<pair<pair<int, int>, int>> result;
    for (int k = 2; k <= n; k++)
    {
        result.push_back({{parent[k], k}, key[k]});
    }
    return result;
}
int main()
{
    int n = 5, m = 6;
    vector<pair<pair<int, int>, int>> edges = {
        {{1, 2}, 2}, {{1, 4}, 8}, {{2, 3}, 3}, {{2, 5}, 5}, {{3, 5}, 7}, {{4, 5}, 9}};

    auto mst = calculatPrimMSt(n, m, edges);

    cout << "🌳 MST Edges:\n";
    for (auto e : mst)
    {
        cout << e.first.first << " -- " << e.first.second
             << "  (weight: " << e.second << ")\n";
    }
    return 0;
}