#include <bits/stdc++.h>
using namespace std;
class a
{
public:
};
void dfs(int node, int parent, int &timer, vector<int> &disc, vector<int> &low,
         vector<vector<int>> &result,
         unordered_map<int, list<int>> &adList, unordered_map<int, bool> &visited)         
{
    visited[node]=true;
    disc[node]=low[node]=timer++;
    for(auto nbr:adList[node])
    {
        if(nbr==parent)
        {
            //to check if bnr is parent
            continue;
        }
        if(!visited[nbr])
        {
            dfs(nbr,node,timer,disc,low,result,adList,visited);
            low[node]=min(low[node],low[nbr]);
            if(low[nbr]>disc[node])
            {
                //to check bridge
                vector<int>ans;
                ans.push_back(node);
                ans.push_back(nbr);
                result.push_back(ans);
            }
        }
        else{
            // node is already visited and not parent mean making back edge
            //back Edges
            low[node]=min(low[node],disc[nbr]);

        }
    }
}
vector<vector<int>> findBrigdges(vector<vector<int>> &edges, int v, int e)
{
    unordered_map<int, list<int>> adList;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adList[u].push_back(v);
        adList[v].push_back(u);
    }
    int timer = 0;
    vector<int> disc(v);
    vector<int> low(v);
    int parent = -1;
    vector<vector<int>> result;
    unordered_map<int, bool> visited;
    for (int i = 0; i < v; i++)
    {
        disc[i] = -1;
        low[i] = -1;
    }
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            dfs(i, parent, timer, disc, low, result, adList, visited);
        }
    }
    return result;
}
int main()
{
      int v = 5, e = 5;
    vector<vector<int>> edges = {
        {0, 1}, {1, 2}, {2, 0}, {1, 3}, {3, 4}
    };

    vector<vector<int>> bridges = findBrigdges(edges, v, e);

    cout << "Bridges:\n";
    for (auto &b : bridges) {
        cout << b[0] << " - " << b[1] << "\n";
    }


    return 0;
}