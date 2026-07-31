#include<iostream>
using namespace std;

int main()
{
    int arr[5]={323};

    int pos;
    cout<<"Enter pos \n";
    cin>>pos;
    for(int i=5;i>pos;i--)
    {
        arr[i]=arr[i-1];
    }
    arr[pos]=4;
    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
