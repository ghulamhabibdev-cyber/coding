#include<bits/stdc++.h>
using namespace std;
void reverseArr(int arr[],int size)
{
    int st=0;
    int end=size-1;
    while(st<end)
    {
        int temp=arr[end];
        arr[end]=arr[st];
        arr[st]=temp;
        st++;
        end--;
    }
}
int main()
{

    int arr[6]={34,35,36,37,38,39};
    for(int i=0;i<6;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    reverseArr(arr,6);
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
