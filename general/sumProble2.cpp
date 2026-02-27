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

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int a;
        int b;
        int c;
        cin >> a >> b >> c;
        if (a + b == c || a + c == b || b + c == a)
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