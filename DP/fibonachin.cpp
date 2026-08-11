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
int fib(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    int prevPrev = 0;
    int prev = 1;
    for (int i = 2; i <= n; i++)
    {
        int curr = prevPrev + prev;
        prevPrev = prev;
        prev = curr;
    }
    return prev;
}
int main()
{
    int n = 4;
    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[n] << endl;
    int ans = fib(n);
    cout << "ans : " << ans << endl;
    return 0;
}