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
int minTramCapcity(int n)
{
    int minCapcity = INT_MIN;
    int entering = 0;
    int leaving = 0;
    int curr = 0;
    int prev = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> leaving;
        cin >> entering;
     
        if (i == 1)
        {
            curr = entering;
            minCapcity = entering;
        }
        else
        {
            curr = abs(curr - leaving + entering);

            int newCap = curr;
            if (newCap > minCapcity)
            {
                minCapcity = newCap;
            }
        }
    }

    return minCapcity;
}
int main()
{
    int n;
    cin >> n;
    int ans = minTramCapcity(n);
    cout << ans;

    return 0;
}