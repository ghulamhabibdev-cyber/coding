#include <bits/stdc++.h>
using namespace std;
int power(int n,int pow)
{
    if(pow==0)
    {
        return 1;
    }
    int ans=1;
    ans=n*power(n,pow-1);
    return ans;
}
int main()
{
  cout<<power(2,3);
    return 0;
}
