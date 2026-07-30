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
bool canSquare(long long n)
{
    if (n < 0)
        return false;

    long long ans = sqrt(n);
    return ans * ans == n;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            int ai;
            cin >> ai;
            sum += ai;
        }
        bool isSquare = canSquare(sum);
        if (isSquare)
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