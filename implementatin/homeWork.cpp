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
string homeWork(string a, string b, string c)
{
    int n = b.length();
    for (int i = 0; i < n; i++)
    {
        if (c[i] == 'V')
        {
            a = b[i] + a;
        }
        else
        {
            a = a + b[i];
        }
    }
    return a;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int lenA;
        cin >> lenA;
        string a, b, c;
        cin >> a;
        int lenBC;
        cin >> lenBC;
        cin >> b >> c;
        string homeWorkStr = homeWork(a, b, c);
        cout << homeWorkStr << endl;
    }

    return 0;
}