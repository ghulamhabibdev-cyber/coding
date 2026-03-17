#include <iostream>
#include <vector>
using namespace std;
void merge(int arr[], int s, int e)
{
    vector<int> ans;
    int mid = s + (e - s)/2;
    int i = s;
    int j = mid + 1;
    while (i <= mid && j <= e)
    {
        if (arr[i] < arr[j])
        {
            ans.push_back(arr[i]);
            i++;
        }
        else{
            ans.push_back(arr[j]);
            j++;
        }
    }
    while(i<=mid)
    {
        ans.push_back(arr[i]);
        i++;
    }
    while(j<=e)
    {
        ans.push_back(arr[j]);
        j++;
    }
    for(int i=0;i<ans.size();i++)
    {
        arr[s+i]=ans[i];
    }
}
void mergeSort(int arr[], int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int mid = s + (e - s) / 2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);
    merge(arr, s, e);
}
int main()
{
    int arr[10] = {32, 1, 23, 34, 56, 35, 65, 678, 44, 34};
    int n = 10;
    mergeSort(arr, 0, n - 1);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
