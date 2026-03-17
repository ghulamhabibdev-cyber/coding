#include <bits/stdc++.h>
using namespace std;
class a
{
public:
};
long long solveRec(int dice, int faces, int target)
{
    if (target < 0)
    {
        return 0;
    }
    if (dice == 0 && target != 0)
    {
        return 0;
    }
    if (target == 0 && dice != 0)
    {
        return 0;
    }
    if (dice == 0 && target == 0)
    {
        return 1;
    }

    long long ans = 0;
    for (int i = 1; i <= faces; i++)
    {
        ans += solveRec(dice - 1, faces, target - i);
    }
    return ans;
}
long long solveMem(int dice, int faces, int target, vector<vector<int>> &dp)
{
    if (target < 0)
    {
        return 0;
    }
    if (dice == 0 && target != 0)
    {
        return 0;
    }
    if (target == 0 && dice != 0)
    {
        return 0;
    }
    if (dice == 0 && target == 0)
    {
        return 1;
    }
    if (dp[dice][target] != -1)
    {
        return dp[dice][target];
    }
    long long ans = 0;
    for (int i = 1; i <= faces; i++)
    {
        ans += solveMem(dice - 1, faces, target - i, dp);
    }
    dp[dice][target] = ans;
    return dp[dice][target];
}
long long solveTab(int d, int f, int t)
{
    vector<vector<long long>> dp(d + 1, vector<long long>(t + 1, 0));
    dp[0][0] = 1;
    for (int dice = 1; dice <= d; dice++)
    {
        for (int target = 1; target <= t; target++)
        {
            long long ans = 0;
            for (int i = 1; i <= f; i++)
            {
                if (target - i >= 0) 
                ans += dp[dice - 1][target - i];
            }
            dp[dice][target] = ans;
        }
    }
    return dp[d][t];
}
long long noOfWays(int n, int m, int x)
{
    long long ans = 0;
    // ans = solveRec(n, m, x);
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, -1));
    // ans = solveMem(n, m, x, dp);
    ans=solveTab(n,m,x);
    return ans;
}
int main()
{
    int n = 2;                         // dice
    int m = 6;                         // faces
    int x = 7;                         // target sum
    cout << noOfWays(n, m, x) << endl; // Expected output: 6
    return 0;
}