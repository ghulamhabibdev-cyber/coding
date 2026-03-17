#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <list>
#include <limits>
#include <list>
using namespace std;

class graph
{
    int **adjMatrix;
    int vertices;
public:
    graph(int v)
    {
        vertices = v;
        adjMatrix = new int *[vertices];

        for (int i = 0; i < vertices; i++)
        {
            adjMatrix[i] = new int[vertices];
        }

        // initialize matrix to 0
        for (int i = 0; i < vertices; i++)
            for (int j = 0; j < vertices; j++)
                adjMatrix[i][j] = 0;
    }
    void addEdge(int u, int v, bool dir = false)
    {
        adjMatrix[u][v] = 1;
        if (!dir)
            adjMatrix[v][u] = 1; // undirected graph
    }
    void printGraph()
    {
        for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < vertices; j++)
                cout << adjMatrix[i][j] << " ";
            cout << endl;
        }
    }
};

int main()
{
    graph g(4);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);

    g.printGraph();
    return 0;
}