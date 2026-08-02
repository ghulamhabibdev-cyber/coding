#include <bits/stdc++.h>
using namespace std;
class a
{
public:
};
// solution by rec;
int solve1(vector<int> &cost, int n)
{
    if (n == 0)
    {
        return cost[0];
    }
    if (n == 1)
    {
        return cost[1];
    }
    int ans = cost[n] + min(solve1(cost, n - 1), solve1(cost, n - 2));
    return ans;
}
// usign memeozation
int solve2(vector<int> &cost, vector<int> &dp, int n)
{
    if (n == 0)
    {
        return cost[0];
    }
    if (n == 1)
    {
        return cost[1];
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    dp[n] = cost[n] + min(solve2(cost, dp, n - 1), solve2(cost, dp, n - 2));
    return dp[n];
}
int tabulaltion(vector<int> &cost)
{
    int prev1 = cost[0];
    int prev2 = cost[1];
    int n = cost.size();
    for (int i = 2; i < n; i++)
    {
        int curr = cost[i] + min(prev1, prev2);
        prev1 = prev2;
        prev2 = curr;
    }
    return min(prev1, prev2);
}
int minCost(vector<int> &cost)
{
    int n = cost.size();
    vector<int> dp(n + 1, -1);
    // int ans=min(solve1(cost,n-1),solve1(cost,n-2));
    // int ans = min(solve2(cost, dp, n - 1), solve2(cost, dp, n - 2));
    int ans = tabulaltion(cost);
    return ans;
}
int solveRecAdj(vector<int> arr, int i)
{
    if (i >= arr.size())
    {
        return 0;
    }
    if (i == arr.size() - 1)
    {
        return arr[i];
    }
    int incl = solveRecAdj(arr, i + 2) + arr[i];
    int excl = solveRecAdj(arr, i + 1) + 0;
    int ans = max(incl, excl);
    return ans;
}
int solveMemAdj(vector<int> arr, vector<int> dp, int i)
{
    if (i >= arr.size())
    {
        return 0;
    }
    if (i == arr.size() - 1)
    {
        return arr[i];
    }
    if (dp[i] != -1)
    {
        return dp[i];
    }
    int incl = solveMemAdj(arr, dp, i + 2) + arr[i];
    int excl = solveMemAdj(arr, dp, i + 1) + 0;
    dp[i] = max(incl, excl);
    return dp[i];
}
int optimizationAdj(vector<int> arr)
{
    int prev1 = 0;
    int prev2 = arr[0];
    int n = arr.size();
    int incl = 0;
    for (int i = 1; i < n; i++)
    {
        int incl = prev1 + arr[i];
        int excl = prev2;
        int ans = max(incl, excl);
        prev1 = prev2;
        prev2 = ans;
    }
    return prev2;
}
int maxSumOfNonAdJ(vector<int> arr)
{

    int i = arr.size();
    int ans = 0;
    vector<int> dp(i, -1);
    // ans = solveRecAdj(arr, 0);

    // ans = solveMemAdj(arr, dp, 0);
    ans = optimizationAdj(arr);

    return ans;
}
// conbination sum problem by using 1dp
int solveRecComb(vector<int> nums, int tar)
{
    if (tar < 0)
    {
        return 0;
    }
    if (tar == 0)
    {
        return 1;
    }
    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        ans += solveRecComb(nums, tar - nums[i]);
    }
    return ans;
}
int solveMemComb(vector<int>&nums,int tar,vector<int>&dp)
{
    if (tar < 0)
    {
        return 0;
    }
    if (tar == 0)
    {
        return 1;
    }
    if(dp[tar]!=-1)
    {
        return dp[tar];
    }
    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        ans += solveRecComb(nums, tar - nums[i]);
    }
    dp[tar]=ans;
    return dp[tar];
}
int solveTab(vector<int>nums,int tar)
{
    vector<int>dp(tar+1,0);
    dp[0]=1;
    for(int i=1;i<=tar;i++)
    {
        for(int j=0;j<nums.size();j++)
        {
            if(i-nums[j]>=0)
            {
                dp[i]+=dp[i-nums[j]];
            }
        }

    }
    return dp[tar];
}
int findWays(vector<int> nums, int tar)
{
    int ans = 0;
    // ans = solveRecComb(nums, tar);
    vector<int>dp(tar+1,-1);
    // ans=solveMemComb(nums,tar,dp);
    ans=solveTab(nums,tar);
    return ans;
}
int solvePerfectSqureProblem(int n)
{
    if (n == 0)
    {
        return 0;
    }
    int ans = n;
    for (int i = 1; i * i <= n; i++)
    {

        ans = min(ans, 1 + solvePerfectSqureProblem(n - i * i));
    }
    return ans;
}
int solvePerfectProByMem(int n,vector<int>&dp)
{
    if(n==0)
    {
        return 0;
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    int ans=n;
    for(int i=1;i*i<=n;i++)
    {
        ans=min(ans,1+solvePerfectProByMem(n-i*i,dp));
    }
    dp[n]=ans;
    return dp[n];
}
int findTotalPerfectSquaresFOrN(int n)
{
    int ans=0;
    // ans=solvePerfectSqureProblem(n);
    vector<int>dp(n+1,-1);
    ans=solvePerfectProByMem(n,dp);
    return ans;
}
int main()
{
    // vector<int> cost = {10, 15, 20, 25, 30};
    // cout << "Min cost to climb stairs: " << minCost(cost) << endl;
    //     vector<int> arr = {10, 30, 5, 90, 7, 100, 20};
    //     cout << "Max sum of non adjacent element  :  " << maxSumOfNonAdJ(arr);

    // vector<int> nums = {1, 2,3};
    // int tar = 4;
    // cout << "Total combination sum of  : " << findWays(nums, tar) << endl;
    int n=5;
    cout<<"Toal perfect squares require to make no :  "<<findTotalPerfectSquaresFOrN(n)<<endl;
    return 0;
}