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
bool isPossible(string n, string t)
{
    sort(n.begin(), n.end());
    sort(t.begin(), t.end());
    return n == t;
}
int main()
{
    int t;
    cin >> t;
    while (t--)

    {
        string n, t;
        int len;
        cin>>len;
        cin >> n >> t;
        bool ans = isPossible(n, t);
        if (ans)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}