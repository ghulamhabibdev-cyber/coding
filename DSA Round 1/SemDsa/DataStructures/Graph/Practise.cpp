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

class graph
{
    int **adjMatrix;
    int vertices;
    // void dfs(int node)

public:
    graph(int v)
    {
        this->vertices = v;
        adjMatrix = new int *[vertices];
        for (int i = 0; i < vertices; i++)
        {
            adjMatrix[i] = new int[vertices];
        }
        for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < vertices; j++)
            {
                adjMatrix[i][j] = 0;
            }
        }
    }
    void prepareAdjMatrix(int u, int v, bool dir)
    {
        adjMatrix[u][v] = 1;
        if (!dir)
        {
            adjMatrix[u][v] = 1;
        }
    }
    void printAdjMatrix()
    {
        for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < vertices; j++)
            {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    vector<int> bfs(int startNode)
    {
        const int row = vertices;
        const int col = vertices;
        int visited[5] = {0};
        visited[startNode] = 1;
        queue<int> q;
        q.push(startNode);
        vector<int> ans;
        // ans.push_back(startNode);
        while (!q.empty())
        {
            int curr = q.front();
            ans.push_back(curr);
            q.pop();
            for (int i = curr; i < vertices; i++)
            {
                if (adjMatrix[curr][i] == 1 && !visited[i])
                {
                    visited[i] = 1;
                    q.push(i);
                }
            }
        }
        return ans;
    }
    
    vector<vector<int>> depthFirstSearch()
    {
    }
};

int main()
{
    graph g(6);

    // undirected graph
    g.prepareAdjMatrix(0, 1, false);
    g.prepareAdjMatrix(0, 2, false);
    g.prepareAdjMatrix(1, 3, false);
    g.prepareAdjMatrix(1, 4, false);
    g.prepareAdjMatrix(2, 5, false);

    cout << "Adjacency Matrix:\n";
    g.printAdjMatrix();

    cout << "\nBFS starting from node 0:\n";
    vector<int> bfsResult = g.bfs(0);

    for (int node : bfsResult)
        cout << node << " ";

    cout << endl;

    return 0;
}
