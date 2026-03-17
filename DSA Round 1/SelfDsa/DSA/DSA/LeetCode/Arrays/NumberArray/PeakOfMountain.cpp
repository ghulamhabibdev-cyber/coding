#include<iostream>
using namespace std;
int PeakElement(int arr[],int size)
{
    int start=0;
    int end=size-1;
    int mid=start+(end-start)/2;
    while (start<end)
    {
        if(arr[mid]<arr[mid+1])
        {
            start=mid+1;
        }
        else
        {
            end=mid;
        }
        mid=start+(end-start)/2;
    }
    return start;
}
int main()
{
    int arr[5]={1,2,5,6,3};
    cout<<PeakElement(arr,5);
}