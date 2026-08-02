#include <iostream>
using namespace std;
int fib(int n)
{
    if (n == 1)
    {
        return 1;
    }
    if (n == 0)
    {
        return 1;
    }
    int ans = fib(n - 2) + fib(n - 1);
    return ans;
}
int main()
{
    int n;
    cout << "Enter the no \n";
    cin >> n;
    int ans = fib(n);
    cout << ans << endl;

    return 0;
}
