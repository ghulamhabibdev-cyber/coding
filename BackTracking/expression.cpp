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
void solve(string str, int index, int num, string exp, int target, vector<string> &res)
{
    if (index >= str.length())
    {
        if (num == target)
        {
            exp.pop_back();
            res.push_back(exp);
        }
        return;
    }
    exp += str[index];
    exp += '+';
    int dig = str[index] - '0';
    num += dig;
    solve(str, index + 1, num, exp, target, res);
    exp.pop_back();
    num -= dig;

    exp += str[index];
    exp += '-';
    num -= dig;
    solve(str, index + 1, num, exp, target, res);
    exp.pop_back();
    num += dig;
    
    exp += str[index];
    exp += '*';
    num *= dig;
    solve(str, index + 1, num, exp, target, res);
    exp.pop_back();
    num /= dig;

    exp += str[index];
    exp += '/';
  
    if (num != 0)
    {
        num /= dig;
    }
    else
    {
        num = dig;
    }
    solve(str, index + 1, num, exp, target, res);
    exp.pop_back();
    num *= dig;
}
int main()
{
    vector<string> res;
    string exp = "123";
    solve(exp, 0, 0, "", 6, res);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}