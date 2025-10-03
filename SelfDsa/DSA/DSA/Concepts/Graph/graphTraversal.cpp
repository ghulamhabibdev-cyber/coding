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
// bfs traversal
void perparAjacencyList(unordered_map<int, list<int>> &adjList, vector<pair<int, int>> edges)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}
void bfs(unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited, vector<int> &ans, int node)
{
    queue<int> q;
    q.push(node);
    visited[node] = 1;
    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();
        ans.push_back(frontNode);
        for (auto i : adjList[frontNode])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = 1;
            }
        }
        /* code */
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int, list<int>> adjList;
    vector<int> ans;
    unordered_map<int, bool> visited;
    perparAjacencyList(adjList, edges);
    // traverse all component of graph

    for (int i = 0; i < vertex; i++)
    {
        if (!visited[i])
        {
            bfs(adjList, visited, ans, i);
        }
    }
    return ans;
}
// dfs traversal
void dfs(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj, vector<int> &componet)
{
    componet.push_back(node);
    visited[node] = true;
    // hr connected node kye liye recursive call
    for (auto i : adj[node])
    {
        if (!visited[i])
        {
            dfs(i, visited, adj, componet);
        }
    }
}
vector<vector<int>> depthFirstTraversal(int v, int e, vector<vector<int>> &edges)
{
    // prepare adjacelos
    unordered_map<int, list<int>> adj;

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> ans;
    unordered_map<int, bool> visited;
    for (int i = 0; i < 1; i++)
    {
        if (!visited[i])
        {
            vector<int> component;
            dfs(i, visited, adj, component);
            ans.push_back(component);
        }
    }
    return ans;
}
// cycle detection in graph
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
int main()
{
    // int n;
    // cout<<"Enter the Number of nodes  : \n";
    // cin>>n;
    // int m;
    // cout<<"Enter the number of edges  : \n";
    // cin>>m;
    // graph g;
    // for(int i=0;i<m;i++)
    // {
    //     int u,v;
    //     cin>>u>>v;
    //     g.addEdges(u,v,0);

    // }
    // g.printAdjacenyList();

    // int vertex = 5;
    // vector<pair<int, int>> edges = {
    //     {0, 1}, {0, 2}, {1, 3}, {2, 4}};

    // vector<int> result = BFS(vertex, edges);

    // cout << "BFS Traversal: ";
    // for (int i : result)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;
    // int v = 5, e = 8;
    // vector<vector<int>> edges = {
    //     {0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 1}, {3, 2}, {2, 1}, {1, 0}};

    // vector<vector<int>> components = depthFirstTraversal(v, e, edges);

    // for (auto comp : components)
    // {
    //     for (int node : comp)
    //     {
    //         cout << node << " ";
    //     }
    //     cout << endl;
    // }

    int n = 4;
    vector<pair<int, int>> edges = {{1, 2}, {2, 3}, {3, 4}, {4, 2}}; // cycle present

    if (detctCycleDirectedGraph(n, edges))
        cout << "Cycle Detected\n";
    else
        cout << "No Cycle\n";

    return 0;
    
}