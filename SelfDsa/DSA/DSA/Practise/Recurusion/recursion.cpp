#include <bits/stdc++.h>
using namespace std;
bool ChechSorted(int arr[], int size)
{
    if (size == 1)
    {
        return 1;
    }
    return arr[size - 1] > arr[size - 2] ? 0 : ChechSorted(arr, size - 1);
}
void insertElementInArrr( vector<int> arr, int pos, int val)
{
   arr.push_back(0);

    for (int i = arr.size() -1; i > pos; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[pos]=val;
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}
void insertShiftArr(int arr[],int size,int pos,int val)
{
    for(int i=size-1;i>pos;i--)
    {
        arr[i]=arr[i-1];
    }
    arr[pos]=val;
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{
    int arr[5] = {5, 4, 3, 2, 1};
    insertShiftArr(arr,5,2,10);
    // vector<int> vArr;
    // for (int i = 0; i < 5; i++)
    // {
    //     vArr.push_back(arr[i]);
    // }

    // insertElementInArrr(vArr, 0, 10);
    // // cout<<ChechSorted(arr,5);

    return 0;
}