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
void printSubset(vector<int> &arr, vector<int> ar, vector<vector<int>> &ans, int i)
{
    if (i == arr.size())
    {
        ans.push_back(ar);
        return;
    }
    ar.push_back(arr[i]);
    printSubset(arr, ar, ans, i + 1);
    ar.pop_back();
    printSubset(arr, ar, ans, i + 1);
}
int main()
{
    vector<int> arr = {1, 2, 3};
    vector<vector<int>> ans;
    vector<int> ar;
    printSubset(arr, ar, ans, 0);
    for (auto v : ans)
    {
        for (auto x : v)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}