#include<iostream> 
using namespace std; 
void PrintArray(int arr[], int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<"\t";
    }
}
int BinarySearch(int arr[],int size,int key)
{
    int start=0;
    int end=size-1;
    int mid=start+(end-start)/2;
    while (start<=end)
    {
        if(key==arr[mid])
        {
            return mid;
        }
        if(key>arr[mid])
        {
            start=mid+1;
        }
        else
        {
            end=mid-1;
        }
        mid=start+(end-start)/2;
    }
    return -1;
    
}
int main()
{
    int arr[5]={1,22,333,4444,55555};
    cout<<BinarySearch(arr,5,55555);
}