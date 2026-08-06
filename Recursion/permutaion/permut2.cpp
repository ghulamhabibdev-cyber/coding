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
void permute(vector<vector<int>> &ans, vector<int> &arr, int index)
{
    if (index == arr.size())
    {
        ans.push_back(arr);
        return;
    }
    vector<bool> use(21, 0);

    for (int i = index; i < arr.size(); i++)
    {
        if (use[arr[i] + 10] == 0)
        {
            swap(arr[i], arr[index]);
            permute(ans, arr, index + 1);
            swap(arr[i], arr[index]);
            use[arr[i] + 10] = 1;
        }
    }
}
int main()
{
    vector<int> arr = {1, 2, 1, 2};
    vector<vector<int>> ans;
    permute(ans, arr, 0);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}