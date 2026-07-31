#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cout << "Enter a Number : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << n-j+1 << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = n; j>= 1; j--)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
