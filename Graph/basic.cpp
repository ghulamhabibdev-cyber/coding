#include <iostream>
#include <vector>

using namespace std;

class Graph
{
private:
    int **graph;
    int size;

public:
    // Constructor
    Graph(vector<vector<int>> arr)
    {
        size = arr.size();

        // 1. First allocate the array of row pointers
        graph = new int *[size];

        // 2. Allocate columns and copy data
        for (int i = 0; i < size; i++)
        {
            graph[i] = new int[size];
            for (int j = 0; j < size; j++)
            {
                graph[i][j] = arr[i][j];
            }
        }
    }

    // Print helper to test the graph
    void printGraph()
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                cout << graph[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Destructor to prevent memory leaks
    ~Graph()
    {
        for (int i = 0; i < size; i++)
        {
            delete[] graph[i];
        }
        delete[] graph;
    }
};
class GraphAdj
{
public:
    vector<vector<int>> adjList;

    // Helper function to safely resize the adjacency list dynamically
    void resizeIfNeeded(int src, int dest)
    {
        int max_vertex = max(src, dest);
        if (max_vertex >= adjList.size())
        {
            adjList.resize(max_vertex + 1);
        }
    }

    // Add a single edge: arr = {source, destination}
    void addedges(vector<int> arr)
    {
        int source = arr[0];
        int dist = arr[1];

        resizeIfNeeded(source, dist); // Ensure indices exist

        adjList[source].push_back(dist);
        adjList[dist].push_back(source);
    }

    // Add multiple edges: arr = {{u1, v1}, {u2, v2}, ...}
    void addedges(vector<vector<int>> arr)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            vector<int> edgs = arr[i];
            int src = edgs[0];
            int dist = edgs[1];

            resizeIfNeeded(src, dist); // Ensure indices exist

            adjList[src].push_back(dist);
            adjList[dist].push_back(src);
        }
    }

    void printGraph()
    {
        for (int i = 0; i < adjList.size(); i++)
        {
            cout << "Vertex " << i << ": ";
            for (int j = 0; j < adjList[i].size(); j++)
            {
                cout << adjList[i][j] << " ";
            }
            cout << endl;
        }
    }
};
int main()
{
    vector<vector<int>> matrix = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};

    // Graph g(matrix);
    // g.printGraph();
    GraphAdj g;
    vector<vector<int>> arr = {{1, 2}, {3, 1}, {2, 4}, {1, 4}, {3, 4}};
    g.addedges(arr);
    g.printGraph();

    return 0;
}
