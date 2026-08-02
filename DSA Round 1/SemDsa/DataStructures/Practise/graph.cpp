#include <iostream>
using namespace std;

class graph
{
    int **mat;
    int nodes;

public:
    graph(int vertex)
    {
        this->nodes = vertex;
        mat = new int *[nodes];
        for (int i = 0; i < nodes; i++)
        {
            mat[i] = new int[nodes];
        }
        for (int i = 0; i < nodes; i++)
        {
            mat[i] = new int[nodes];
            for (int j = 0; j < nodes; j++)
            {
                mat[i][j] = 0;
            }
        }
    }
    void adjMatrix(int u, int v, bool isDirectd)
    {
        mat[u][v] = 1;
        if (!isDirectd)
        {
            mat[v][u] = 1;
        }
    }
    void printGraph()
    {
        for (int i = 0; i < nodes; i++)
        {
            for (int j = 0; j < nodes; j++)
            {
                cout << mat[i][j] << " ";
            }
            cout << "\n";
        }
    }
};

int main()
{
    graph g(4);
    g.adjMatrix(0, 1, false);
    g.adjMatrix(1, 2, false);
    g.adjMatrix(2, 3, false);
    g.printGraph();

    return 0;
}