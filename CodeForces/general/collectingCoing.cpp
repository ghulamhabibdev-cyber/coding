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
bool isPossibleToDivid(int a, int b, int c, int n)
{
    int m = max({a, b, c});
    int requr = (m - a) + (m - b) + (m - c);
    if (n < requr)
    {
        return false;
    }
    return ((n - requr) % 3 == 0);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c, n;
        cin >> a >> b >> c >> n;
        bool yes = isPossibleToDivid(a, b, c, n);
        if (yes)
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