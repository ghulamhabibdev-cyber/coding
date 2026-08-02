#include <bits/stdc++.h>
using namespace std;
class a
{
public:
};
int solveRec(vector<int> coin, int x)
{
    if (x == 0)
    {
        return 0;
    }
    if (x < 0)
    {
        return INT_MAX;
    }
    int mini = INT_MAX;
    for (int i = 0; i < coin.size(); i++)
    {
        int ans = solveRec(coin, x - coin[i]);
        if (ans != INT_MAX)
        {
            mini = min(mini, 1 + ans);
        }
    }
    return mini;
}
int solveMem(vector<int> coin, vector<int> &dp, int x)
{
    if (x == 0)
    {
        return 0;
    }
    if (x < 0)
    {
        return INT_MAX;
    }
    if (dp[x] != -1)
    {
        return dp[x];
    }
    int mini = INT_MAX;
    for (int i = 0; i < coin.size(); i++)
    {
        int ans = solveMem(coin, dp, x - coin[i]);
        if (ans != INT_MAX)
        {
            mini = min(1 + ans, mini);
        }
    }
    dp[x] = mini;
    return mini;
}
int solveTab(vector<int>&coin,int x)
{
    vector<int>dp(x+1,INT_MAX);
    dp[0]=0;
    for(int i=1;i<=x;i++)
    {
        for(int j=0;j<coin.size();j++)
        {
            if(i-coin[j]>=0&&(dp[i-coin[j]]!=INT_MAX))
            {
                dp[i]=min(dp[i],1+dp[i-coin[j]]);
            }
        }
    }
    return dp[x];
}
int minicoin(vector<int> &coin, int x)
{
    // int ans = solveRec(coin, x);
    int n = coin.size();
    vector<int> dp(x + 1, -1);

    // int ans = solveMem(coin, dp, x);
    int ans=solveTab(coin,x);
    if (ans == INT_MAX)
    {
        return -1;
    }
    return ans;
}
int main()
{
    vector<int> coins = {1, 3, 4};
    int target = 6;
    cout << minicoin(coins, target);
    return 0;
}