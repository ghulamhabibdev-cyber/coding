#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits>
#include <list>
#include <string>
using namespace std;

class A
{
};
bool checkImportancy(string st)
{
    if (st[0] != '1')
    {
        return false;
    }
    string power = "";
    int n = st.length();
    int zeroCount = 0;
    for (int i = 1; i < n; i++)
    {
        if (st[i] == '0')
        {
            zeroCount++;
            ;
        }
        else
        {
            if (zeroCount == 0)
            {
                continue;
            }
            while (i < n)
            {
                power += st[i];
                i++;
            }
        }
    }
    if (zeroCount == 0 && (power == "1" || power == "2") || (power == ""))
    {
        return false;
    }
    return true;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int number;
        cin >> number;
        string str = to_string(number);
        bool foundImport = checkImportancy(str);
        if (foundImport)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}