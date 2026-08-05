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
    map<string, vector<string>> adjlist;

public:
    void AddEdjges(string src, string dist)
    {
        adjlist[src].push_back(dist);
        adjlist[dist].push_back(src);
    }
    void printGraph()
    {
        for (auto p : adjlist)
        {
            cout << p.first << " -> ";
            for (int i = 0; i < p.second.size(); i++)
            {
                cout << p.second[i];
                if (i < p.second.size() - 1)
                {
                    cout << " , ";
                }
            }
            cout << endl;
        }
    }
};
int main()
{
    Graph g;
    g.AddEdjges("Karchi", "Lahore");
    g.AddEdjges("Lahore", "Quetta");
    g.AddEdjges("quetta", "Karchi");
    g.AddEdjges("Quetta", "Faisalabad");
    g.AddEdjges("Dehli", "Pattana");
    g.printGraph();
    return 0;
}