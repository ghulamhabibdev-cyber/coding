#include <bits/stdc++.h>
using namespace std;
class a
{
public:
};
int solveRec(int index, int arr[], int n, int target)
{
    if (index >= n)
    {
        return 0;
    }
    if (target < 0)
    {
        return 0;
    }
    if (target == 0)
    {
        return 1;
    }
    int incl = solveRec(index + 1, arr, n, target - arr[index]);
    int excl = solveRec(index + 1, arr, n, target - 0);
    int ans = incl || excl;
    return ans;
}
int solveMem(int index, int arr[], int n, int target, vector<vector<int>> &dp)
{

    if (index >= n)
    {
        return 0;
    }
    if (target < 0)
    {
        return 0;
    }
    if (target == 0)
    {
        return 1;
    }
    if (dp[index][target] != -1)
    {
        return dp[index][target];
    }
    int incl = solveRec(index + 1, arr, n, target - arr[index]);
    int excl = solveRec(index + 1, arr, n, target - 0);
    dp[index][target] = incl || excl;
    return dp[index][target];
}
int solveTab(int arr[], int n, int total)
{
    vector<vector<int>> dp(n + 1, vector<int>(total + 1, 0));
    for (int i = 0; i <=n; i++)
    {
        dp[i][0] = 1;
    }
    for (int index = n-1; index >= 0; index--)
    {
        for (int target = 0; target <= total / 2; target++)
        {
            int incl =0;
            if (target - arr[index] >= 0)
            {
                 incl = dp[index + 1][target - arr[index]];
            }
            int excl = dp[index + 1][target ];
            dp[index][target] = incl || excl;
        }
    }
    return dp[0][total/2];
}
int solveOp(int arr[], int n, int total)
{
    vector<int>curr(total+1,0);
    vector<int>next(total+1,0);
    curr[0]=1;
    next[0]=1;
    for (int index = n-1; index >= 0; index--)
    {
        for (int target = 0; target <= total / 2; target++)
        {
            int incl =0;
            if (target - arr[index] >= 0)
            {
                 incl = next[target - arr[index]];
            }
            int excl = next[target ];
            curr[target] = incl || excl;
        }
        next=curr;
    }
    return next[total/2];


}

int equalPartion(int n, int arr[])
{
    int ans = 0;
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        total += arr[i];
    }
    if (total & 1)
    {
        return 0;
    }
    int target = total / 2;
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));

    // ans = solveRec(0, arr, n, target);
    // ans = solveMem(0, arr, n, target, dp);
    // ans=solveTab(arr,n,total);
    ans=solveOp(arr,n,total);
    return ans;
}
int main()
{
    int arr[] = {1, 5, 11, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    if (equalPartion(n, arr))
        cout << "Can be partitioned into equal subsets\n";
    else
        cout << "Cannot be partitioned into equal subsets\n";

    return 0;
}