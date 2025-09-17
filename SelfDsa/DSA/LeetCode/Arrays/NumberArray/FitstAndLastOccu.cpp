#include<iostream>
using namespace std;
int FistOcuurence(int arr[],int size,int key)
{
    int start=0;
    int end=size-1;
    int mid=start+(end-start)/2;
    int ans=-1;
    while (start<=end)
    {
        if(key==arr[mid])
        {
            ans=mid;
            end=mid-1;
        }
        else if(key>arr[mid])
        {
            start=mid+1;
        }
        else{
            end=mid-1;
        }
        mid=start+(end-start)/2;
    }
    return ans;
    
}
int LastOccurenct(int arr[],int size,int key)
{
 int start=0;
    int end=size-1;
    int mid=start+(end-start)/2;
    int ans=-1;
    while (start<=end)
    {
        if(key==arr[mid])
        {
            ans=mid;
            start=mid+1;
        }
        else if(key>arr[mid])
        {
            start=mid+1;
        }
        else{
            end=mid-1;
        }
        mid=start+(end-start)/2;
    }
    return ans;   
}
int main()
{
    int arr[5]={1,2,3,3,5};
    int first=FistOcuurence(arr,5,3);
    cout<<"First Occurence : "<<first<<endl;
    cout<<"Last occurence : "<<LastOccurenct(arr,5,3);
}