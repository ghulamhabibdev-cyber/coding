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
int maxi = INT_MAX;
int min(int a, int b)
{
    if (a <= b)
    {
        return a;
    }
    return b;
}
int solve(vector<int> &coins, int rem, unordered_map<int, int> memo)
{
    if (rem < 0)
        return -1;
    if (rem == 0)
        return 0;
    if (memo.find(rem) != memo.end())
        return memo[rem];
    int min_count = INT_MAX;

    for (int coin : coins)
    {
        int res = solve(coins, rem - coin, memo);
        if (res >= 0 && res < min_count)
        {
            min_count = 1 + res;
        }
    }
    memo[rem] = (min_count == INT_MAX) ? -1 : min_count;
    return memo[rem];
}
int main()
{
    vector<int> coins = {1, 2, 5};
    int count = 0;
    unordered_map<int, int> dp;
    int ans = solve(coins, 11, dp);
    cout << "ans : " << ans << endl;
    return 0;
}