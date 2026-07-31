#include <bits/stdc++.h>
using namespace std;

int main()
{
    char ch;
    cout << "Enter a character \n";
    cin >> ch;
    if (ch > 'a' && ch < 'z')
    {
        cout << "Lower case \n";
    }
    else if (ch > 'A' && ch < 'Z')
    {
        cout << "Uper case \n";
    }
    else if (ch >='0' && ch <='9')
    {
        cout << "Digit \n";
    }
    else
    {
        cout << "symbol \n";
    }
    return 0;
}
