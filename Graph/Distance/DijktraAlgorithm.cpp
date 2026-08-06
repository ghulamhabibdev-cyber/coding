#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

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
    void addEdges(int src, int dist, int wt)
    {
        resizeGraph(src, dist);
        adj[src].push_back({dist, wt});
        adj[dist].push_back({src, wt});
    }
    int dijkstra(int src, int dist)
    {
        int n = adj.size();
        if (src >= n || dist >= n)
            return INT_MAX;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> distance(n, INT_MAX);
        pq.push({0, src});
        distance[src] = 0;
        while (!pq.empty())
        {
            auto [d, node] = pq.top();
            pq.pop();         
            if (d > distance[node])
            {
                continue;
            }
            for (auto &edge : adj[node])
            {
                int neigh = edge.first;
                int wt = edge.second;

                if (d + wt < distance[neigh])
                {
                    distance[neigh] = d + wt;
                    pq.push({distance[neigh], neigh});
                }
            }
        }
        cout << "Overall distances from source " << src << ":" << endl;
        for (int i = 0; i < distance.size(); i++)
        {
            cout << "Node " << i << " : " << (distance[i] == INT_MAX ? -1 : distance[i]) << endl;
        }

        return distance[dist];
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
    int shortest_distance = wg.dijkstra(0, target);

    cout << "\nShortest distance to " << target << " is: " << shortest_distance << endl;

    return 0;
}
