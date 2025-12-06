#include <bits/stdc++.h>
using namespace std;
bool binary_search(int arr[], int size, int key)
{
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start) / 2;
    while (start <end)
    {
         
        if (arr[mid] == key)
        {
            return true;
        }
        if (key>arr[mid])
        {
            start = mid + 1;
            
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return false;
}
bool binarySearch(int arr[],int s,int e,int k)
{
    if(s>e)
    {
        return 0;
    }
    int mid=s+(e-s)/2;
    if(arr[mid]==k)
    {
        return true;
    }
    if(k>arr[mid])
    {
        return binarySearch(arr,mid+1,e,k);
    }
    else{
        return binarySearch(arr,s,mid-1,k);
    }
}
int main()
{
    int arr[4] = {1, 2, 3, 4};
    // cout << binary_search(arr, 4, 3);
    cout<<binarySearch(arr,0,3,4);
    return 0;
}