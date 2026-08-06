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
void Permute(vector<vector<int>> &ans, vector<int> arr, int index)
{
    if (index == arr.size())
    {
        ans.push_back(arr);
        return;
    }
    for (int i = index; i < arr.size(); i++)
    {
        swap(arr[i], arr[index]);
        Permute(ans, arr, index + 1);
        swap(arr[i], arr[index]);
    }
}
int main()
{
    vector<int> arr = {1, 2, 3};
    vector<vector<int>> ans;
    Permute(ans, arr, 0);
    for (int i = 0; i < ans.size(); i++)
    {
        vector<int> prmut = ans[i];
        for (int &num : prmut)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}