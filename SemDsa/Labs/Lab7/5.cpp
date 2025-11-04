#include <iostream>
using namespace std;
int fib(int n)
{
    int ans = 0;
    int a = 0;
    int b = 1;
    for (int i = 0; i < n; i++)
    {
        ans = a + b;
        a = b;
        b = ans;
    }
    return ans;
}
int main()
{
    int n;
    cout << "Enter the fib term no \n";
    cin >> n;
    int ans = fib(n);
    cout << ans << endl;

    return 0;
}
