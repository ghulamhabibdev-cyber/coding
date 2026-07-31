#include <bits/stdc++.h>
using namespace std;
class a
{
public:
};
int solveRob(vector<int> arr, int n)
{
    if (n == 0)
    {
        return arr[0];
    }
    if (n < 0)
    {
        return 0;
    }
    int incl = solveRob(arr, n - 2) + arr[n];
    int excl = solveRob(arr, n - 1) + 0;
    int ans = max(incl, excl);
    return ans;
}
int optimization(vector<int> arr)
{
    int n = arr.size();
    int prev1 = 0;
    int prev2 = arr[0];
    for (int i = 1; i < n; i++)
    {
        int incl = prev1 + arr[i];
        int excl = prev2;
        int ans = max(incl, excl);
        prev1 = prev2;
        prev2 = ans;
    }
    return prev2;
}
int houseRob(vector<int> arr)
{
    int n = arr.size();
    vector<int> first, second;
    for (int i = 0; i < n; i++)
    {
        if (i < n - 1)
        {
            first.push_back(arr[i]);
        }
        if (i != 0)
        {
            second.push_back(arr[i]);
        }
    }
    int i = first.size();
    int j = second.size();
    int ans = 0;
    //  ans = max((solveRob(first, i - 1)), (solveRob(second, j - 1)));
    ans = max(optimization(first), optimization(second));

    return ans;
}
int main()
{

    vector<int> houses = {2, 3, 2, 4};
    cout << "Max money robbed = " << houseRob(houses) << endl;
    return 0;
}