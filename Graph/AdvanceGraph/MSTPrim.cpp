#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
class Graph
{
    vector<vector<pair<int, int>>> adj;
    void resizeGraph(int src, int dist)
    {
        int maxi = max(src, dist);
        if (maxi >= adj.size())
        {
            adj.resize(maxi + 1);
        }
    }
public:
    void addDirectedEdges(int src, int dist, int wt)
    {
        resizeGraph(src, dist);
        adj[src].push_back({dist, wt});
    }
    void addUndirectedEdges(int src, int dist, int wt)
    {
        resizeGraph(src, dist);
        adj[src].push_back({dist, wt});
        adj[dist].push_back({src, wt});
    }
    int MSTUsingPrims()
    {
        int n = adj.size();
        vector<bool> vis(n, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        int sum = 0;
        while (!pq.empty())
        {
            pair<int, int> p = pq.top();
            pq.pop();
            int wt = p.first;   
            int node = p.second; 
            if (!vis[node])
            {
                vis[node] = true;
                sum = sum + wt;
                for (int j = 0; j < adj[node].size(); j++)
                {
                    int neigh = adj[node][j].first;
                    int w = adj[node][j].second;
                    if (!vis[neigh])
                    {
                        pq.push({w, neigh});
                    }
                }
            }
        }
        return sum;
    }
};

int main()
{
    Graph mstG;
    mstG.addUndirectedEdges(0, 1, 5);
    mstG.addUndirectedEdges(0, 2, 1);
    mstG.addUndirectedEdges(2, 1, 2);
    mstG.addUndirectedEdges(2, 3, 3);
    mstG.addUndirectedEdges(1, 4, 3);
    mstG.addUndirectedEdges(1, 3, 2);
    mstG.addUndirectedEdges(3, 4, 6);
    int mst = mstG.MSTUsingPrims();
    cout << "Mininim weight of Tree : " << mst << endl;
    return 0;
}
