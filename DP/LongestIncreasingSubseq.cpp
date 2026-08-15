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
void findLongesIncreaseing(vector<vector<int>> &ans, vector<int> &curr, vector<int> &arr, int index, int n, int prev)
{
    if (index == n)
    {
        if (ans.empty() || curr.size() > ans[0].size())
        {
            ans.clear();
            ans.push_back(curr);
        }

        return;
    }
    if (curr.empty() || arr[index] > prev)
    {
        curr.push_back(arr[index]);
        findLongesIncreaseing(ans, curr, arr, index + 1, n, arr[index]);
        curr.pop_back();
    }
    findLongesIncreaseing(ans, curr, arr, index + 1, n, prev);
}

int LIS(vector<int> &arr)
{
    int n = arr.size();
    vector<int> res(n);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        res[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
            {
                res[i] = max(res[i], res[j] + 1);
                ans = max(ans, res[i]);
            }
        }
        }
    return ans;
}

int main()
{
    vector<vector<int>> res;
    vector<int> curr;
    vector<int> arr = {10, 9, 2, 1, 0, 7, 7, 101, 19};
    int n = arr.size();
    findLongesIncreaseing(res, curr, arr, 1, n, arr[0]);
    vector<int> ans = res[0];
    for (int num : ans)
    {
        cout << num << " ";
    }
    cout << endl;
    int len = LIS(arr);
    cout << "Lenth : " << len << endl;
    return 0;
}