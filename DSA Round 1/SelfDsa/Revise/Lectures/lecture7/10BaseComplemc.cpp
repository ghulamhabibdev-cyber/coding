#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m = 10;
    int n = m;
    int mask = 0;
    while (n != 0)
    {
        mask = (mask << 1) | 1;
        n = n >> 1;
    }
    int ans = (~m) & mask;
    cout << ans << endl;
    return ans;
    return 0;
}
