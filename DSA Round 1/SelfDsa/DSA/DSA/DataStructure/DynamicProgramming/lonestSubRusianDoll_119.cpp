#include <bits/stdc++.h>
using namespace std;
class a
{
public:
};
int solveRec(int n, int a[], int curr, int prev)
{
    if (curr == n)
    {
        return 0;
    }
    int take = 0;
    if (prev == -1 || a[curr] > a[prev])
    {
        take = 1 + solveRec(n, a, curr + 1, curr);
    }
    int notTake = solveRec(n, a, curr + 1, prev);
    int ans = max(take, notTake);
    return ans;
}
int solveMem(int n, int a[], int curr, int prev, vector<vector<int>> &dp)
{
    if (curr == n)
    {
        return 0;
    }
    if (dp[curr][prev + 1] != -1)
    {
        return dp[curr][prev + 1];
    }
    int take = 0;
    if (prev == -1 || a[curr] > a[prev])
    {
        take = 1 + solveMem(n, a, curr + 1, curr, dp);
    }
    int notTake = solveMem(n, a, curr + 1, prev, dp);
    int ans = max(take, notTake);
    dp[curr][prev + 1] = ans;
    return dp[curr][prev + 1];
}
int solveTab(int n, int a[])
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int curr = n - 1; curr >= 0; curr--)
    {
        for (int prev = curr - 1; prev >= -1; prev--)
        {
            int take = 0;
            if (prev == -1 || a[curr] > a[prev])
            {
                take = 1 + dp[curr + 1][curr + 1];
            }
            int notTake = 0 + dp[curr + 1][prev + 1];
            int ans = max(take, notTake);
            dp[curr][prev + 1] = ans;
        }
    }
    return dp[0][-1 + 1];
}
int solveOpt_1(int n, int a[])
{
    // vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    vector<int>currRow(n+1,0);
    vector<int>next(n+1,0);

    for (int curr = n - 1; curr >= 0; curr--)
    {
        for (int prev = curr - 1; prev >= -1; prev--)
        {
            int take = 0;
            if (prev == -1 || a[curr] > a[prev])
            {
                take = 1 + next[curr + 1];
            }
            int notTake = 0 + next[prev + 1];
            int ans = max(take, notTake);
            currRow[prev+1] = ans;
        }
        next=currRow;
    }
    return next[0];
}
int solveOptimal(int n,int a[])
{
    if(n==0)
    {
        return 0;
    }
    vector<int>ans;
    ans.push_back(a[0]);
    for(int i=1;i<n;i++)
    {
        if(a[i]>ans.back())
        {
            ans.push_back(a[i]);
        }
        else{
            int index=lower_bound(ans.begin(),ans.end(), a[i]) - ans.begin();
            ans[index]=a[i];
        }
    }
    return ans.size();
}
int longestSubsequence(int n, int a[])
{
    int ans = 0;
    // ans= solveRec(n, a, 0, -1);
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    // ans = solveMem(n, a, 0, -1, dp);
    // ans = solveTab(n, a);
    // ans=solveOpt_1(n,a);
    ans=solveOptimal(n,a);
    return ans;
}
int main()
{
    
    int arr[] = {10, 22, 9, 33, 21, 50, 41, 60};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Length of LIS: " << longestSubsequence(n, arr) << endl;
    return 0;
}