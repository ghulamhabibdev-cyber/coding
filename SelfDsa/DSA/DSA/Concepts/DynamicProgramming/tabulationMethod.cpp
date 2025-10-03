#include <bits/stdc++.h>
using namespace std;
void fib(int n, vector<int> &dp)
{
    // this is called tabulation form
    dp[1] = 1;
    dp[0] = 0;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, 0);
    fib(n, dp);
    for (int i = 0; i <= n; i++)
    {
        cout << dp[i] << " ";
    }

    return 0;
}