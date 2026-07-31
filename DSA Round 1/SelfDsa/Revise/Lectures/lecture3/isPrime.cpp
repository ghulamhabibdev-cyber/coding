#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter number \n";
    cin>>n;
    int i=2;
    bool isprime=true;
    while(i<n)
    {
        if(n%i==0)
        {
            isprime=false;

        }
        i++;
    }
    if(isprime)
    {
        cout<<"Prim \n";
    }else{
        cout<<"Not prime \n";
    }
    return 0;
}
