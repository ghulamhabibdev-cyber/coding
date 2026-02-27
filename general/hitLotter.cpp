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
void solution(long int amount, int &count, vector<int> &dp, int i)
{
    if (amount == 0 || i == dp.size())
    {
        return;
    }
    if (dp[i] <= amount)
    {
        amount = amount - dp[i];
        count++;
    }
    else
    {
        i++;
    }
    // cout << dp[i] << endl;
    solution(amount, count, dp, i);
}
int hitLotery(long int amount)
{
    int count = 0;
    vector<int> dp;
    dp.push_back(100);
    dp.push_back(20);
    dp.push_back(10);
    dp.push_back(5);
    dp.push_back(1);
    solution(amount, count, dp, 0);
    return count;
}
int main()
{
    long int n;
    cin >> n;
    int count = hitLotery(n);
    cout << count << endl;
    return 0;
}