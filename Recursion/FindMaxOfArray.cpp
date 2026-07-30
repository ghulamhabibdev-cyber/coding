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
int maxOfArray(vector<int> arr, int maxi, int index)
{
    if (index >= arr.size())
    {
        return INT_MIN;
    }
    int ans = maxOfArray(arr, maxi, index + 1);
    return max(ans, arr[index]);
}
int minOfArray(vector<int> arr, int mini, int index)
{
    if (index >= arr.size())
    {
        return INT_MAX;
    }
    int ans = minOfArray(arr, mini, index + 1);
    return min(ans, arr[index]);
}
int main()
{
    vector<int> arr = {-10001, 23, 34, 43, 300, 33, 10001};
    int ans = maxOfArray(arr, arr[0], 0);
    int minAns = minOfArray(arr, arr[0], 0);
    cout << "Min Ans : " << minAns << endl;
    cout << "Max ans  : " << ans << endl;
    return 0;
}