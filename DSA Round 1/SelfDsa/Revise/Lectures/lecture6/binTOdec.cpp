#include <bits/stdc++.h>
using namespace std;

int main()
{
    int binary;
    cout << "Enter the Binary\n";
    cin >> binary;
    int ans = 0;
    int base = 1;
    while (binary != 0)
    {
        int digit = binary % 10;
        if (digit == 1)
        {
            ans = ans + base;
        }

        base *= 2;
        binary = binary / 10;
    }
    cout << ans << endl;
    return 0;
}
