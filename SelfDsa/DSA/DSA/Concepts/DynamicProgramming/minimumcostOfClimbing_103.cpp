#include <bits/stdc++.h>
using namespace std;
class a
{
public:
};
int solve(long long stairs, int i)
{
    if (stairs == i)
    {
        return 1;
    }
    if (i > stairs)
    {
        return 0;
    }
    return (solve(stairs, i + 1) + solve(stairs, i + 2));
}
int countNoWayToCliimb(long long stair)
{
    int ans = solve(stair, 0);
    return ans;
}
int Minsolve(vector<int> &cost, int n,vector<int>&dp)
{
    if (n == 0)
    {
        return cost[0];
    }
    if (n == 1)
    {
        return cost[1];
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    // int ans = cost[n] + min(Minsolve(cost, n - 1), Minsolve(cost, n - 2));
    dp[n]=cost[n]+ min(Minsolve(cost, n - 1,dp), Minsolve(cost, n - 2,dp));
    return dp[n];
}
int minCost(vector<int> &cost)
{
    int n = cost.size();
    vector<int>dp(n+1,-1);
    // int ans = min(Minsolve(cost, n - 1), Minsolve(cost, n - 2));
     int ans = min(Minsolve(cost, n - 1,dp), Minsolve(cost, n - 2,dp));
    return ans;
}
//tabulation method
int tabMinCost(vector<int> &cost)
{
   
    int n=cost.size();
     vector<int>dp(n+1);
    dp[0]=cost[0];
    dp[1]=cost[1];
    for(int i=2;i<n;i++)
    {
        dp[i]=cost[i]+min(dp[i-2],dp[i-1]);
    }
    return min(dp[n-1],dp[n-2]);
}
int tabMinCostOp(vector<int> &cost)
{ 
    int n=cost.size();   
    int prev1=cost[0];
    int prev2=cost[1];
    for(int i=2;i<n;i++)
    {
        int curr=cost[i]+min(prev1,prev2);
        prev1=prev2;
        prev2=curr;
    }
    return min(prev1,prev2);
}
int main()
{
    // cout << "Toal way to climb : " << countNoWayToCliimb(8);
    // cout << "Total ways to climb 8 stairs: " << countNoWayToClimb(8) << endl;

    vector<int> cost = {10, 15, 20,25,30};
    cout << "Min cost to climb stairs: " << minCost(cost) << endl;
    cout<<"MIn cost : " << tabMinCost(cost)<<endl;;
    cout<<"MIn cost : " << tabMinCostOp(cost)<<endl;
    return 0;
}