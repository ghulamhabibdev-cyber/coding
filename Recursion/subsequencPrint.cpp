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
void helper(vector<int> &arr, vector<vector<int>> &ans, vector<int> &curr, int index)
{
    if (index >= arr.size())
    {
        ans.push_back(curr);
        return;
    }
    helper(arr, ans, curr, index + 1);
    curr.push_back(arr[index]);
    helper(arr, ans, curr, index + 1);
    curr.pop_back();
}
void printSubsequce(vector<int> &arr)
{
    vector<vector<int>> res;
    vector<int> curr;
    int index = 0;
    helper(arr, res, curr, index);
    cout << "total : " << res.size() << endl;
    for (int i = 0; i < res.size(); i++)
    {
        vector<int> sub = res[i];
        for (int num : sub)
        {
            cout << num << " ";
        }
        cout << endl;
    }
}
int main()
{
    vector<int> arr = {1, 2, 3};
    printSubsequce(arr);

    return 0;
}