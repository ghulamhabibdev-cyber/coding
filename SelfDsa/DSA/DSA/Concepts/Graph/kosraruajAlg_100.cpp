#include <bits/stdc++.h>
using namespace std;
class a
{
public:
};
// konsragu alurtyhm is use to find all strongly connected component
//  a node from which we can trverse all node of give component
//  it is apply on directed graph
void dfs(int node, unordered_map<int, bool> &vis, stack<int> &s, unordered_map<int, list<int>> &adj)
{
    vis[node] = true;
    for (auto nbr : adj[node])
    {
        if (!vis[nbr])
        {
            dfs(nbr, vis, s, adj);
        }
    }
    s.push(node);
}
void revDfs(int node, unordered_map<int, bool> &vis, unordered_map<int, list<int>> &adj)
{
    vis[node] = true;
    for (auto nbr : adj[node])
    {
        if (!vis[nbr])
        {
            revDfs(nbr, vis, adj);
        }
    }
}
int kosarajuAlogrythm(int v, vector<vector<int>> edges)
{
    // #->make adj list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }
    // find topological sort
    stack<int> s;
    unordered_map<int, bool> vis;
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, s, adj);
        }
    }
    // take tranpose of graph/adj list
    unordered_map<int, list<int>> transpose;
    for (int i = 0; i < v; i++)
    {
        vis[i] = 0;
        for (auto nbr : adj[i])
        {
            transpose[nbr].push_back(i);
        }
    }
    int count = 0;
    // cal dfs using above stack
    while (!s.empty())
    {
        int top = s.top();
        s.pop();
        if (!vis[top])
        {
            count++;
            revDfs(top, vis, transpose);
        }
    }
    return count;
}
int main()
{
    int v = 5; // number of vertices (0 to 4)

    // edges of the directed graph
    vector<vector<int>> edges = {
        {1, 0},
        {0, 2},
        {2, 1},
        {0, 3},
        {3, 4}};

    int sccCount = kosarajuAlogrythm(v, edges);

    cout << "Number of Strongly Connected Components = " << sccCount << endl;
    return 0;
}
