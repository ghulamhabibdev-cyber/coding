#include <bits/stdc++.h>
using namespace std;
class a
{
public:
};
int solveRec(int n)
{
    if (n == 0)
    {
        return 0;
    }
    int ans = n;
    for (int i = 1; i * i <= n; i++)
    {

        ans = min(ans, 1 + solveRec(n - i * i));
    }

    return ans;
}
int solveMem(int n, vector<int> &dp)
{
    if (n == 0)
    {
        return 0;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    int ans = n;
    for (int i = 1; i * i <= n; i++)
    {

        ans = min(ans, 1 + solveRec(n - i * i));
    }
    dp[n] = ans;

    return dp[n];
}
int solveTab(int n)
{
    vector<int> dp(n + 1, INT_MAX);
    int ans = n;
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {

        for (int j = 1; j * j <= n; j++)
        {
            int temp = j * j;
            if (i - temp >= 0)
            {
                dp[i] = min(dp[i], 1 + dp[i - temp]);
            }
        }
    }

    return dp[n];
}
int perfectSquaresProblem(int n)
{
    int ans = 0;
       ans= solveRec(n);
    // vector<int> dp(n + 1, -1);
    // // ans = solveMem(n, dp);
    // ans = solveTab(n);
    return ans;
}
int main()
{
    int n = 100;
    cout << "Total perfect squre : " << perfectSquaresProblem(n) << endl;
    return 0;
}