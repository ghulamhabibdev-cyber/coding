class Solution
{
public:
    int maxHouseRober(vector<int> &arr, int index, int curr, int &maxi,
                      unordered_map<int, int> &dp)
    {
        if (index >= arr.size())
        {
            maxi = max(curr, maxi);
            return 0;
        }
        if (dp.find(index) != dp.end())
        {
            return dp[index];
        }
        int ans = arr[index] + maxHouseRober(arr, index + 2, curr, maxi, dp);
        int ans2 = maxHouseRober(arr, index + 1, curr, maxi, dp);
        maxi = max(ans, ans2);
        dp[index] = maxi;
        return maxi;
    }
    int rob(vector<int> &nums)
    {
        int ans = 0;
        unordered_map<int, int> dp;
        maxHouseRober(nums, 0, 0, ans, dp);
        return ans;
    }
};