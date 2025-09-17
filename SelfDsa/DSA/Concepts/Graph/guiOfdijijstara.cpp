#include <bits/stdc++.h>
using namespace std;

// Color Macros
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

// Dijkstra with parent tracking
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source, vector<int> &parent)
{
    unordered_map<int, list<pair<int, int>>> adjList;
    for (int i = 0; i < edges; i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }

    vector<int> dist(vertices, INT_MAX);
    dist[source] = 0;
    parent[source] = -1;

    set<pair<int, int>> st;
    st.insert({0, source});

    while (!st.empty())
    {
        auto [d, node] = *st.begin();
        st.erase(st.begin());

        for (auto [nbr, wt] : adjList[node])
        {
            if (d + wt < dist[nbr])
            {
                st.erase({dist[nbr], nbr});
                dist[nbr] = d + wt;
                parent[nbr] = node;
                st.insert({dist[nbr], nbr});
            }
        }
    }
    return dist;
}

string getPath(int node, vector<int> &parent)
{
    vector<int> path;
    while (node != -1)
    {
        path.push_back(node);
        node = parent[node];
    }
    reverse(path.begin(), path.end());
    stringstream ss;
    for (int i = 0; i < path.size(); i++)
    {
        ss << path[i];
        if (i != path.size() - 1) ss << " -> ";
    }
    return ss.str();
}

int main()
{
    cout << CYAN << BOLD;
    cout << "=============================================\n";
    cout << "         🚀 Dijkstra Shortest Path Finder     \n";
    cout << "=============================================\n" << RESET;

    int vertices, edges;
    cout << YELLOW << "Enter number of vertices: " << RESET;
    cin >> vertices;
    cout << YELLOW << "Enter number of edges: " << RESET;
    cin >> edges;

    vector<vector<int>> edgeList(edges, vector<int>(3));
    cout << BLUE << "\nEnter edges (u v weight):\n" << RESET;
    for (int i = 0; i < edges; i++)
    {
        cin >> edgeList[i][0] >> edgeList[i][1] >> edgeList[i][2];
    }

    int source;
    cout << GREEN << "\nEnter source node: " << RESET;
    cin >> source;

    vector<int> parent(vertices, -1);
    vector<int> dist = dijkstra(edgeList, vertices, edges, source, parent);

    cout << CYAN << "\n=============================================\n";
    cout << "         📊 Shortest Paths Table              \n";
    cout << "=============================================\n";
    cout << left << setw(10) << "Node" << setw(15) << "Distance" << "Path\n";
    cout << "---------------------------------------------\n" << RESET;

    for (int i = 0; i < vertices; i++)
    {
        cout << left << setw(10) << i;
        if (dist[i] == INT_MAX)
        {
            cout << RED << setw(15) << "∞" << "No Path" << RESET << "\n";
        }
        else
        {
            cout << GREEN << setw(15) << dist[i] << RESET
                 << YELLOW << getPath(i, parent) << RESET << "\n";
        }
    }

    cout << CYAN << "=============================================\n" << RESET;
}
