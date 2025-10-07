#include <bits/stdc++.h>
using namespace std;

int main()
{
    // int sum = 0;
    // int n = 100;
    // for (int i = 1; i <= n; i++)
    // {
    //     if (i > 50)
    //     {
    //         continue;
    //     }
    //     else
    //     {
    //         cout << i << " ";
    //         sum += i;
    //     }
    //     // sum+=i;
    // }
    // for (int i = 0; i <= 6; i++)
    // {
    //     cout << "Hi \n";
    //     cout << "Yes \n";
    //     continue;
    //     cout << "Reply to day day\n";
    // }
    // for(int i=0;i<=5;i++)
    // {
    //     cout<<i<<" ";
    //     i++;

    // }
    // cout << sum << endl;
    for(int i=0;i<=15;i+=2)
    {
        cout<<i<<" ";
        if(i&1)
        {
            continue;
        }
        i++;

    }
    return 0;
}
