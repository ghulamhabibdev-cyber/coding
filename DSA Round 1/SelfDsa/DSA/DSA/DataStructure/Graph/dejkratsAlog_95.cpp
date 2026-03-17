#include <bits/stdc++.h>
using namespace std;
class a
{
public:
};
// dijackrats alogrh
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source)
{
    // prepare adjacency list
    unordered_map<int, list<pair<int, int>>> adjList;
    for (int i = 0; i < edges; i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int weight = vec[i][2];
        adjList[u].push_back(make_pair(v, weight));
        adjList[v].push_back(make_pair(u, weight));
    }
    // make ditance ds to store ditances
    vector<int> distance(vertices);
    for (int i = 0; i < vertices; i++)
    {
        distance[i] = INT_MAX;
    }
    // to stroe distance , node
    set<pair<int, int>> st;
    distance[source] = 0;
    st.insert(make_pair(0, source));
    while (!st.empty())
    {
        // fetch to recore
        auto top = *(st.begin());
        int nodedistance = top.first;
        int topNode = top.second;
        // removo top
        st.erase(st.begin());
        for (auto neigh : adjList[topNode])
        {
            if (nodedistance + neigh.second < distance[neigh.first])
            {
                auto record = st.find(make_pair(distance[neigh.first], neigh.first));
                if (record != st.end())
                {
                    st.erase(record);
                }
                distance[neigh.first] = nodedistance + neigh.second;
                st.insert(make_pair(distance[neigh.first], neigh.first));
            }
        }
       
        /* code */
    }
     return distance;
}
int main()
{
    int vertices = 5, edges = 6;
    vector<vector<int>> edgesList = {
        {0, 1, 2}, {0, 4, 8}, {1, 2, 3}, {1, 4, 5}, {2, 3, 7}, {3, 4, 9}};

    int source = 0;
    vector<int> result = dijkstra(edgesList, vertices, edges, source);

    cout << "Shortest distances from source " << source << ":\n";
    for (int i = 0; i < vertices; i++)
    {
        cout << "Node " << i << " -> " << result[i] << "\n";
    }
    return 0;
}