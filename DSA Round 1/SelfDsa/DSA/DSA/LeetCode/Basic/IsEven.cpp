#include <iostream>
using namespace std;
bool IsEven(int num)
{
    if (num & 1)
    {
        return 0;
    }
    return 1;
}
int Fact(int n)
{
    int fact = 1;
    for (int i = 2; i <= n; i++)
    {
        fact = fact * i;
    }
    return fact;
}
int nCr(int n, int r)
{
    int nom = Fact(n);
    int den = (Fact(r) * (Fact(n - r)));
    return nom / den;
}
int main()
{
    cout << IsEven(12) << endl;
    cout << Fact(0) << endl;
    cout << nCr(5, 2);
}