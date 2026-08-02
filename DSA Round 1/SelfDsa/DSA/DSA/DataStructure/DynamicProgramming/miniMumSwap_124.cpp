#include <bits/stdc++.h>
using namespace std;
class a
{
public:
};
int solveRec(vector<int> num1, vector<int> num2, int index, bool swaped)
{
    if (index == num1.size())
    {
        return 0;
    }
    int ans = INT_MAX;
    int prev1 = num1[index - 1];
    int prev2 = num2[index - 1];
    if (swaped)
    {
        swap(prev1, prev2);
    }
    if (num1[index] > prev1 && num2[index] > prev2)
    {
        ans = solveRec(num1, num2, index + 1, 0);
    }
    if (num1[index] > prev2 && num2[index] > prev1)
    {
        ans = min(ans, 1 + solveRec(num1, num2, index + 1, 1));
    }
    return ans;
}
int solveMem(vector<int> num1, vector<int> num2, int index, bool swaped, vector<vector<int>> &dp)
{
    if (index == num1.size())
    {
        return 0;
    }
    if (dp[index][swaped] != -1)
    {
        return dp[index][swaped];
    }
    int ans = INT_MAX;
    int prev1 = num1[index - 1];
    int prev2 = num2[index - 1];
    if (swaped)
    {
        swap(prev1, prev2);
    }
    if (num1[index] > prev1 && num2[index] > prev2)
    {
        ans = solveRec(num1, num2, index + 1, 0);
    }
    if (num1[index] > prev2 && num2[index] > prev1)
    {
        ans = min(ans, 1 + solveRec(num1, num2, index + 1, 1));
    }
    dp[index][swaped] = ans;
    return dp[index][swaped];
}
int solveTab(vector<int> num1, vector<int> num2)
{
    int n = num1.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    // dp[n-1][0] = 0; // No swap at last index
    // dp[n-1][1] = 1;
    for (int index = n - 1; index >= 1; index--)
    {
        for (int swaped = 1; swaped >= 0; swaped--)
        {
            int ans = INT_MAX;
            int prev1 = num1[index - 1];
            int prev2 = num2[index - 1];
            if (swaped)
            {
                swap(prev1, prev2);
            }
            if (num1[index] > prev1 && num2[index] > prev2)
            {
                ans = dp[index + 1][0];
            }
            if (num1[index] > prev2 && num2[index] > prev1)
            {
                ans = min(ans, 1 + dp[index + 1][1]);
            }
            dp[index][swaped] = ans;
        }
    }
    return dp[1][0];
}
int solveOp(vector<int> num1, vector<int> num2)
{
    
    int n = num1.size();
    // vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    // dp[n-1][0] = 0; // No swap at last index
    // dp[n-1][1] = 1;
    int swapy=0;
    int noswap=0;
    int currSwap=0;
    int currNoswap=0;

    for (int index = n - 1; index >= 1; index--)
    {
        for (int swaped = 1; swaped >= 0; swaped--)
        {
            int ans = INT_MAX;
            int prev1 = num1[index - 1];
            int prev2 = num2[index - 1];
            if (swaped)
            {
                swap(prev1, prev2);
            }
            if (num1[index] > prev1 && num2[index] > prev2)
            {
                ans =noswap;
            }
            if (num1[index] > prev2 && num2[index] > prev1)
            {
                ans = min(ans,1+swapy);
            }
            if(swaped)
            {
                currSwap=ans;
            }
            else{
                currNoswap=ans;
            }
        }
        swapy=currSwap;
        noswap=currNoswap;
    }
    return min(swapy,noswap);
}
int minSwap(vector<int> num1, vector<int> num2)
{
    num1.insert(num1.begin(), -1);
    int n = num1.size();
    num2.insert(num2.begin(), -1);
    int ans = 0;
    bool swaped = 0; // it is  pass that prev two index are not swaped or swaped
    // ans = solveRec(num1, num2, 1, swaped);
    vector<vector<int>> dp(n, vector<int>(2, -1));
    // ans = solveMem(num1, num2, 1, swaped, dp);
    ans = solveTab(num1, num2);
    return ans;
}
int main()
{
    vector<int> A = {1, 3, 5, 4};
    vector<int> B = {1, 2, 3, 7};
    cout << minSwap(A, B) << endl; // Expected output = 1
    return 0;
}