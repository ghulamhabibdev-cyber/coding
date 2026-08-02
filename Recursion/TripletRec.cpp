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
void helper(vector<vector<int>> &ans, vector<int> nums, vector<int> &curr, int index)
{
    if (index >= nums.size())
    {
        ans.push_back(curr);
        return;
    }
    if (curr.size() == 3)
    {
        ans.push_back(curr);
        return;
    }
    curr.push_back(nums[index]);
    helper(ans, nums, curr, index + 1);
    curr.pop_back();
    helper(ans, nums, curr, index + 1);
    return;
}
void findAllTriplets(vector<vector<int>> &ans, vector<int> nums)
{
    vector<int> curr;
    int index = 0;
    helper(ans, nums, curr, 0);
}
int main()
{
    vector<vector<int>> ans;
    vector<int> nums = {5, 4, 2, 3,  1};
    findAllTriplets(ans, nums);
    cout << "Posible : <<<" << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
    {

        if (ans[i].size() == 3)
        {
            cout << "[";
            for (int j = 0; j < 3; j++)
            {
                cout << ans[i][j];
            }
            cout << "]" << endl;
        }
    }
    return 0;
}