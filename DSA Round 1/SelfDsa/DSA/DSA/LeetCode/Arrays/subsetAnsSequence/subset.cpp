#include <bits/stdc++.h>
using namespace std;
void solve(vector<int> &num,vector<int>output,int index,vector<vector<int>> &ans)
{
    if(index>=num.size())
    {
        ans.push_back(output);
        return;
    }
    solve(num, output, index+1, ans);
    int element=num[index];
    output.push_back(element);
    solve(num, output, index+1, ans);
}

vector<vector<int>> subset(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;
    solve(nums, output, index, ans);
    return ans;
}
int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
   vector<vector<int> >ans=subset(nums);
   for (const auto& row : ans) {
    for (const auto& col : row) {
        cout << col << " ";
    }
    cout << endl;
}
    return 0;
}