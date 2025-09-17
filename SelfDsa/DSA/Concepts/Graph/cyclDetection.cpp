#include <bits/stdc++.h>
using namespace std;
bool checkCycle(int node, unordered_map<int, bool> visited, unordered_map<int, bool> dfsvisited, unordered_map<int, list<int>> adjacnyList)
{
    visited[node] = true;
    dfsvisited[node] = true;
    for (auto neigh : adjacnyList[node])
    {
        if (!visited[neigh])
        {
            bool fond = checkCycle(neigh, visited, dfsvisited, adjacnyList);
            if (fond)
            {
                return true;
            }
        }
        else if (dfsvisited[neigh])
        {
            return true;
        }
    }
    dfsvisited[node] = false;
    return false;
}
int detctCycleDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    unordered_map<int, list<int>> adjacnyList;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        adjacnyList[u].push_back(v);
        adjacnyList[v].push_back(u);
    }
    // call dfs for all componet
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsvisisted;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            if (checkCycle(i, visited, dfsvisisted, adjacnyList))
                return true;
        }
    }
    return false;
}
// cycle detection using topological sort

int detectCycleUsingTopologicalSort(int n, vector<pair<int, int>> edges)

{

    unordered_map<int, list<int>> adList;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        adList[u].push_back(v);
    }

    vector<int> indegree(n, 0);
    for (auto i : adList)
    {
        for (auto j : i.second)
        {
            indegree[j]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    int cnt = 0;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        cnt++;
        cout<<"I am CNT : "<<cnt<<endl;
        for (auto neigh : adList[front])
        {
            indegree[neigh]--;
            if (indegree[neigh] == 0)
            {
                q.push(neigh);
            }
        }
        /* code */
    }
    if (cnt == n)
    {
        return false;
    }
    return true;
}
int main()
{
    // int n = 4;
    // vector<pair<int, int>> edges = {{1, 2}, {2, 3}, {3, 4}, {4, 2}}; // cycle present

    // if (detctCycleDirectedGraph(n, edges))
    //     cout << "Cycle Detected\n";
    // else
    //     cout << "No Cycle\n";
    int n = 4; // number of nodes
    vector<pair<int, int>> edges = {
        {0, 1}, {1, 2}, {2, 3}, {3, 1} // cycle present
    };

    if (detectCycleUsingTopologicalSort(n, edges))
    {
        cout << "Cycle Detected!" << endl;
    }
    else
    {
        cout << "No Cycle Detected." << endl;
    }
    return 0;
}