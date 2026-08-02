#include<iostream>
using namespace std;
bool IsPossible(int arr[],int size,int m,int mid)
{
    int stdCount=1;
    int pageSum=0;
    for(int i=0;i<size;i++)
    {
        if(pageSum+arr[i]<=mid)
        {
            pageSum+=arr[i];
        }
        else
        {
            stdCount++;
            if(stdCount>m||arr[i]>mid)
            {
                return false;
            }
            pageSum=arr[i];
        }
    }
    return true;
}
int Allocation(int arr[],int size,int m)
{
    int start=0;
    int sum=0;
    for(int i=0;i<size;i++)
    {
        sum+=arr[i];
    }
    int end=sum;
    int ans=-1;
    int mid=start+(end-start)/2;
    while (start<=end)
    {
        if(IsPossible(arr,size,m,mid))
        {
            ans=mid;
            end=mid-1;

        }
        else{
            start=mid+1;
        }
        mid=start+(end-start)/2;
    }
    
    return ans;
}
int main()
{
    int arr[4]={10,20,30,40};
    int m=2;
    cout<<Allocation(arr,4,2);
}