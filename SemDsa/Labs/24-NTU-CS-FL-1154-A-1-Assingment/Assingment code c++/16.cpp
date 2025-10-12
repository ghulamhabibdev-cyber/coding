// Write a program to insert a new element at the beginning of a 1D array.
#include <iostream>
using namespace std;
void insertAtBegin(int arr[], int size, int data)
{
    for (int i = size; i >= 1; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = data;
}
void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    const int size = 10;
    int arr[size] = {323, 434, 545};
    printArr(arr, size);
    insertAtBegin(arr,size,34);
    insertAtBegin(arr, size, 349);
    printArr(arr, size);
    return 0;
}
