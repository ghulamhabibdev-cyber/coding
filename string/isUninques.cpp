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
bool isUniqueChar(string s)
{
    vector<bool> dp(26, false);
    if (s.length() > 26)
    {
        return false;
    }
    for (int i = 0; i < s.length(); i++)
    {
        int index = s[i] - 'a';
        cout << index << endl;
        if (dp[index])
        {
            return false;
        }
        dp[index] = true;
    }
    return true;
}
int main()
{
    bool ans = isUniqueChar("aili");
    if (ans)
    {
        cout << "uniques";
    }
    else
    {
        cout << "not Unique";
    }
    return 0;
}