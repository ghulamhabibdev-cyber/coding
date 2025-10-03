#include <bits/stdc++.h>
using namespace std;
int fact(int n)
{
    if(n==0)
    {
        return 1;
    }
    long long  int ans=1;
    ans=n*fact(n-1);
    return ans;

}
int main()
{
    cout<<fact(100);
  
    return 0;
}
