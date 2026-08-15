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
int callElevator(int a, int b, int c)
{
    int bTime = 0;
    if (b > c)
    {
        bTime = b - 1;
    }
    else
    {
        bTime = c - 1;
        bTime += c - b;
        // cout << bTime << endl;
    }
    if (bTime > a-1)
    {
        return 1;
    }
    else if (a-1 > bTime)
    {
        return 2;
    }
    return 3;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int minTime = callElevator(a, b, c);
        cout << minTime << endl;
    }

    return 0;
}