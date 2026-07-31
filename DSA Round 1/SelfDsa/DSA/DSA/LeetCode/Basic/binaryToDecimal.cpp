#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter Number : ";
    cin >> n;
    int i = 1;
    int two = 2;
    int deci = 0;
    int rem;
    while (n > 0)
    {
        rem = n % 10;
        if (i == 1)
        {
            deci = deci + rem * i;
            n = n / 10;
            i++;
        }
        else
        {
            deci = deci + rem * two;
            two = two * two;
            n = n / 10;
        }

        /* code */
    }
    cout << deci << endl;
}