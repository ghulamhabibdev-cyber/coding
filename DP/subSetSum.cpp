#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits>
#include <list>
using namespace std;

class A
{
};
bool found(vector<int> &arr, int n, int i, int sum, vector<vector<int>> &dp)
{
    if (i == n)
    {
        if (sum == 0)
        {
            return true;
        }
        return false;
    }
    if (i == n || sum < 0)
    {
        return false;
    }

    if (dp[i][sum] != -1)
    {
        return dp[i][sum];
    }
    bool yes = found(arr, n, i + 1, sum - arr[i], dp);
    bool no = found(arr, n, i + 1, sum, dp);
    return dp[i][sum] = yes || no;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = arr.size();
    int sum = 5;
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
    bool ans = found(arr, n, 0, sum, dp);
    if (ans)
    {
        cout << "Found " << endl;
    }
    else
    {
        cout << "Not Found " << endl;
    }
    return 0;
}