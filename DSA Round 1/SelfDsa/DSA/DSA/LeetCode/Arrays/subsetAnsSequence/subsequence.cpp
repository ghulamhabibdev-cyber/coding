#include <bits/stdc++.h>
using namespace std;
void solve(string &num, string output, int index, vector<string> &ans)
{
    if (index >= num.size())
    {
        if (output.length() > 0)
        {
            ans.push_back(output);
        }
        return;
    }
    solve(num, output, index + 1, ans);
    int element = num[index];
    output.push_back(element);
    solve(num, output, index + 1, ans);
}

vector<string> subset(string &nums)
{
    vector<string> ans;
    string output;
    int index = 0;
    solve(nums, output, index, ans);
    return ans;
}
int main()
{
    string str="abc";
    vector<string> ans = subset(str);
    for (const auto &row : ans)
    {
       cout<<row<<endl;
    }
    return 0;
}