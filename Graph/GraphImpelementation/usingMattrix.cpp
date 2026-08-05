#include <iostream>
using namespace std;

class A
{
};
// this is graph using matrix of size
class Graph
{
public:
    int **graph;
    int row;
    Graph(int n)
    {
        row = n;
        graph = new int *[n];
        for (int i = 0; i < n; i++)
        {
            graph[i] = new int[n];
            for (int j = 0; j < n; j++)
            {
                graph[i][j] = 0;
            }
        }
    }
    void addEdges(int u, int v)
    {
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    void printGraph()
    {
        cout << "   ";
        for (int i = 0; i < row; i++)
        {
            cout << i << " ";
        }
        cout << endl;
        for (int i = 0; i < row; i++)
        {
            cout << i << "->";
            for (int j = 0; j < row; j++)
            {
                cout << graph[i][j] << " ";
            }
            cout << endl;
        }
    }
};
int main()
{
    Graph g(5);
    g.addEdges(0, 2);
    g.addEdges(1, 2);
    g.addEdges(2, 3);
    g.addEdges(3, 4);
    g.addEdges(1, 4);
    g.printGraph();
    return 0;
}