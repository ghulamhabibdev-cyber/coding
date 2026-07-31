#include <bits/stdc++.h>
using namespace std;
class a
{
public:
};
int solveRec(int index, int diff, int arr[])
{
    if (index < 0)
    {
        return 0;
    }
    int ans = 0;
    for (int j = index - 1; j >= 0; j--)
    {
        if (arr[index] - arr[j] == diff)
        {
            ans = max(ans, 1 + solveRec(j, diff, arr));
        }
    }
    return ans;
    // backward check
}
int solveMem(int index, int diff, int arr[], unordered_map<int, int> dp[])
{

    if (index < 0)
    {
        return 0;
    }
    if (dp[index].count(diff))
    {
        return dp[index][diff];
    }
    int ans = 0;
    for (int j = index - 1; j >= 0; j--)
    {
        if (arr[index] - arr[j] == diff)
        {
            ans = max(ans, 1 + solveMem(j, diff, arr, dp));
        }
    }
    dp[index][diff] = ans;
    return dp[index][diff];
}
int logestArithmaticAP(int arr[], int n)
{
    if (n <= 2)
    {
        return n;
    }
    int ans = 0;
    unordered_map<int, int> dp[n + 1];
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {

            // ans = max(ans, 2 + solveRec(i, arr[j] - arr[i], arr));
            ans = max(ans, 2 + solveMem(i, arr[j] - arr[i], arr, dp));
        }
    }
    return ans;
}
int longestAritmaticAp(int arr[], int n)
{

    if (n <= 2)
    {
        return n;
    }
    int ans = 0;
    unordered_map<int, int> dp[n + 1];
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            int diff=arr[i]-arr[j];
            int cnt=1;
            if(dp[j].count(diff))
            {
                cnt=dp[j][diff];
            }
            dp[i][diff]=1+cnt;
            ans=max(ans,dp[i][diff]);
        }
    }
    return ans;
}
int main()
{
    int arr[] = {1, 7, 10, 15, 27, 29};
    int n = sizeof(arr) / sizeof(arr[0]);
    // cout << "Longest Arithmetic Progression Length = "
    //      << logestArithmaticAP(arr, n) << endl;
         cout << "Longest Arithmetic Progression Length = "
         << longestAritmaticAp(arr, n) << endl;
    return 0;
}