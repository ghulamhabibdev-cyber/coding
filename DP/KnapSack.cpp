#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findMaxKnapsack(vector<int> &value, vector<int> &wt, int i, int n, int cap, vector<vector<int>> &dp)
{
    if (i == n || cap == 0)
    {
        return 0;
    }
    if (dp[i][cap] != -1)
    {
        cout<<"i :cap "<<i<<" : "<<cap<<endl;
        return dp[i][cap];
    }
    if (cap < wt[i])
    {
        return dp[i][cap] = findMaxKnapsack(value, wt, i + 1, n, cap, dp);
    }
    int yes = value[i] + findMaxKnapsack(value, wt, i + 1, n, cap - wt[i], dp);
    int no = findMaxKnapsack(value, wt, i + 1, n, cap, dp);
    cout << "max i :cap " << i << " : " << cap << endl;
    return dp[i][cap] = max(yes, no);
}

int knapSack(vector<int> value, vector<int> wt, int cap)
{
    int n = value.size();
    vector<vector<int>> dp(n, vector<int>(cap + 1, -1));
    return findMaxKnapsack(value, wt, 0, n, cap, dp);
}

int main()
{
    vector<int>value = {10, 20, 30, 40};
    vector<int>wt = {1, 2, 3, 4};
   int W = 5;

    int ans = knapSack(value, wt,W );
    cout << "Maximum Knapsack Value: " << ans << endl;
    return 0;
}
