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

class Graph
{
public:
    unordered_map<string, vector<string>> adjList;
    void addEdges(string src, string dist)
    {
        adjList[src].push_back(dist);
    }
    void addTwo(string src, string dist)
    {
        adjList[src].push_back(dist);
        adjList[dist].push_back(src);
    }
    void printGraph()
    {
        for (auto &p : adjList)
        {
            cout << p.first << "-> ";
            for (int i = 0; i < p.second.size(); i++)
            {
                cout << p.second[i] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph g;
    g.addEdges("Karachi", "Lahore");
    g.addEdges("Lahore", "Islamabad");
    g.addTwo("Lahore", "fsd");
    g.addTwo("fsd", "Tandiawala");
    g.addTwo("fsd", "Quetta");
    g.addTwo("Lahore", "Quetta");
    g.printGraph();

    return 0;
}