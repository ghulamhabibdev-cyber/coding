#include<iostream>
using namespace std;
int BinarySearch(int arr[],int n,int key)
{
    int start=0;
    int end=n-1;
    int mid=(start+end)/2;
    while(start<=end)
    {
        if(key==arr[mid]){
            return mid;
        }
        if(key>arr[mid])
        {
            start=mid+1;
        }
        else{
            end=mid-1;
        }
        mid=(start+end)/2;
    
    }
    return -1;
}
int ForloopBinar(int arr[],int n,int key)
{
    int start=0;
    int end=n-1;
    
    for(;start<=end;)
    {
        int mid=start+(end-start)/2;
        if(key==arr[mid])
        {
            return mid;
        }
        if(key>arr[mid])
        {
            start=mid+1;
        }
        else{
            end=mid-1;
        }
        
    }
    return -1;
}
int DowhileBinarySearch(int arr[],int n,int key)
{
    int start=0;
    int end=n-1;
    int mid=start+(end-start)/2;
    do{
        int mid=start+(end-start)/2;
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

    
    }while (start<=end);
   return -1;
}
int main()
{
    int arr[6]={1,2,3,4,5,6};
    // cout<<BinarySearch(arr,6,4);
    // cout<<ForloopBinar(arr,6,6);
    cout<<DowhileBinarySearch(arr,6,2);
}