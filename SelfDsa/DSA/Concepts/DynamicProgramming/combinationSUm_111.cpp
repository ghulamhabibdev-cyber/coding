#include <bits/stdc++.h>
using namespace std;
class a
{
public:
};
int solveRec(vector<int> &nums, int tar)
{
    // base case
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
        ans += solveRec(nums, tar - nums[i]);
    }
    return ans;
}
int solveMem(vector<int> &nums, int tar, vector<int> &dp)
{
    // base case
    if (tar < 0)
    {
        return 0;
    }
    if (tar == 0)
    {
        return 1;
    }
    if (dp[tar] != -1)
    {
        return dp[tar];
    }
    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        ans += solveRec(nums, tar - nums[i]);
    }
    dp[tar] = ans;
    return dp[tar];
}
int solveTab(vector<int> &nums, int tar)
{
    // base case
    vector<int> dp(tar + 1, 0);
    dp[0] = 1;
    int ans = 0;
    for (int i = 1; i <= tar; i++)
    {
        for (int j = 0; j < nums.size(); j++)
        {
            if (i - nums[j] >= 0)
            {
                dp[i] += dp[i - nums[j]];
            }
        }
        // ans+=solveRec(nums,tar-nums[i]);
        // }
        // dp[tar]=ans;
    }
    return dp[tar];
}
int findWay(vector<int> nums, int tar)
{
    int ans = 0;
    // ans=solveRec(nums,tar);
    vector<int> dp(tar + 1, -1);
    //    ans= solveMem(nums,tar,dp);
    ans = solveTab(nums, tar);
    return ans;
}
int main()
{
    vector<int> nums = {1, 2,3};
    int tar = 4;
    cout << "Total ways are : " << findWay(nums, tar);
    return 0;
}