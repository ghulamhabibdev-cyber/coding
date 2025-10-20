#include <iostream>
using namespace std;
int solve(int arr[], int size, int key, int mid, int s, int e)
{
    if (s > e)
    {
        return -1;
    }
    if (arr[mid] == key)
    {
        return mid;
    }
    mid = s + (e - s) / 2;
    if (key < arr[mid])
    {
        return solve(arr, size, key, mid, s, e - 1);
    }
    else
    {
        return solve(arr, size, key, mid, s + 1, e);
    }

}
int binSearch(int arr[], int size, int key)
{
    int s = 0;
    int e = size - 1;
    int mid = s + (e - s) / 2;
    int ans = solve(arr, size, key, mid, s, e);
    return ans;
}
int main()
{
    int arr[7] = {1, 2, 3, 4, 5, 6, 7};
    cout<<"Enter a element \n";
    int n;
    cin>>n;
   int ans=binSearch(arr,7,n);
   if(ans>=0)
   {
    cout<<arr[ans]<<endl;
   }
    return 0;
}
