#include <iostream>
using namespace std;
void DeciTOBinary(int n)
{
    int ans = 0;
    int ten = 1;
    int rem;
    while (n > 0)
    {
        rem = n % 2;
        if (ten == 1)
        {
            ans = ans + ten * rem;
            ten = 10;
            n=n/2;
        }
        else
        {
            ans = ans + ten * rem;
            ten*=10;
            n=n/2;
        }
        
        /* code */
    }
    cout<<ans<<endl;
}
int main()
{
    int n;
    cout << "Enter a No : ";
    cin >> n;
    // char digits[20];
    // int rem;
    // int i = 0;
    // while (n > 0)
    // {
    //     rem = n % 2;
    //     digits[i] = '0' + rem;
    //     n = n / 2;
    //     i++;
    //     /* code */
    // }
    // for (int j = i; j >= 0; j--)
    // {
    //     cout << digits[j];
    // }
    DeciTOBinary(n);
}