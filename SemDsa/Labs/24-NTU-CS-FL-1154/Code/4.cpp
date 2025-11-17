#include <iostream>
using namespace std;
int power(int n, int pow)
{
    if (pow == 0)
    {
        return 1;
    }
    if (pow == 1)
    {
        return n;
    }
    int ans = n * power(n, pow - 1);
    return ans;
}
int main()
{
    int n;
    int pow;
    cout << "Enter the No \n";
    cin >> n;
    cout << "Enter the power \n";
    cin >> pow;
    int ans = power(n, pow);
    cout << ans << endl;

    return 0;
}
