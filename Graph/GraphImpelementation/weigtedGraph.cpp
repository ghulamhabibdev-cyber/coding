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
    unordered_map<string, vector<pair<string, int>>> adj;

public:
    void addEdge(string src, string dist, int wt)
    {
        adj[src].push_back({dist, wt});
        adj[dist].push_back({src, wt});
    }
    void printGraph()
    {
        for (auto &p : adj)
        {
            cout << p.first << " -> ";
            for (int i = 0; i < p.second.size(); i++)
            {
                cout << p.second[i].first << " " << " wt " << p.second[i].second << " " << endl;
            }
        }
    }
};

int main()
{
    Graph g;
    g.addEdge("Lahore", "Karachi", 1000);
    g.addEdge("Lahore", "Fsd", 130);
    g.addEdge("FSD", "Islamabad", 430);
    g.printGraph();

    return 0;
}