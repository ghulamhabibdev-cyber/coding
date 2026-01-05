#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits>
#include <list>
#include <unordered_map>
#include<map>
using namespace std;

class A
{
};
void preparedAdjacenyList(map<int, list<int>> &adjList, vector<pair<int, int>> &edges)
{
    for (auto i : edges)
    {
        int u = i.first;
        int v = i.second;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}
void printAdjacList(map<int, list<int>> &adjList)
{
    for (auto &i : adjList)
    {
        cout << i.first << "->";
        for (auto j : i.second)
        {
            cout << j << " , ";
        }
        cout << endl;
    }
}
void dfs(int node, unordered_map<int, bool> &visited, map<int, list<int>> &adjList, vector<int> &comp)
{
    comp.push_back(node);
    visited[node]=1;
    for (auto neighbor : adjList[node])
    {
        if (!visited[neighbor])
        {
            dfs(neighbor, visited, adjList, comp);
        }
    }
}
vector<vector<int>> depthFirstSearach(map<int, list<int>> &adjList)
{
    vector<vector<int>>ans;
    unordered_map<int,bool> visited;
    for (auto i : adjList)
    {
        if(!visited[i.first])
        {
            vector<int>comp;
            dfs(i.first,visited,adjList,comp);
            ans.push_back(comp);
        }
    }
    return ans;
}
int main()
{
    vector<pair<int,int>> edges = {{1, 2}, {2, 4}, {3, 4}, {4, 2}, {1,3}};
    map<int, list<int>> adjList;
    preparedAdjacenyList(adjList, edges);
    printAdjacList(adjList);
  vector<vector<int>>ans=  depthFirstSearach(adjList);
  for(auto i:ans)
  {
    for(auto j:i)
    {
        cout<<j<<" ";
    }
  }
    return 0;
}