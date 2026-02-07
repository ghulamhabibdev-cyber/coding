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
int requireRemind(int x, int y, int n)
{

    int r = y % x;

    if (n < r)
        return 0;
    return r + x *((n - r) / x);
}
int main()
{
    // int t;
    // cin >> t;

    // for (int i = 0; i < t; i++)
    // {
    //     int x, y, n;
    //     cin >> x >> y >> n;
    //     int ans = requireRemind(x, y, n);
    //     cout << ans << endl;
    // }
cout<<40%50<<endl;
    return 0;
}