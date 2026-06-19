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
class BrowserHistory
{
    int curr;
    int visitIndex;
    vector<string>pages;
public:
    BrowserHistory(string homepage)
    {
        pages.push_back(homepage);
        curr=visitIndex=0;
    }

    void visit(string url)
    {
        pages.push_back(url);
        visitIndex++;
        curr=visitIndex;
    }

    string back(int steps)
    {
        while(curr>0&&steps>0)
        {
            curr--;
            steps--;
        }
        return pages[curr];
    }

    string forward(int steps)
    {
        while(curr<visitIndex&&steps>0)
        {
            curr++;
            steps--;
        }
        return pages[curr];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
int main() {
    
    return 0;
}