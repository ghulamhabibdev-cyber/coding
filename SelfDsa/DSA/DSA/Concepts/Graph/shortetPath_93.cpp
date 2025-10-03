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
vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int s, int t)
{
    unordered_map<int, list<int>> adjacencyList;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u);
    }
    //do bfs
    unordered_map<int,bool>visited;
    unordered_map<int,int>parent;
    queue<int>q;
    q.push(s);
    parent[s]=-1;
    visited[s]=true;
    //start bfs 
    while(!q.empty())
    {
        int front=q.front();
        q.pop();
        for(auto neigh:adjacencyList[front])
        {
            if(!visited[neigh])
            {
                visited[neigh]=true;
                parent[neigh]=front;
                q.push(neigh);
            }
        }
    }
    //prepare shortest path 
    vector<int>ans;
    int currentNod=t;
    ans.push_back(t);
    while (currentNod!=s)
    {
        currentNod=parent[currentNod];
        ans.push_back(currentNod);

    }
    reverse(ans.begin(),ans.end());
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

    // int n = 6; // number of nodes
    // int m = 7; // number of edges
    // vector<pair<int,int>> edges = {
    //     {0,1},{0,2},{1,3},{2,3},{3,4},{4,5},{2,5}
    // };

    // int s = 0, t = 5; // source & target

    // vector<int> path = shortestPath(edges, n, m, s, t);

    // if(path[0] == -1) {
    //     cout << "No Path Exists!" << endl;
    // } else {
    //     cout << "Shortest Path: ";
    //     for(int node : path) cout << node << " ";
    //     cout << endl;
    // }

    int n = 9; // number of nodes (1..8)
    int m = 9; // number of edges
    vector<pair<int,int>> edges = {
        {1,2},{2,5},{5,8},  // Path 1
        {1,3},{3,8},        // Path 2
        {1,4},{4,6},{6,7},{7,8} // Path 3
    };

    int s = 1, t = 8; // source & destination

    vector<int> path = shortestPath(edges, n, m, s, t);

    if(path[0] == -1) {
        cout << "No Path Exists!" << endl;
    } else {
        cout << "Shortest Path from " << s << " to " << t << ": ";
        for(int node : path) cout << node << " ";
        cout << endl;
    }
    return 0;
}