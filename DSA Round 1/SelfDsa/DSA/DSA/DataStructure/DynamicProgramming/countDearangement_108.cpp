#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
class a
{
public:
};
long long int countDearangeMent(int n)
{
    // base case
    if (n == 1)
    {
        return 0;
    }
    if (n == 2)
    {
        return 1;
    }
    long long int ans = ((n - 1) % MOD * ((countDearangeMent(n - 1) + countDearangeMent(n - 2)) % MOD)) % MOD;

    return ans;
}

int main()
{
    cout << countDearangeMent(4);
    return 0;
}