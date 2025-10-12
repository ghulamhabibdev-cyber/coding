// 11. Write a program to input and display elements of a 1D array.
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[4];
    cout<<"===============Input==================\n";
    for(int i=0;i<4;i++)
    {
        cout<<"Enter A number \n";
        cin>>arr[i];
    }
    cout<<"=================Displaying Results ==========\n";
    for(int i=0;i<4;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
