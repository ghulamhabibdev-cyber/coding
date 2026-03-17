// Write a program to perform deletion operations in an array : (a)Delete the first element(b)
// Delete an element from a specific position(c)
// Delete the last element
#include <iostream>
using namespace std;
void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void delFromStart(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    arr[n - 1] = 0;
}
void delFromPosition(int arr[], int size, int pos)
{
    if (pos < 0 || pos > size)
    {
        cout << "Wrong Position \n";
        return;
    }
    else
    {
        for (int i = pos - 1; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        arr[size - 1] = 0;
    }
}
void delFromEnd(int arr[], int size)
{
    for (int i = size - 1; i >= 1; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = 0;
}
int main()
{
    int arr[7] = {1, 2, 3, 4, 5, 6, 7};
    cout << "===============Delete from start===============\n";
    delFromStart(arr, 7);
    delFromStart(arr, 7);
    printArr(arr, 7);
    cout << "===============Delete from Pos==============\n";
    delFromPosition(arr, 7, 3);
    printArr(arr, 7);
    delFromEnd(arr, 7);
    delFromEnd(arr, 7);
    printArr(arr, 7);

    return 0;
}
