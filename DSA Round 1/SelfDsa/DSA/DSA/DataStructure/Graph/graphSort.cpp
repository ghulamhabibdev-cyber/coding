#include <bits/stdc++.h>
using namespace std;
class graph
{
public:
    unordered_map<int, list<int>> adj;
    void addEdges(int u, int v, bool direction)
    {
        // direction 0 equal undirected graph
        // direction 1 mean directed graph
        adj[u].push_back(v);
        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }
    void printAdjacenyList()
    {
        for (auto data : adj)
        {
            cout << data.first << "->";
            for (auto j : data.second)
            {
                cout << j << ", ";
            }
            cout << endl;
        }
    }
};
// Topological sort using DFS
void topoSort(int node, unordered_map<int, bool> &visited, stack<int> &s, unordered_map<int, list<int>> &adList)
{
    visited[node] = true;
    for (auto neigh : adList[node])
    {
        if (!visited[neigh])
        {
            topoSort(neigh, visited, s, adList);
        }
    }
    s.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    // step #-> Make adjacncy list of given edges
    unordered_map<int, list<int>> adList;
    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adList[u].push_back(v);
    }
    // step #->call sorting method
    unordered_map<int, bool> visited;
    stack<int> s;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            topoSort(i, visited, s, adList);
        }
    }
    vector<int> result;
    while (!s.empty())
    {
        result.push_back(s.top());
        s.pop();
    }

    return result;
}



// topological sort using kahn's alogrhytm
vector<int> topoSortByKahns(vector<vector<int>> edge, int v, int e)
{
    // #->Make Adjecency list
    unordered_map<int, list<int>> adList;
    for (int i = 0; i <= e; i++)
    {
        int u = edge[i][0];
        int v = edge[i][1];
        adList[u].push_back(v);
    }

    vector<int>indegree(v,0);
    for(auto i:adList)
    {
        for(auto j:i.second)
        {
            indegree[j]++;
        }
    }
    queue<int>q;
    for(int i=0;i<v;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }
    vector<int> ans;
    while (!q.empty())
    {
        int front=q.front();
        q.pop();
        ans.push_back(front);
        for(auto neigh:adList[front])
        {
            indegree[neigh]--;
            if(indegree[neigh]==0)
            {
                q.push(neigh);
            }
        }
        /* code */
    }
    return ans;
}
int main()
{
    // int v = 6, e = 6;
    // vector<vector<int>> edges = {
    //     {5, 2}, {5, 0}, {4, 0}, {4, 1}, {2, 3}, {3, 1}};

    // vector<int> ans = topologicalSort(edges, v, e);

    // cout << "Topological Sort: ";
    // for (auto x : ans)
    //     cout << x << " ";
    // cout << endl;

//topological sort using kahn alog
     int v = 5, e = 5;
    vector<vector<int>> edges = {
        {1, 2}, {1, 3}, {2, 5},
        {3, 5}, {5, 4}, };

    vector<int> ans = topoSortByKahns(edges, v, e);

    cout << "Topological Sort (Kahn's Algorithm): ";
    for (auto x : ans)
        cout << x << " ";
    cout << endl;
    return 0;




}