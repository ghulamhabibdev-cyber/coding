#include <bits/stdc++.h>
using namespace std;
class a
{
public:
};
vector<vector<int>> merge(vector<vector<int>> &arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    vector<int> current = arr[0];
    for (int i = 0; i < n; i++)
    {

        // if (arr[i][0] <= current[1])
        // {
        //     current[1] = max(arr[i][1], current[1]);
        // }
        // else
        // {
        //     ans.push_back(current);
        //     current = arr[i];
        //     // ans[i].push_back(end);
        // }
        if(ans.empty()||arr[i][0]>ans.back()[1])
        {
            ans.push_back(arr[i]);
        }
        else{
            ans.back()[1]=max(arr[i][1],ans.back()[1]);
        }
    }
    // ans.push_back(current);
    // int x = ans.size();
    // vector<vector<int>>final(x, vector<int>(2, 0));
    // for (int i = x - 1; i >= 0; i++)
    // {

    //     int m = arr[i].size();
    //     final[i].push_back(arr[i][m - 2]);
    //     final[i].push_back(arr[i][m - 1]);
    // }
    return ans;
}
int main()
{
    vector<vector<int>> input = {{1, 2}, {2, 6}, {8, 10}, {15, 18}};
    // sort(input.begin(), input.end());
    // for (int i = 0; i < input.size(); i++)
    // {
    //     for (int j = 0; j < 2; j++)
    //     {
    //         cout << input[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    vector<vector<int>> ans = merge(input);
    for (auto a : ans)
    {
        for (int i : a)
        {

            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
