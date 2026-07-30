#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits>
#include <list>
#include <math.h>
using namespace std;

class A
{
};
int gcd(int a, int b)
{
    while (b != 0)
    {
        int rem = a % b;
        a = b;
        b = rem;
    }
    return a;
}
int maxGcd(int n)
{
    int prev = -1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            prev = max(gcd(i, j), prev);
        }
    }
    return prev;
}
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        int maxiGc = maxGcd(n);
        cout << maxiGc << endl;
    }

    return 0;
}