#include <bits/stdc++.h>
using namespace std;
class a
{
public:
};
int solveProb(vector<int> &stat, int index, int time)
{
    int n = stat.size();
    if (index == n)
    {
        return 0;
    }
    int include = stat[index] * (time + 1) + solveProb(stat, index + 1, time + 1);
    int excle = 0 + solveProb(stat, index + 1, time);
    int ans = max(include, excle);
    return ans;
}
int solveMem(vector<int> &stat, int index, int time, vector<vector<int>> &dp)
{
    int n = stat.size();
    if (index == n)
    {
        return 0;
    }
    if (dp[index][time] != -1)
    {
        return dp[index][time];
    }
    int include = stat[index] * (time + 1) + solveProb(stat, index + 1, time + 1);
    int excle = 0 + solveProb(stat, index + 1, time);
    int ans = max(include, excle);
    dp[index][time] = ans;
    return dp[index][time];
}
int solveTab(vector<int> &stat)
{
    // bottom up 
    int n = stat.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int index = n - 1; index >= 0; index--)
    {
        for (int time = index; time >= 0; time--)
        {
            int include = stat[index] * (time + 1) +dp[index+1][time+1];
            int excle = 0 + dp[index+1][time];
            int ans = max(include, excle);
            dp[index][time] = ans;
          
        }
    }
    return dp[0][0];
}
int solveTab2(vector<int> &stat)
{
    int n = stat.size();
    vector<int>curr(n+1,0);
    vector<int>next(n+1,0);
    for (int index = n - 1; index >= 0; index--)
    {
        for (int time = index; time >= 0; time--)
        {
            int include = stat[index] * (time + 1) +next[time+1];
            int excle = 0 + next[time];
            int ans = max(include, excle);
            curr[time]= ans;
          
        }
        next=curr;
    }
    return next[0];
}
int maxStatfiFaction(vector<int> &statifaction)
{
    sort(statifaction.begin(), statifaction.end());
    int ans = 0;
    //  ans = solveProb(statifaction, 0, 0);
    int n = statifaction.size();
    // vector<vector<int>> dp(n + 1, vector<int>(n + 2, -1));
    // ans = solveMem(statifaction, 0, 0, dp);
    ans=solveTab2(statifaction);
    return ans;
}
int main()
{
    // vector<int> dishes = {-1, -8, 0, 5, -9};
    vector<int> dishes = {4, 3, 2};
    cout << maxStatfiFaction(dishes) << endl; // Expected output: 14

    return 0;
}