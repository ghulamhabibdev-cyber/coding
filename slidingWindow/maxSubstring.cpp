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
int maxSubarrayLength(vector<int> arr, int k)
{
    int n = arr.size();
    unordered_map<int, int> counter;
    int res = 0;
    int low = 0;
    for (int high = 0; high < n; high++)
    {
        counter[arr[high]]++;
        while (counter[arr[high]] > k)
        {
            counter[arr[low]]--;
            low++;
        }
        res = max(res, high - low + 1);
    }
    return res;
}
int main()
{
    vector<vector<int>> testCases = {
        {1, 2, 3, 1, 2, 3, 1, 2}, {1, 2, 1, 2, 1, 2, 1, 2}, {5, 5, 5, 5, 5, 5, 5}, {2, 2, 3}, {1, 2, 2, 1, 3}};
    vector<int> kays = {2, 1, 4, 1, 1};

    vector<int> res;
    for (int i = 0; i < testCases.size(); i++)
    {
        vector<int> arr = testCases[i];
        int k = kays[i];
        int ans = maxSubarrayLength(arr, k);
        cout << "New " << endl;
        res.push_back(ans);
    }
    for (int i = 0; i < testCases.size(); i++)
    {
        vector<int> arr = testCases[i];
        cout << "[ ";
        for (int num : arr)
        {
            cout << num << " , ";
        }
        cout << " ]" << " max Subarray : " << res[i] << endl;
    }
}