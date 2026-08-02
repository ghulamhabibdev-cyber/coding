#include <bits/stdc++.h>
using namespace std;
inline int getMax(int a, int b)
{
    return (a > b) ? a : b;
}
int main()
{

    int a = 1;
    int b = 3;
    int ans = getMax(a, b);
    cout << "Max : " << ans << endl;
    a = a + 40;
    b = b + 10;
    ans = getMax(a, b);
    cout << "Max : " << ans << endl;
    return 0;
}