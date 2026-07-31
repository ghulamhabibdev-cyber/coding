#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits>
#include <list>
#include <unordered_map>
using namespace std;

class A
{
};
void preparedAdjacenyList(unordered_map<int, list<int>> &adjList, vector<pair<int, int>> edges)
{
    for(auto i:edges)
    {
        int u=i.first;
        int v=i.second;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

}
void printAdjList(unordered_map<int, list<int>> &adjList)
{
    for(auto i:adjList)
    {
        cout<<i.first<<" -> ";
        for(auto j:i.second)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
vector<int>Bfs(unordered_map<int,list<int>>&adjList,int start)
{
    unordered_map<int,bool> visited;
    visited[start]=1;
    queue<int>q;
    q.push(start);
    vector<int>ans;
    ans.push_back(start);
    while(!q.empty())
    {
        int front =q.front();
        q.pop();
        for(auto i:adjList[front])
        {
            if(!visited[i])
            {
                visited[i]=1;
                q.push(i);
                ans.push_back(i);
            }
        }
    }
    return ans;
}
int main()
{
    vector<pair<int, int>> edges = {{0, 1}, {0, 2}, {1, 2}, {1, 3}, {2, 4}};
    unordered_map<int, list<int>> adjList;
    preparedAdjacenyList(adjList, edges);
    printAdjList(adjList);
    vector<int> result = Bfs(adjList, 0);
    for(auto i:result)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}