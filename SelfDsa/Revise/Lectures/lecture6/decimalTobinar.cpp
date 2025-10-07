#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "enter the number \n";
    cin >> n;
    // string ans="";
    int ans = 0;
    int base = 1;
    while (n != 0)
    {
        int bit = n & 1; 
        ans = (base * bit) + ans;
        base *= 10;
        n = n >> 1;
    }
    cout << ans << endl;
    return 0;
}
