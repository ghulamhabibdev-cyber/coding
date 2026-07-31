#include <iostream>
using namespace std;
int power(int a, int b)
{
    if (b == 0)
    {
        return 1;
    }
    if (b == 1)
    {
        return a;
    }
    int ans = power(a, b / 2);
    if (b % 2 == 0)
    {
        return ans * ans;
    }
    else
    {
        return a * ans * ans;
    }
}
void bubleSort(int arr[], int size)
{
    if (size == 0 || size == 1)
    {
        return;
    }
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
        }
    }
    bubleSort(arr, size - 1);
}
void insertionSort(int arr[], int size)
{
    if (size <= 1)
    {
        return;
    }
    insertionSort(arr, size - 1);
    // now alway this is end at 2
    int last = arr[size - 1]; // this give you at end index 1
    int j = size - 2;
    while (j >= 0 && arr[j] > last)
    {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = last;
}
int findMinIndex(int arr[], int start, int size)
{
    int minIndex = start;
    for (int i = start + 1; i < size; i++)
    {
        if (arr[i] < arr[minIndex])
        {
            minIndex = i;
        }
    }
    return minIndex;
}
void selectionSort(int arr[], int start, int size)
{
    if (start >= size - 1)
    {
        return;
    }
    int minIndex = findMinIndex(arr, start, size);
    swap(arr[start], arr[minIndex]);
    selectionSort(arr, start + 1, size);
}
int main()
{
    int a, b;
    // cin >> a >> b;
    // int ans = power(a, b);
    // cout << ans << endl;
    int arr[] = {5, 3, 8, 4, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    // bubleSort(arr, size);
    // insertionSort(arr,size);
    selectionSort(arr, 0, size);

    cout << "Sorted array: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
