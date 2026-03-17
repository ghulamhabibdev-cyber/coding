#include <bits/stdc++.h>
using namespace std;
class graph
{
public:
    unordered_map<int, list<pair<int, int>>> adjList;
    void addEdge(int u, int v, int wiehgt)
    {
        pair<int, int> p = make_pair(v, wiehgt);
        adjList[u].push_back(p);
    }
    void printAdj()
    {
        for (auto i : adjList)
        {
            cout << i.first << "->";
            for (auto j : i.second)
            {
                cout << "(" << j.first << ", " << j.second << "), ";
            }
            cout << endl;
        }
    }
    void dfs(int node, unordered_map<int, bool> &visted, stack<int> &s)
    {
        visted[node] = true;
        for (auto neigh : adjList[node])
        {
            if (!visted[neigh.first])
            {
                dfs(neigh.first, visted, s);
            }
        }
        s.push(node);
    }
    void getShortesPath(int src, vector<int> &dist, stack<int> &s)
    {
        dist[src] = 0;
        while (!s.empty())
        {
            int top = s.top();
            s.pop();
            if(dist[top]!=INT_MAX)
            {
                for(auto i:adjList[top])
                {
                    if(dist[top]+i.second<dist[i.first])
                    {
                        dist[i.first]=dist[top]+i.second;
                    }
                }
            }
            /* code */
        }
    }
    
};

// void perparAjacencyList(unordered_map<int, list<int>> &adjList, vector<pair<int, int>> edges)
// {
//     for (int i = 0; i < edges.size(); i++)
//     {
//         int u = edges[i].first;
//         int v = edges[i].second;
//         adjList[u].push_back(v);
//         adjList[v].push_back(u);
//     }
// }
// void bfs(unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited, vector<int> &ans, int node)
// {
//     queue<int> q;
//     q.push(node);
//     visited[node] = 1;
//     while (!q.empty())
//     {
//         int frontNode = q.front();
//         q.pop();
//         ans.push_back(frontNode);
//         for (auto i : adjList[frontNode])
//         {
//             if (!visited[i])
//             {
//                 q.push(i);
//                 visited[i] = 1;
//             }
//         }
//         /* code */
//     }
// }
// vector<int> BFS(int vertex, vector<pair<int, int>> edges)
// {
//     unordered_map<int, list<int>> adjList;
//     vector<int> ans;
//     unordered_map<int, bool> visited;
//     perparAjacencyList(adjList, edges);
//     // traverse all component of graph
//     for (int i = 0; i < vertex; i++)
// //     {
//         if (!visited[i])
//         {
//             bfs(adjList, visited, ans, i);
//         }
//     }
//     return ans;
// }

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

    graph g;
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 6);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);
    g.printAdj();
    int n = 6;
    unordered_map<int, bool> visited;
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            g.dfs(i, visited, s);
        }
    }
    int src=1;
    vector<int>dist(n,0);
    for(int i=0;i<n;i++)
    {
        dist[i]=INT_MAX;
    }
    g.getShortesPath(src,dist,s);
    for(int i=0;i<dist.size();i++)
    {
        cout<<dist[i]<<" ";
    }
    return 0;
}