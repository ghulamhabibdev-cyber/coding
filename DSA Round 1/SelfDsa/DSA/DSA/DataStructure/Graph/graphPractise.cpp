#include <bits/stdc++.h>
using namespace std;
template <typename t>
class graph
{
public:
    unordered_map<int, list<int>> adj;
    // insert   edges
    /*main pupose of making this method is to make eges  against given
    to next node and that node to back if this is undirected graph
    like 1->2
         2->1
         2->3
         3->1*/
    void insertEdges(int u, int v, bool direction)
    {
        adj[u].push_back(v);
        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }
    /*now i make a function that print data against one node to its connected
    neighbour
    1->2,3
    2->1,3
    3->1,2*/
    void printAjacenyList()
    {
        for (auto node : adj)
        {
            cout << node.first << "-->";
            for (auto edges : node.second)
            {
                cout << edges << ", ";
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
    cout << "BFS Traversal: ";
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

// template <typename t>
// class graph
// {
// private:
//     unordered_map<t, list<t>> adacentList;

// public:
//     void AddEdges(t u, t v, bool direction)
//     {
//         adacentList[u].push_back(v);
//         if (direction == 0)
//         {
//             adacentList[v].push_back(u);
//         }
//     }
//     void printAdjacentList()
//     {
//         for (auto i : adacentList)
//         {
//             cout << i.first << "->";
//             for (auto j : i.second)
//             {
//                 cout << j << ", ";
//             }
//             cout << endl;
//         }
//     }
// };
// // now you to do bfs
// void preparAdjcancyList(map<int, list<int>> &adList, vector<pair<int, int>> edges)
// {
//     for (int i = 0; i < edges.size(); i++)
//     {
//         int u = edges[i].first;
//         int v = edges[i].second;
//         adList[u].push_back(v);
//         adList[v].push_back(u);
//     }
//     for (auto &it : adList)
//     {
//         it.second.sort();
//     }
// }
// void bfs(int node, unordered_map<int, bool> &visited, map<int, list<int>> &adList, vector<int> &ans)
// {
//     queue<int> q;
//     q.push(node);
//     visited[node] = true;

//     while (!q.empty())
//     {
//         int frontNode = q.front();
//         q.pop();
//         ans.push_back(frontNode);
//         for (auto neigh : adList[frontNode])
//         {
//             if (!visited[neigh])
//             {
//                 q.push(neigh);
//                 visited[neigh] = true;
//             }
//         }
//     }
// }
// vector<int> BFSTraversal(vector<pair<int, int>> edges, int n)
// {
//     // #-> make adjaceny list
//     map<int, list<int>> adList;
//     preparAdjcancyList(adList, edges);
//     // we need a map of int and bool to record which node is already visited
//     unordered_map<int, bool> visited;
//     vector<int> ans;
//     for (auto node : adList)
//     {
//         int data = node.first;
//         cout << "I am data  : " << data << endl;
//         if (!visited[data])
//         {
//             bfs(data, visited, adList, ans);
//         }
//     }

//     return ans;
// }
// // now #->DFS
// void dfs(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adList, vector<int> &ans)
// {
//     ans.push_back(node);
//     visited[node] = true;
//     vector<int> keys;

//     for (int neigh : adList[node])
//     {
//         if (!visited[neigh])
//         {
//             dfs(neigh, visited, adList, ans);
//         }
//     }
// }
// vector<int> DFSTravsersal(vector<pair<int, int>> edges, int n)
// {
//     // make adjaceeny list
//     // make unordered_map
//     unordered_map<int, list<int>> adList;
//     for (auto d : edges)
//     {
//         int u = d.first;
//         int v = d.second;
//         adList[u].push_back(v);
//         adList[v].push_back(u);
//     }
//     // for (auto &it : adList)
//     // {
//     //     it.second.sort();
//     // }
//     unordered_map<int, bool> visited;
//     vector<int> ans;
//     vector<int> keys;
//     // ensures 1,2,3,4,5 order

//     for (auto d : adList)
//     {
//         int node = d.first;
//         if (!visited[node])
//         {
//             dfs(node, visited, adList, ans);
//         }
//     }
//     return ans;
// }

// #cylic detection
//  bool isCyclicGraph(int node, unordered_map<int, list<int>> &adjList,
//                     unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited)
//  {
//      visited[node] = 1;
//      dfsVisited[node] = 1;
//      for (auto neigh : adjList[node])
//      {
//          if (!visited[neigh])
//          {
//              bool fond = isCyclicGraph(neigh, adjList, visited, dfsVisited);
//              if (fond)
//              {
//                  return true;
//                    cout<<"Neigh return : "<<neigh<<endl;
//              }
//          }
//          else if (dfsVisited[neigh])
//          {
//              cout<<"Neigh return : "<<neigh<<endl;
//              return true;
//          }
//      }
//      dfsVisited[node]=0;
//      return false;
//  }
//  bool cycleDetection(vector<pair<int, int>> edges, int v, int e)
//  {
//      // make adjacelist
//      unordered_map<int, list<int>> adjList;
//      for (int i = 0; i < edges.size(); i++)
//      {
//          int u = edges[i].first;
//          int v = edges[i].second;
//          adjList[u].push_back(v);
//          adjList[v].push_back(u);
//      }
//      unordered_map<int, bool> visited;
//      unordered_map<int, bool> dfsVisited;
//      for (auto i : adjList)
//      {
//          int node = i.first;
//          if (!visited[node])
//          {
//              bool fond = isCyclicGraph(node, adjList, visited, dfsVisited);
//              if (fond)
//              {
//                  return true;
//              }
//          }
//      }
//      return false;
//  }

// #->TopoLogical sort
// topological sort apply only on acyclic directed graph
// void topoSort(int node, unordered_map<int, list<int>> &adList, unordered_map<int, bool> &visited, stack<int> &s)
// {
//     visited[node] = 1;
//     for (auto neigh : adList[node])
//     {
//         if (!visited[neigh])
//         {
//             topoSort(neigh, adList, visited, s);
//         }
//     }
//     s.push(node);
// }
// vector<int> topoLosgicalSort(vector<pair<int, int>> edges, int v, int e)
// {
//     // #->require ds stack unoredered_map of int ,list<int> ,unordered_map<int,bool>
//     //  1->make adjancy list
//     unordered_map<int, list<int>> adList;
//     stack<int> s;
//     vector<int> ans;
//     unordered_map<int, bool> visited;

//     for (auto data : edges)
//     {
//         int u = data.first;
//         int v = data.second;
//         adList[u].push_back(v);
//     }
//     for (int i = 0; i < v; i++)
//     {

//         if (!visited[i])
//         {
//             topoSort(i, adList, visited, s);
//         }
//     }
//     while (!s.empty())
//     {
//         ans.push_back(s.top());
//         s.pop();
//         /* code */
//     }
//     return ans;
// }

// khmans algrthym to topological sort
// vector<int> topologicalSortByKahan(vector<vector<int>> edges, int v, int e)
// {
//     // make adjancy list
//     unordered_map<int, list<int>> adList;
//     for (int i = 0; i < v; i++)
//     {
//         int u = edges[i][0];
//         int v = edges[i][1];
//         adList[u].push_back(v);
//     }
//     // #->make indegree of lsit
//     vector<int> indegree(v + 1, 0);
//     for (auto i : adList)
//     {
//         for (auto j : i.second)
//         {
//             indegree[j++];
//         }
//     }
//     queue<int> q;
//     vector<int> ans;
//     for (int i = 1; i <= v; i++)
//     {
//         if (indegree[i] == 0)
//         {
//             q.push(i);
//         }
//     }
//     while (!q.empty())
//     {
//         int frontNode = q.front();
//         q.pop();
//         ans.push_back(frontNode);
//         for (auto neigh : adList[frontNode])
//         {
//             indegree[neigh]--;
//             if (indegree[neigh] == 0)
//             {
//                 q.push(neigh);
//             }
//         } /* code */
//     }
//     return ans;
// }
// ===============================================Find Shortes path====================

// vector<int> shortestPathFromSourceToDestination(vector<pair<int, int>> edges, int n, int m, int s, int t)
// {
//     // prepare adjacency list
//     unordered_map<int, list<int>> adjList;
//     for (int i = 0; i < edges.size(); i++)
//     {
//         int u = edges[i].first;
//         int v = edges[i].second;
//         adjList[u].push_back(v);
//         adjList[v].push_back(u);
//     }
//     //do bfs
//     unordered_map<int,bool>visited;
//     unordered_map<int,int>parent;
//     queue<int>q;
//     q.push(s);
//     parent[s]=-1;
//     visited[1]=1;
//     while (!q.empty())
//     {
//         int front=q.front();
//         q.pop();
//         for(auto neigh:adjList[front])
//         {
//             if(!visited[neigh])
//             {
//                 parent[neigh]=front;
//                 visited[neigh]=1;
//                 q.push(neigh);
//             }
//         }
//     }
//     // find route from parent
//     vector<int>ans;
//     int current=t;
//     ans.push_back(t);
//     while (current!=s)
//     {
//         current=parent[current];
//         ans.push_back(current);
//     }
//     reverse(ans.begin(),ans.end());
//     return ans;
// }

// this is how to find shortest path using dijikrats algo

// vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source)
// {
//     // step #1-> prepare adjlist of undirected graph
//     unordered_map<int, list<pair<int, int>>> adList;
//     for (int i = 0; i < edges; i++)
//     {
//         int u = vec[i][0];
//         int v = vec[i][1];
//         int w = vec[i][2];
//         adList[u].push_back(make_pair(v, w));
//         adList[v].push_back(make_pair(u, w));
//     }
//     // step#->inilise ditance with infite
//     vector<int> distance(vertices);
//     for (int i = 0; i < vertices; i++)
//     {
//         distance[i] = INT_MAX;
//     }
//     // make sorurcs distance to zero
//     distance[source] = 0;
//     set<pair<int, int>> st;
//     st.insert(make_pair(0, 0));
//     while (!st.empty())
//     {
//         auto top = *(st.begin());
//         int topNode = top.second;
//         int topNodeDistance = top.first;
//         st.erase(st.begin());
//         for (auto neigh : adList[topNode])
//         {
//             if (topNodeDistance + neigh.second < distance[neigh.first])
//             {
//                 auto record = st.find(make_pair(distance[neigh.first], neigh.first));
//                 if (record != st.end())
//                 {
//                     st.erase(record);
//                 }
//                 distance[neigh.first] = topNodeDistance + neigh.second;
//                 st.insert(make_pair(distance[neigh.first], neigh.first));
//             }
//         }
//     }
//     return distance;
// }
// vector<pair<pair<int, int>, int>> calculatPrimMSt(int n, int m, vector<pair<pair<int, int>, int>> g)
// {
//     // step #1->get adjacency list
//     unordered_map<int, list<pair<int, int>>> adList;
//     for (int i = 0; i < g.size(); i++)
//     {
//         int u = g[i].first.first;
//         int v = g[i].first.second;
//         int w = g[i].second;
//         adList[u].push_back(make_pair(v, w));
//         adList[v].push_back(make_pair(u, w));
//     }
//     // two make ds
//     vector<int> key(n + 1, INT_MAX);
//     vector<bool> mst(n + 1, false);
//     vector<int> parent(n + 1, -1);
//     key[1] = 0;
//     parent[1] = -1;
//     // #-> get min value of mst and get node
//     for (int i = 0; i <= n; i++)
//     {
//         int mini = INT_MAX;
//         int u;
//         for (int v = 1; v <= n; v++)
//         {
//             if (mst[v] == false && key[v] < mini)
//             {
//                 u = v;
//                 mini = key[v];
//             }
//         }
//         mst[u] = true;
//         // now get neighor
//         for (auto it : adList[u])
//         {
//             int v = it.first;
//             int w = it.second;
//             if (mst[v] == false && w < key[v])
//             {
//                 parent[v] = u;
//                 key[v] = w;
//             }
//         }
//     }
//     vector<pair<pair<int, int>, int>> result;
//     for (int k = 2; k <= n; k++)
//     {
//         result.push_back({{parent[k], k}, key[k]});
//     }
//     return result;
// }
// #find the articulation point of graph by removing   that node a graph b
// break into two or more component
// void dfs(int node,int parent,
//     unordered_map<int,list<int>>&adj,
//     unordered_map<int,bool>&vis, vector<int>&dis, vector<int>&low,vector<int>&ap,int &timer)
// {
//     vis[node]=true;
//     dis[node]=low[node]=timer++;
//     int child=0;
//     for(auto nbr:adj[node])
//     {
//         if(nbr==parent)
//         {
//             continue;
//         }
//         if(!vis[nbr])
//         {
//             dfs(nbr,node,adj,vis,dis,low,ap,timer);
//             low[node]=min(low[node],low[nbr]);
//             if(low[nbr]>=dis[node]&&parent!=-1)
//             {
//                 ap[node]=1;
//             }
//             child++;
//         }
//         else{
//             low[node] = min(low[node], dis[nbr]);
//         }
//     }
//     if(parent==-1&&child>1)
//     {
//        ap[node]=1;
//     }
// }
// vector<int>findArticulationPont(vector<pair<int,int>>edges,int n,int e)
// {
//     unordered_map<int,list<int>>adj;
//     for(int i=0;i<edges.size();i++)
//     {
//         int u=edges[i].first;
//         int v=edges[i].second;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }
//     vector<int>dis(n,-1);
//     vector<int>low(n,-1);
//     unordered_map<int,bool>vis;
//     vector<int>ap(n,false);
//     int timer=0;
//     for(int i=0;i<n;i++)
//     {
//         if(!vis[i]){
//             dfs(i,-1,adj,vis,dis,low,ap,timer);
//         }
//     }
//     return ap;
// }

// find bridges in graph a bridge is poin in graph by removing that
// edge graph become divided in to are more part

// void dfs(int node, int parent,
//          unordered_map<int, list<int>> &adj,
//          vector<int> &dis, vector<int> &low, unordered_map<int, bool> &vis, vector<vector<int>> &result, int &timer)
// {
//     vis[node] = true;
//     dis[node] = low[node] = timer++;
//     for (auto nbr : adj[node])
//     {
//         if (nbr == parent)
//         {
//             continue;
//         }
//         if (!vis[nbr])
//         {
//             dfs(nbr, node, adj, dis, low, vis, result, timer);
//             low[node] = min(low[node], low[nbr]);
//             if (low[nbr] > dis[node])
//             {
//                 // to check bridge
//                 vector<int> ans;
//                 ans.push_back(node);
//                 ans.push_back(nbr);
//                 result.push_back(ans);
//             }
//         }
//         else
//         {
//             low[node] = min(low[node], dis[nbr]);
//         }
//     }
// }
// vector<vector<int>> findBridgesPointEdge(vector<pair<int, int>> edges, int n, int e)
// {
//     // prepare adj list
//     unordered_map<int, list<int>> adj;
//     for (int i = 0; i < edges.size(); i++)
//     {
//         int u = edges[i].first;
//         int v = edges[i].second;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }
//     vector<int> dis(n, -1);
//     vector<int> low(n, -1);
//     unordered_map<int, bool> vis;
//     int timer = 0;
//     vector<vector<int>> result;
//     for (int i = 0; i < n; i++)
//     {
//         if (!vis[i])
//         {
//             dfs(i, -1, adj, dis, low, vis, result, timer);
//         }
//     }
//     return result;
// }

// kosa ruju algo is use to find stribgkt connected component
// void dfs(int node, unordered_map<int, bool> &vis, stack<int> &st, unordered_map<int, list<int>> &adj)
// {
//     vis[node] = true;
//     for (auto nbr : adj[node])
//     {
//         if (!vis[nbr])
//         {
//             dfs(nbr, vis, st, adj);
//         }
//     }
//     st.push(node);
// }
// void revDfs(int node, unordered_map<int, list<int>> &transpose, unordered_map<int, bool> &vis)
// {
//     vis[node] = true;
//     cout<<node<<" ";
//     for (auto nbr : transpose[node])
//     {
//         if (!vis[nbr])
//         {
//             revDfs(nbr, transpose, vis);
//         }
//     }
// }
// int kosarajuAlogrythm(int v, vector<vector<int>> edges)
// {
//     // step 1 make adjaceny list
//     unordered_map<int, list<int>> adj;
//     for (int i = 0; i < edges.size(); i++)
//     {
//         int u = edges[i][0];
//         int v = edges[i][1];
//         adj[u].push_back(v);
//     }
//     // call dps for toplogical sort
//     unordered_map<int, bool> vis;
//     stack<int> st;
//     for (int i = 0; i < v; i++)
//     {
//         if (!vis[i])
//         {
//             dfs(i, vis, st, adj);
//         }
//     }
//     // take transpose
//     unordered_map<int, list<int>> transpose;
//     for (int i = 0; i < v; i++)
//     {
//         vis[i] = false;
//         for (auto nbr : adj[i])
//         {
//             transpose[nbr].push_back(i);
//         }
//     }
//     int count = 0;
//     while (!st.empty())
//     {
//         int top = st.top();
//         st.pop();
//         if (!vis[top])
//         {
//             count++;
//             cout<<"SCC : "<< count<<" # " ;
//             revDfs(top, transpose, vis);
//             cout<<endl;
//         }
//     }
//     return count;
// }

// Bellman ford algotthym is use to find shortest path between source and destionation
// it is use for both negative and pos weight graph like
int bellManFordAlgo(int n, int m, int src, int dest, vector<vector<int>> edges)
{

    vector<int> dis(n + 1, 1e9);
    dis[src] = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int from = edges[j][0];
            int to = edges[j][1];
            int wt = edges[j][2];
            if(dis[from] != 1e9 && (dis[from] + wt < dis[to]))
            {
                dis[to]=dis[from]+wt;
            }
        }
    }
    bool flag=0;
     for (int j = 0; j < m; j++)
        {
            int from = edges[j][0];
            int to = edges[j][1];
            int wt = edges[j][2];
            if(dis[from] != 1e9 && (dis[from] + wt < dis[to]))
            {
               flag=1;
            }
        }

    if (flag == 0)
    {
        return dis[dest];
    }

    return -1;
}
int main()
{
    // graph<int> g;
    // // now i will first ask for node then total edges between them
    // int node;
    // cout << "No of node : \n";
    // cin >> node;
    // int edges;
    // cout << "No of edges : \n";
    // cin >> edges;
    // for (int i = 0; i < edges; i++)
    // {
    //     int u, v;
    //     cin >> u >> v;
    //     g.insertEdges(u, v, 1);
    // }
    // g.printAjacenyList();
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
    // graph<int> g;
    // int edges;
    // cout << "No of edges \n";
    // cin >> edges;
    // for (int i = 0; i < edges; i++)
    // {
    //     int u, v;
    //     cin >> u >> v;
    //     bool d = 0;
    //     g.AddEdges(u, v, d);
    // }
    // g.printAdjacentList();
    // bfs traversl
    // int n=5;
    // int vertex = 5;
    // vector<pair<int, int>> edges = {{1, 3}, {1, 4}, {2, 4}, {3, 4}, {4, 5}};
    // vector<int> result = BFSTraversal(edges, vertex);
    // for (int i = 0; i < result.size(); i++)
    // {
    //     cout << result[i] << " ";
    // }
    // cout << endl;
    // // DFS seach using
    // vector<pair<int, int>> edges = {{1, 2}, {1, 3}, {2, 4}, {3, 4}, {4, 5}};
    // vector<int> dfsResult = DFSTravsersal(edges, 3);
    // for (int i = 0; i < dfsResult.size(); i++)
    // {
    //     cout << dfsResult[i] << " ";
    // }
    // cout << endl
    // cout << "----------------------------------------------Cycle Detection----------------------------------\n";
    // int n = 4;
    // vector<pair<int, int>> edges = {{1, 2}, {2, 3}, {3, 4}, {4, 2}}; // cycle present
    // if (cycleDetection(edges, n, 9))
    //     cout << "Cycle Detected\n";
    // else
    //     cout << "No Cycle\n";
    cout << "----------------------------------------------------------------Graph sorts------------------------------------------------------\n";
    // int v = 6, e = 6;
    // vector<pair<int, int>> edges = {{5, 2}, {5, 0}, {4, 0}, {4, 1}, {2, 3}, {3, 1}};
    // vector<int> ans = topoLosgicalSort(edges, v, e);
    // cout << "Topological Sort: ";
    // for (auto x : ans)
    // cout << x << " ";
    // cout << endl;
    // int v = 5, e = 5;
    // vector<vector<int>> edges = {
    //     {1, 2},
    //     {1, 3},
    //     {2, 5},
    //     {3, 5},
    //     {5, 4},
    // };
    // vector<int> ans = topologicalSortByKahan(edges, v, e);
    // cout << "Topological Sort (Kahn's Algorithm): ";
    // for (auto x : ans)
    //     cout << x << " ";
    // cout << endl;
    // return 0;

    // int n = 9; // number of nodes (1..8)
    // int m = 9; // number of edges
    // vector<pair<int, int>> edges = {
    //     {1, 2}, {2, 5}, {5, 8}, // Path 1
    //     {1, 3},
    //     {3, 8}, // Path 2
    //     {1, 4},
    //     {4, 6},
    //     {6, 7},
    //     {7, 8} // Path 3
    // };

    // int s = 1, t = 8; // source & destination

    // vector<int> path = shortestPathFromSourceToDestination(edges, n, m, s, t);

    // if (path[0] == -1)
    // {
    //     cout << "No Path Exists!" << endl;
    // }
    // else
    // {
    //     cout << "Shortest Path from " << s << " to " << t << ": ";
    //     for (int node : path)
    //         cout << node << " ";
    //     cout << endl;
    // }

    // int vertices = 5, edges = 6;
    // vector<vector<int>> edgesList = {
    //     {0, 1, 2}, {0, 4, 8}, {1, 2, 3}, {1, 4, 5}, {2, 3, 7}, {3, 4, 9}};

    // int source = 0;
    // vector<int> result = dijkstra(edgesList, vertices, edges, source);

    // cout << "Shortest distances from source " << source << ":\n";
    // for (int i = 0; i < vertices; i++)
    // {
    //     cout << "Node " << i << " -> " << result[i] << "\n";
    // }

    // int n = 5, m = 6;
    // vector<pair<pair<int, int>, int>> edges = {
    //     {{1, 2}, 2}, {{1, 4}, 8}, {{2, 3}, 3}, {{2, 5}, 5}, {{3, 5}, 7}, {{4, 5}, 9}};
    // auto mst = calculatPrimMSt(n, m, edges);
    // cout << "🌳 MST Edges:\n";
    // for (auto e : mst)
    // {
    //     cout << e.first.first << " -- " << e.first.second
    //          << "  (weight: " << e.second << ")\n";
    // }

    // int n = 5;
    // int e = 5;
    // vector<pair<int, int>> edges;
    // edges.push_back(make_pair(0, 3));
    // edges.push_back(make_pair(3, 4));
    // edges.push_back(make_pair(0, 4));
    // edges.push_back(make_pair(0, 1));
    // edges.push_back(make_pair(1, 2));
    // vector<int>ap=findArticulationPont(edges,n,e);

    // for(int i=0;i<n;i++)
    // {
    //     if(ap[i]!=0)
    //     {
    //         cout<<i<<" ";
    //     }
    // }
    //   int v = 5, e = 5;
    //     vector<pair<int,int>> edges = {
    //         {0, 1}, {1, 2}, {2, 0}, {1, 3}, {3, 4}
    //     };

    //     vector<vector<int>> bridges = findBridgesPointEdge(edges, v, e);

    //     cout << "Bridges:\n";
    //     for (auto &b : bridges) {
    //         cout << b[0] << " - " << b[1] << "\n";
    //     }

    // int v = 5; // number of vertices (0 to 4)

    // // edges of the directed graph
    // vector<vector<int>> edges = {
    //     {1, 0},
    //     {0, 2},
    //     {2, 1},
    //     {0, 3},
    //     {3, 4}};

    // int sccCount = kosarajuAlogrythm(v, edges);

    // cout << "Number of Strongly Connected Components = " << sccCount << endl;

int n = 5, m = 8; // example graph
    vector<vector<int>> edges = {
        {1, 2, -1}, {1, 3, 4}, {2, 3, 3}, {2, 4, 2}, {2, 5, 2}, {4, 2, 1}, {4, 3, 5}, {5, 4, -3}};

    int src = 1, dest = 3;
    int ans = bellManFordAlgo(n, m, src, dest, edges);

    if (ans == -1)
        cout << "Negative cycle detected\n";
    else
        cout << "Shortest distance from " << src << " to " << dest << " = " << ans << "\n";









































































































































































































































































































































































































    return 0;
}