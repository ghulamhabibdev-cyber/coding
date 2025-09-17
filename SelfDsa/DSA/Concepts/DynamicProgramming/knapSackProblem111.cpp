#include <bits/stdc++.h>
using namespace std;
class a
{
public:
};
int solveRec(vector<int> wt, vector<int> value, int i, int w)
{

    if (i == 0)
    {
        if (wt[0] <= w)
        {
            return value[0];
        }
        return 0;
    }
    int incl = 0;
    if (wt[i] <= w)
    {
        incl = value[i] + solveRec(wt, value, i - 1, w - wt[i]);
    }
    int excl = 0 + solveRec(wt, value, i - 1, w);
    int ans = max(incl, excl);
    return ans;
}
int solveMem(vector<int> wt, vector<int> value, int i, int w, vector<vector<int>> dp)
{

    if (i == 0)
    {
        if (wt[0] <= w)
        {
            return value[0];
        }
        return 0;
    }
    if (dp[i][w] != -1)
    {
        return dp[i][w];
    }
    int incl = 0;
    if (wt[i] <= w)
    {
        incl = value[i] + solveMem(wt, value, i - 1, w - wt[i], dp);
    }
    int excl = 0 + solveMem(wt, value, i - 1, w, dp);
    dp[i][w] = max(incl, excl);
    return dp[i][w];
}
int solveTab(vector<int> wt, vector<int> value, int n, int w)
{
    vector<vector<int>> dp(n, vector<int>(w + 1, 0));

    // base case: first row
    for (int i = wt[0]; i <= w; i++)
    {
        dp[0][i] = value[0];
    }

    // fill the dp table
    for (int index = 1; index < n; index++)
    {
        for (int i = 0; i <= w; i++)
        {
            int incl = 0;
            if (wt[index] <= i)
            {
                incl = value[index] + dp[index - 1][i - wt[index]];
            }
            int excl = dp[index - 1][i];
            dp[index][i] = max(incl, excl);
        }
    }

    return dp[n - 1][w];
}
int solveOpt(vector<int> wt, vector<int> value, int n, int w)
{
    // vector<vector<int>> dp(n, vector<int>(w + 1, 0));
    vector<int> prev(w + 1, 0);
    vector<int> curr(w + 1, 0);

    // base case: first row
    for (int i = wt[0]; i <= w; i++)
    {
       if (wt[0] <= w)
        {
            prev[i]= value[0];
        }else{
            prev[i]=0;
        }
    }

    // fill the dp table
    for (int index = 1; index < n; index++)
    {
        for (int i = 0; i <= w; i++)
        {
            int incl = 0;
            if (wt[index] <= i)
            {
                incl = value[index] + prev[i - wt[index]];
            }
            int excl = prev[i];
            curr[i] = max(incl, excl);
        }
        prev=curr;
    }

    return prev[w];
}
int knapSacck(vector<int> weight, vector<int> value, int n, int w)
{
    int ans = 0;
    vector<vector<int>> dp(n, vector<int>(w + 1, -1));
     ans= solveRec(weight, value, n-1, w);
    // ans = solveMem(weight, value, n - 1, w, dp);
    // ans = solveTab(weight, value, n, w);
    // ans=solveOpt(weight,value,n,w);
    return ans;
}
int main()
{
    vector<int> wt = {10, 10, 6, 5};
    vector<int> val = {50, 40, 80, 60};
    int W = 20;
    int n = wt.size();

    cout << "Maximum value in Knapsack = " << knapSacck(wt, val, n, W);
    return 0;
}