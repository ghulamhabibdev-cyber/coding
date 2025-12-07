// Write a program to insert a new element at the end of a dynamically allocated array using realloc().
#include <iostream>
using namespace std;
void insertLast(int arr[], int &size, int data)
{
    size+=1;
    arr = (int *)realloc(arr, (size) * sizeof(int));
    arr[size-1] = data;
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
    int size;
    cout << "Enter the Size \n";
    cin >> size;
    int *arr = (int *)malloc(size * sizeof(int));
    insertLast(arr, size, 34);
    insertLast(arr, size, 43);
    insertLast(arr, size, 545);
    insertLast(arr, size, 4344);
    insertLast(arr, size,434);
    insertLast(arr, size,45435);
    printArr(arr, size);

    return 0;
}
