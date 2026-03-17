#include <iostream>
using namespace std;
bool IsPossible(int arr[],int size,int m,int mid)
{
    int cowCount=0;
    int lastPos=arr[0];
    for(int i=0;i<size;i++)
    {
        if(arr[i]-lastPos>=mid)
        {
            cowCount++;
            if(cowCount==m)
            {
                return true;
            }
            lastPos=arr[i];

        }
        
    }
    return false;
}
int AggressiveCow(int arr[],int size,int m)
{
    int start=0;
    int ans=-1;
    
    int maxi=INT32_MIN;
    for(int i=0;i<size;i++)
    {
        if(arr[i]>maxi)
        {
            maxi=arr[i];
        }
    }
    int end=maxi;
    int mid=start+(end-start)/2;
    while (start<=end)
    {
        if(IsPossible(arr,size,m,mid))
        {
            ans=mid;
            start=mid+1;
        }
    }
    return ans;
}
int main()
{
    int arr[5]={1,2,3,4,6};
    cout<<AggressiveCow(arr,5,2);
    return 0;
}
