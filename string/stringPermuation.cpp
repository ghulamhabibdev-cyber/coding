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
vector<string> findStringPermuation(string str)
{
    vector<string> res;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        for (char c = 'a'; c <= 'z'; c++)
        {
            if (c != ch)
            {
                str[i] = c;
                res.push_back(str);
            }
        }
        str[i] = ch;
    }
    return res;
}
int main()
{
    vector<string> res = findStringPermuation("abc");
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << endl;
    }
    return 0;
}