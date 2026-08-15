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
bool isPossibleToDividNBarely(long long  n, long long k)
{
    if (n % k == 0)
    {
        return true;
    }
    else if(n%2==0)
    {
        return true;
    }
    return (n - k) % 2 == 0;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long  coins;
        long long  k;
        cin >> coins >> k;
        bool barely = isPossibleToDividNBarely(coins, k);
        if (barely)
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