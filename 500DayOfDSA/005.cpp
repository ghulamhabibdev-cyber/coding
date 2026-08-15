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
void prepareMap(unordered_map<char, int> &mp, string str)
{
    for (char ch : str)
    {
        mp[ch]++;
    }
}
bool checkPalindromePermuation(string str)
{
    unordered_map<char, int> mp;
    prepareMap(mp, str);
    bool oddFound = false;
    for (auto p : mp)
    {
        if (p.second % 2 == 1)
        {
            if (oddFound)
            {
                return false;
            }
            oddFound = true;
        }
    }
    return true;
}
int main()
{

    string str = "allaey";
    bool ans = checkPalindromePermuation(str);
    if (ans)
    {
        cout << "Yes " << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}
