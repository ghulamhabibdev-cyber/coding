#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    char ch = 'D';
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << char(ch - i + j) << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 1; i <= n; i++)
    {
        char chy = 'A' + n - i;
        for (int j = 1; j <= i; j++)
        {
            cout << char(chy) << " ";
            chy++;
        }
        cout << endl;
    }
    return 0;
}
