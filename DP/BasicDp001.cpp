#include <iostream>
#include <unordered_map>
using namespace std;
int fib(int n, unordered_map<int, int> &dp)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    if (dp.find(n) != dp.end())
    {
        return dp[n];
    }
    int ans = fib(n - 1, dp) + fib(n - 2, dp);
    dp[n] = ans;
    return ans;
}
int main()
{
    unordered_map<int, int> dp;
    int n = 5;
    int ans = fib(n, dp);
    cout << ans << endl;
    return 0;
}