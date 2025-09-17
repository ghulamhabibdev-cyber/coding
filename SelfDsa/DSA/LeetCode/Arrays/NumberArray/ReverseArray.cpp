#include <iostream>
using namespace std;
void ReverseArray(int arr[], int size,int m)
{
    int temp;
    int runner = m+1;
    int handle = size-1;
    for (int i = m+1; i < size; i++)
    {
        temp = arr[handle ];
        arr[handle] = arr[i];
        arr[i] = temp;
        handle--;
        if (handle == runner)
        {
            break;
        }
    }
    // for (int i = 0; i < size; i++)
    // {
    //     cout << arr[i] << "\t";
    // }
    cout << endl;
}
void PrintArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}
// int ReturnSizeOfArray(int arr[])
// {
    
//     int size=sizeof(arr)/sizeof(int);
//     return size;
// }
void BuiltInSwapReverseArray(int arr[],int size,int m)
{
    int start=m+1;
    int end=size-1;
    while (start<=end)
    {
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
    // for(int i=0;i<size;i++)
    // {
    //     cout<<arr[i]<<"\t";
    // }
   
    
}
int main()
{
    int arr[6] = {1, 2, 3, 4, 5, 6};
    ReverseArray(arr, 6,2);
    PrintArray(arr, 6);
    // ReverseArray(arr, 6);
    // BuiltInSwapReverseArray(arr,6,2);
    //  cout<<ReturnSizeOfArray(arr);
    // PrintArray(arr, 6);
    return 0;
}