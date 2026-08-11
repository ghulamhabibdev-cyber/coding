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
bool identicalCharCount(string str, string str2)
{
    if (str.length() != str2.length())
    {
        return false;
    }
    // we assump that it contain all charact 128
    vector<int> dp(128, 0);
    for (char c : str)
    {
        int index = c;
        dp[c]++;
    }
    for (int i = 0; i < str2.length(); i++)
    {
        int index = str2[i];
        dp[index]--;
        if (dp[index] < 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    bool ans = identicalCharCount("ali", "ila");
    if (ans)
    {
        cout << "yes " << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}