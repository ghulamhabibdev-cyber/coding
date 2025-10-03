#include <bits/stdc++.h>
using namespace std;
int RemoveVal(int arr[], int size,int val)
{
    int runer = 0;
   
   
    for (int i = 0; i < size; i++)
    {
        if(arr[i]!=val)
        {
            arr[runer]=arr[i];
            ++runer;
        }
    }
    for(int i=0;i<size;i++)
    {
        cout<<"|"<<arr[i]<<" |";
        if(arr[i]==8)
        {
            cout<<"Eight exist in arr\n";
        }
    }
}
int main()
{
    // int arr[8] = {0,1,2,2,3,0,4,2};
    int arr[4]={3,2,2,3};
    cout << RemoveVal(arr, 4,3);
    return 0;
}