#include <iostream>
using namespace std;
int rev()
{

    int n;
    cout << "Enter number : ";
    cin >> n;
    int ans = 0;
    while (n != 0)
    {
        if (((ans * 10) > INT32_MAX) || ((ans * 10) > INT32_MAX))
        {
            return 0;
        }
        int digit = n % 10;
        ans = (ans * 10) + digit;
        n = n / 10;
    }
    cout << ans;
    return ans;
}
int main()
{
    rev();
}