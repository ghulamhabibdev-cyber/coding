#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a = 0;
    int b = 1;
    int n = 10;
    for(int i=1;i<=n;i++)
    {
        int n=a+b;
        cout<<n<<" ";
        a=b;

        b=n;
    }
     return 0;
}
