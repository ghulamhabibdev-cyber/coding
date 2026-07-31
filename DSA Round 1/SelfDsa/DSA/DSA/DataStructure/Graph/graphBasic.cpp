#include <bits/stdc++.h>
using namespace std;
class graph
{
    public:
    unordered_map<int,list<int>>adj;
    void addEdges(int u, int v, bool direction)
    {
        //direction 0 equal undirected graph
        //direction 1 mean directed graph
        adj[u].push_back(v);
        if(direction==0)
        {
            adj[v].push_back(u);
        }
        
    }
    void printAdjacenyList()
    {
        for(auto data:adj)
        {
            cout<<data.first<<"->";
            for(auto j:data.second)
            {
                cout<<j<<", ";
            }
            cout<<endl;
        }
    }
    
};
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
        int frontNode= q.front();
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

      int vertex = 5;
    vector<pair<int, int>> edges = {
        {0, 1}, {0, 2}, {1, 3}, {2, 4}};

    vector<int> result = BFS(vertex, edges);

    cout << "BFS Traversal: ";
    for (int i : result)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}