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
void helper(vector<string> &ans, string &str, int n, int l, int r)
{
    if (l >= n && r >= n)
    {
        ans.push_back(str);
        return;
    }
    if (l < n)
    {
        str += '(';
        helper(ans, str, n, l + 1, r);
        str.pop_back();
    }
    if (r < l)
    {
        str += ')';
        helper(ans, str, n, l, r + 1);
        str.pop_back();
    }
}
vector<string> generateParathesise(int n)
{
    vector<string> ans;
    string str = "";
    helper(ans, str, n, 0, 0);
    return ans;
}
int main()
{
    int n;
    // cout << "Enter A number : " << endl;
    // cin >> n;
    n = 2;
    vector<string> ans = generateParathesise(n);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}