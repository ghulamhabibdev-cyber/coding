#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits>
#include <list>
using namespace std;

class A
{
};
pair<int, int> countChar(string str)
{
    int bigCharCount = 0;
    int smallCharCount = 0;
    int n = str.length();
    for (int i = 0; i < n; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            bigCharCount++;
        }
        else
        {
            smallCharCount++;
        }
    }
    return {smallCharCount, bigCharCount};
}
char myLower(char ch)
{
    if (ch >= 65 && ch <= 'Z')
    {
        ch = ch - 'A' + 'a';
    }
    return ch;
}
char myUpper(char ch)
{
    if (ch >= 'a' && ch <= 'z')
    {
        ch = ch - ('a' - 'A');
    }
    return ch;
}
string upLerLower(string str)
{
    pair<int, int> p = countChar(str);
    string ans = "";
    int n = str.length();

    if (p.first < p.second)
    {
        for (int i = 0; i < n; i++)
        {
            char ch = myUpper(str[i]);
            ans += ch;
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            char ch = myLower(str[i]);
            ans += ch;
        }
    }
    return ans;
}
int main()
{
    string str;
    cin >> str;
    str = upLerLower(str);
    cout << str << endl;
    return 0;
}