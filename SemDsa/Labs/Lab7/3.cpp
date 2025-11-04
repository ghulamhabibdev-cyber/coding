#include <iostream>
using namespace std;
int power(int n, int pow)
{
    int ans = 1;
    for (int i = 1; i <= pow; i++)
    {
        ans *= n;
    }
    return ans;
}
int main()
{
    int n;
    int pow;
    cout << "Enter the number \n";
    cin >> n;
    cout << "Enter the power \n";
    cin >> pow;
    int ans = power(n, pow);
    cout << ans << endl;

    return 0;
}
