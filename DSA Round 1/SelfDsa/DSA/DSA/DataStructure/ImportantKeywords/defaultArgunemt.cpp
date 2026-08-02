#include <bits/stdc++.h>
using namespace std;
#define Print(arr,x) \
{\
    for(int i=0;i<x;i++)\
{\
    cout<<arr[i]<<" ";\
}\
}\

void printArray(int arr[],int size,int n=2)
{
    for(int i=n;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }

}
int main()
{
    int arr[4]={1,2,3,4};
    printArray(arr,4,3);
    Print(arr,4);
  
    return 0;
}