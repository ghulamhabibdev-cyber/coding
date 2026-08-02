#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[5]={32,545,667,87,-1};
    int mini=INT_MAX;
    int maxi=INT_MIN;
    for(int i=1;i<5;i++)
    {
        if(arr[i]>maxi)
        {
            maxi=arr[i];
        }
        if(arr[i]<mini)
        {
            mini=arr[i];
        }
    }
    cout<<"Maxi : "<<maxi<<endl;
    cout<<"Mini  : "<<mini<<endl;
    return 0;
}
