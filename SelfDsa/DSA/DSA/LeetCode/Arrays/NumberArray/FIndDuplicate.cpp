#include<iostream>
using namespace std;
int main()
{
    int arr[5]={1,2,2,1};
    int ans=0;
    for(int i=0;i<5;i++)
    { 
            ans=ans^arr[i];
    }
    cout<<ans<<endl;
     for(int i=0;i<4;i++)
    {
            ans=ans^arr[i];
    }
    cout<<ans<<endl;
}