#include <bits/stdc++.h>
using namespace std;
class a
{
public:
};
int solveRec(vector<int> &arr, int index)
{
    if (index < 0)
    {
        return 0;
    }
    if (index == 0)
    {
        return arr[0];
    }

    int incl = solveRec(arr, index - 2) + arr[index];
    int excl = solveRec(arr, index - 1) + 0;
    return max(incl, excl);
}
int solveMem(vector<int> &arr, vector<int> &dp, int index)
{
    if (index < 0)
    {
        return 0;
    }
    if (index == 0)
    {
        return arr[0];
    }
    if (dp[index] != -1)
    {
        return dp[index];
    }
    int incl = solveRec(arr, index - 2) + arr[index];
    int excl = solveRec(arr, index - 1) + 0;
    dp[index] = max(incl, excl);
    return dp[index];
}
int solveTab(vector<int> arr)
{
    int n = arr.size();
    vector<int> dp(n, 0);
    dp[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        int incle = arr[i];
        if (i > 1)
        {
            incle += dp[i - 2];
        
        }
        int excl = dp[i - 1] + 0;
        dp[i] = max(incle, excl);
    }

    return dp[n - 1];
}
int optimization(vector<int>arr)
{
    int n=arr.size();
    int prev2=0;
    int prev1=arr[0];
    int ans=0;
    for(int i=1;i<n;i++)
    {
        int incl=prev2+arr[i];
        int excl=prev1+0;
         ans=max(incl,excl);
        prev2=prev1;
        prev1=ans;
    }
    return ans;
}
int maximumSumOfNonAdjacent(vector<int> arr)
{
    int index = arr.size();
    int ans;
    // ans=solveRec(arr,index-1);
    vector<int> dp(index, -1);
    // ans=solveMem(arr, dp, index - 1);
    // ans = solveTab(arr);
    ans=optimization(arr);
    return ans;
}
int main()
{
    vector<int> arr = {50, 2,100, 3,20};
    cout << "Maximum Sum of Non-Adjacent Elements = "
         << maximumSumOfNonAdjacent(arr) << endl;
    return 0;
}