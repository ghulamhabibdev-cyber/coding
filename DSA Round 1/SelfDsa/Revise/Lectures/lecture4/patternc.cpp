#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int count = i;
        for (int j = i; j <= (2*i-1); j++)
        {
            cout << j << " ";
            count++;
        }
        // count = i+1;
        cout << endl;
    }
    return 0;
}
