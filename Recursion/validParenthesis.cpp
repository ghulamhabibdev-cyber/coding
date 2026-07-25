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
void findAllCombinations(int open, int close, int n, string &tmp, vector<string> &arr)
{
    if (open == n && close == n)
    {
        arr.push_back(tmp);
        return;
    }
    if (open < n)
    {
        tmp += '(';
        findAllCombinations(open + 1, close, n, tmp, arr);
        tmp.pop_back();
    }
    if (close < open)
    {
        tmp += ')';
        findAllCombinations(open, close + 1, n, tmp, arr);
        tmp.pop_back();
    }
    return;
}
int main()
{
    string tmp = "";
    int n = 3;
    vector<string> arr;
    findAllCombinations(0, 0, n, tmp, arr);
    for (string str : arr)
    {
        cout << str << endl;
    }
    return 0;
}