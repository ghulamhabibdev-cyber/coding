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
char mostFreqeuntChar(string str)
{
    int aCount = 0;
    int bCount = 0;
    int n = str.length();
    for (int i = 0; i < n; i++)
    {
        char ch = str[i];
        if (ch == 'A')
        {
            aCount++;
        }
        else
        {
            bCount++;
        }
    }
    return aCount > bCount ? 'A' : 'B';
}
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        string str;
        cin >> str;
        char ans = mostFreqeuntChar(str);
        cout << ans << endl;
    }

    return 0;
}