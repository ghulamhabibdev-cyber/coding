#include<iostream>
using namespace std;
long long oddSumFun(long long n)
{
    if (n % 2 == 0)
        n = n - 1;

    long long terms = (n + 1) / 2;
    return terms * (2 * 1 + (terms - 1) * 2) / 2;
}

long long evenSumFun(long long n)
{
    if (n % 2 != 0)
        n = n - 1;

    long long terms = n / 2;
    return terms * (2 * 2 + (terms - 1) * 2) / 2;
}

long long calculatingFunction(long long n)
{
    return evenSumFun(n) - oddSumFun(n);
}
int main()
{
    long long n;
    cin >> n;
    long long ans = calculatingFunction(n);
    cout << ans;
    return 0;
}