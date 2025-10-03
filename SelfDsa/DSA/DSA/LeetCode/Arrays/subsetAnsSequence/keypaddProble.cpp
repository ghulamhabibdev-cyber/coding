#include <bits/stdc++.h>
using namespace std;
void solve(string digit, string ouput, int index, vector<string> &ans, string map[])
{
    if (index >= digit.length())
    {
        ans.push_back(ouput);
        return;
    }
    int number = digit[index] - '0';
    string value = map[number];
    for (int i = 0; i < value.length(); i++)
    {
        ouput.push_back(value[i]);
        solve(digit, ouput, index + 1, ans, map);
        ouput.pop_back();
    }
}
vector<string> letterComm(string digit)
{
    vector<string> ans;
    if (digit.length() == 0)
    {
        return ans;
    }
    string ouput;
    int index = 0;
    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    solve(digit, ouput, index, ans, mapping);
    return ans;
}
int main()
{
    vector<string> ans=letterComm("234");
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
     return 0;
}