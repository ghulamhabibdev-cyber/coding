#include <iostream>
using namespace std;
void insertBegin(int arr[], int size, int data)
{
    for (int i = size - 1; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = data;
}

void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "  ";
    }
}
int main()
{
    int arr[5];
    insertBegin(arr, 5, 90);
    insertBegin(arr, 5, 40);
    insertBegin(arr, 5, 30);
    insertBegin(arr, 5, 20);
    print(arr, 5);
    return 0;
}
