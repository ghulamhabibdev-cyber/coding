#include <iostream>
using namespace std;
int partition(int arr[],int s,int e)
{
    int pivot=arr[s];
    int cnt=0;
    for(int i=s+1;i<=e;i++)
    {
        if(arr[i]<=pivot)
        {
            cnt++;
        }
    }
    // place pviot at right place
    int pivotIndex=s+cnt;
    swap(arr[pivotIndex], arr[s]);
    int i=s;
    int j=e;
    while (i <= pivotIndex && j > pivotIndex)
    {
      while(arr[i]<pivot)
      {
        i++;
      }
      while(arr[j]>pivot)
      {
        j--;
      }
      if(i<pivotIndex&&j>pivotIndex)
      {
        swap(arr[i++],arr[j--]);
      }
    }

    return pivotIndex;

}
void quickSort(int arr[], int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int p = partition(arr, s, e);
    quickSort(arr, s, p - 1);
    quickSort(arr, p + 1, e);
}
int main()
{
    int arr[16] = {9,9,9,9,9,93,3,3,3,3,10,23,43,434,0,0};
    int n = 16;
    quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
