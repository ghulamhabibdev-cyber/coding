#include <iostream>
using namespace std;
int peakElement(int arr, int size)
{
    int s = 0;
    int e = size - 1;
    int mid = s + (e - s) / 2;
    while (s < e)
    {
        if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
        {
            return mid;
        }
        if()
    }
}
int SearchingRotatedShortedArray(int arr[], int size, int key)
{
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start) / 2;
    while (start < end)
    {
        mid = start + (end - start) / 2;
        if (key == arr[mid])
        {
            return mid;
        }

        else if (key > arr[mid])
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return -1;
}
int main()
{
    int arr[7] = {4, 5, 6, 7, 0, 1, 2};
    cout << SearchingRotatedShortedArray(arr, 7, 0);
}