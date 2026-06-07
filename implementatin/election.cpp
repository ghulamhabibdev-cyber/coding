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
int findMax(int a, int b, int c)
{
    int maxi = a;
    if (maxi < b)
    {
        maxi = b;
    }
    if (maxi < c)
    {
        maxi = c;
    }
    return maxi;
}
void findElectWiner(int a, int b, int c)
{
    if (a == b && b == c)
    {
        cout << a + 1 << " " << b + 1 << " " << c + 1 << endl;
        return;
    }
    int maxi = findMax(a, b, c);
    // cout << "I am Masi " << maxi << endl;
    if (maxi == a)
    {
        cout << 0 << " " << (maxi - b) + 1 << " " << (maxi - c)+1 << " " << endl;
    }
    else if (maxi == b)
    {
        cout << (maxi - a) + 1 << " " << 0<< " " << (maxi - c) + 1 << " " << endl;
    }
    else
    {
        cout << (maxi - a) + 1 << " " << (maxi - b) + 1 << " " << 0 << " " << endl;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        findElectWiner(a, b, c);
    }
    return 0;
}