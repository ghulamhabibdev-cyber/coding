#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits>
#include <list>
using namespace std;

class A
{
};
class Graph
{
    vector<vector<pair<int, int>>> edges;

public:
    void resizeGraph(int src, int dist)
    {
        int maxi = max(src, dist);
        if (maxi >= edges.size())
        {
            edges.resize(maxi + 1);
        }
    }
    void addEdges(int src, int dist, int wt)
    {
        resizeGraph(src, dist);
        edges[src].push_back({dist, wt});
        edges[dist].push_back({src, wt});
    }
    vector<int> FindPathUsingDijktra(int src, int dist)
    {

        int n = edges.size();
        vector<int> res(n, INT_MAX);
        if (src >= n || dist >= n)
        {
            return {-1};
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({src, 0});
        while (!pq.empty())
        {
            pair<int, int> p = pq.top();
            pq.pop();
            int node = p.first;
            int d = p.second;
            for (int i = 0; i < edges[node].size(); i++)
            {
                pair<int, int> newP = edges[node][i];
                int neigh = newP.first;
                int wt = newP.second;
                if (d > res[node])
                {
                    continue;
                    ;
                }
                if (d + wt < res[neigh])
                {
                    pq.push({neigh, d + wt});
                    res[neigh] = d + wt;
                }
            }
        }
        return res;
    }
};
int main()
{
    Graph wg;
    wg.addEdges(0, 1, 7);
    wg.addEdges(0, 2, 12);
    wg.addEdges(1, 3, 9);
    wg.addEdges(2, 4, 10);
    wg.addEdges(4, 3, 4);
    wg.addEdges(3, 5, 1);
    wg.addEdges(4, 5, 5);

    int target = 5;
    vector<int> res = wg.FindPathUsingDijktra(0, target);
    for (int i = 0; i < res.size(); i++)
    {
        cout << i << " : " << res[i] << endl;
    }
    return 0;
}