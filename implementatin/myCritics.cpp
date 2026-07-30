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
bool MyCritics(int a, int b, int c)
{

    int ans = 10 - a - b;
    if (ans <= 0)
    {
        return true;
    }

    ans = 10 - a - b;
    if (ans <= 0)
    {
        return true;
    }
    ans = 10 - a - c;
    if (ans <= 0)
    {

        return true;
    }

    ans = 10 - b - c;
    if (ans <= 0)
    {
        return true;
    }
    return false;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        bool isPossible = MyCritics(a, b, c);
        if (isPossible)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}