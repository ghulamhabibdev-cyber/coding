#include <iostream>
using namespace std;
void PrintArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;
}
void SwapAlterNative(int arr[], int size)
{
    int temp = 0;
    if (size % 2 == 0)
    {
        for (int i = 0; i < size; i = i + 2)
        {
            temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }
    else
    {
        cout << "enter\n";
        for (int i = 0; i < size; i = i + 2)
        {
            temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
            if (i > size)
            {
                cout << "Breaking\n";
                break;
            }
        }
    }
    PrintArray(arr, size);
}
void SwapAlterNative2(int arr[], int size)
{
    for (int i = 0; i < size; i += 2)
    {
        if (i + 1 < size)
        {
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }
    PrintArray(arr, size);
}
void SwapTwo(int arr[], int n)
{
    for (int i = 0; i + 1 < n; i+=2)
    {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
    }
    PrintArray(arr, n);
}
int main()
{
    int arr[4] = {1, 2, 3, 4};
    int arr2[5] = {1, 2, 3, 4, 6};
    // SwapAlterNative(arr2, 5);
    // SwapAlterNative2(arr,4);
    // SwapAlterNative2(arr2,5);
    SwapTwo(arr, 4);
    SwapTwo(arr2, 5);

    return 0;
}