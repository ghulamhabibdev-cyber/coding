#include <bits/stdc++.h>
using namespace std;
int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    int ans = factorial(n - 1);
    int fac = n * ans;
    return fac;
}
int power(int n, int pow)
{
    if (pow == 0)
    {
        return 1;
    }
    int ans = n * power(n, pow - 1);
    cout << ans << endl;
    return ans;
}
int sumToNumber(int n)
{
    if (n == 0)
    {
        return 0;
    }
    int sum = n + sumToNumber(n - 1);
    return sum;
}
int table(int n, int lim)
{
    if (lim == 0)
    {
        return 0;
    }
    lim = n + table(n, lim - 1);
    return lim;
}
void printCounting(int n)
{
    if (n == 0)
    {
        return;
    }

    printCounting(n - 1);
    cout << "Count : " << n << endl;
}
int main()
{
    // int n;
    // cin >> n;
    //   int ans=factorial(n);
    //   cout<<ans;
    // power(2, n);

    // cout<<sumToNumber(n);
    // cout<<table(3,20);
    printCounting(5);
    return 0;
}