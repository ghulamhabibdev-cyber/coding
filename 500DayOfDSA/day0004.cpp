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
int nDividbym(int n, int m)
{
    int rem = n % m;
    if (rem == 0)
    {
        return n;
    }
    else
    {
        if (n < 0)
        {
            n += rem;
            return abs(n);
        }
        int maxi = min(rem, m - rem);
        n -= maxi;
        n = abs(n);
        return n;
    }
}
int main()
{
    int ans = nDividbym(15, 4);
    cout << ans << endl;
    return 0;
}