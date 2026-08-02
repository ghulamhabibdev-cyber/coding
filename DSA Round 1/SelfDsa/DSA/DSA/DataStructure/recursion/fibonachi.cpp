#include <bits/stdc++.h>
using namespace std;
int fib(int n)
{
    if(n==0)
    {
        return 0;
    }
    if(n==1)
    {
        return 1;
    }
    int num=0;
    num=fib(n-1)+fib(n-2);
    return num;
}
int main()
{
    vector<int> v;
    vector<int> v3;
    for(int i=0;i<v.size();i++)
    {
        v.push_back(v3[i]);
    }
    sort(v.begin(),v.end());
  cout<<fib(7);
    return 0;
}