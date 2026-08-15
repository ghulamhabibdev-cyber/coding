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
void lowerCase(string &str)
{
    int n = str.length();
    for (int i = 0; i < n; i++)
    {
        char ch = str[i];
        if (ch >= 'A' && ch <= 'Z')
        {
            ch = 'a' + ch - 'A';
        }
        str[i] = ch;
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        lowerCase(str);
        if (str == "yes")
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}