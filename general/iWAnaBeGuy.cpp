#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits>
#include <unordered_set>
#include <list>
using namespace std;

class A
{
};
bool isWanaGuy(int n)
{
    unordered_set<int> set;
    int xLen;
    cin >> xLen;
    for (int i = 0; i < xLen; i++)
    {
        int lev;
        cin >> lev;
        set.insert(lev);
    }
    int yLen;
    cin>>yLen;
    for (int i = 0; i < yLen; i++)
    {
        int lev;
        cin >> lev;
        set.insert(lev);
    }
    return set.size() == n;
}
int main()
{
    int n;
    cin >> n;
    bool isWin = isWanaGuy(n);
    if (isWin)
    {
        cout << "I become the guy.";
        return 0;
    }
    cout << "Oh, my keyboard!";
    return 0;
}