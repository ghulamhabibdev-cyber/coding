#include <vector>
#include <iostream>
using namespace std;

class A
{
};
template <typename T>
void printArray(vector<T> arr, int idx)
{
    if (idx >= arr.size())
    {
        return;
    }
    cout << arr[idx] << " ";
    printArray(arr, idx + 1);
}
template <typename T>
void prinReverseArray(vector<T>arr,int idx)
{
    if(idx>=arr.size())
    {
        return;
    }
    prinReverseArray(arr,idx+1);
    cout<<arr[idx]<<" ";
}
int sumArray(vector<int>arr,int idx)
{
    if(idx>=arr.size())
    {
        return 0;
    }
    int  ans=sumArray(arr,idx+1)+arr[idx];
    return ans;
}
void reverseArray(vector<int>&arr,int st,int end)
{
    if(st>end)
    {
        return;
    }
    swap(arr[st],arr[end]);
    reverseArray(arr,st+1,end-1);
}
int findMin(vector<int>arr,int idx)
{
    if(idx>=arr.size())
    {
        return INT_MAX;
    }
    int mini=min(arr[idx],findMin(arr,idx+1));
    return mini;
}
int findMax(vector<int>arr,int idx)
{
    if(idx>=arr.size())
    {
        return INT_MIN;
    }
    int maxi=max(arr[idx],findMax(arr,idx+1));
    return maxi;
}
int main()
{

    vector<int> arr = {2, -2, 2, 20, 10, 20};
    // printArray(arr, 0);
    // prinReverseArray(arr,0);
    // int sum=sumArray(arr,0);
    // cout<<"sum of Array : "<<sum<<endl;
    // reverseArray(arr,0,arr.size()-1);
    // printArray(arr,0);
    cout<<findMin(arr,0)<<endl;
    cout<<findMax(arr,0)<<endl;

    return 0;
}