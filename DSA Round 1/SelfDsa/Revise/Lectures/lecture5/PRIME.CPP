#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number \n";
    cin >> n;
    bool prime = true;
    for (int i = 2; i <= n - 1; i++)
    {
        if (n % i == 0)
        {
            prime = 0;
            break;
        }
    }
    if (prime)
    {
        cout << " this number : " << n << " is prime \n";
    }
}
