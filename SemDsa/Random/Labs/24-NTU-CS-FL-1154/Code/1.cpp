#include <iostream>
using namespace std;
long factorial(int n)
{
    long ans = 1;
    for (int i = 2; i <= n; i++)
    {
        ans *= i;
    }
    return ans;
}
int main()
{

    int facNo;
    cout << "Enter the no \n";
    cin >> facNo;
    long ans = factorial(facNo);
    cout << ans << endl;
    return 0;
}
