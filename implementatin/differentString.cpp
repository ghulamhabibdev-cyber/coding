#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits>
#include <list>
// typedef bool bo;
// typedef string  str;
// typedef int in;
// typedef char ch;
using namespace std;

class A
{
};
pair<bool, string> checkPossibleDiffStr(string s)
{
    int n = s.length();
    char c = s[0];
    bool foundFlag = false;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i + 1] != s[i])
        {
            swap(s[i + 1], s[i]);
            foundFlag = true;
            break;
        }
    }
    if (foundFlag)
    {
        return {foundFlag, s};
    }
    return {foundFlag, s};
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        pair<bool, string> p = checkPossibleDiffStr(str);
        if (p.first)
        {
            cout << "YES" << endl;
            cout << p.second << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}