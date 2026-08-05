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
void permute(vector<vector<int>> &res, vector<int> &temp, vector<int> &arr, vector<bool> &vis)
{
    if (temp.size() >= arr.size())
    {
        res.push_back(temp);
        return;
    }
    for (int i = 0; i < arr.size(); i++)
    {
        if (!vis[i])
        {
            vis[i] = true;
            temp.push_back(arr[i]);

            permute(res, temp, arr, vis);

            temp.pop_back(); 
            vis[i] = false;
        }
    }
}
int main()
{
    int n = 3;
    vector<int> arr = {1, 2, 3};
    vector<vector<int>> res;
    vector<bool> vis(n, 0);
    vector<int> temp;
    permute(res, temp, arr, vis);
    for (int i = 0; i < res.size(); i++)
    {
        cout << "{ ";
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j];
            if (j < res[i].size() - 1)
            {
                cout << ",";
            }
        }
        cout << " }" << endl;
    }
    return 0;
}