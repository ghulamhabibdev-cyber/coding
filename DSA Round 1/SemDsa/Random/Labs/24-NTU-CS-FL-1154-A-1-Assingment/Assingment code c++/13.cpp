// Write a program to copy the contents of one array into another using pointers
#include <iostream>
using namespace std;

int main()
{
    int arr[5] = {323, 434, 545, 545, 34};
    int *arrPtr = arr;
    int arr2[5];
    cout<<"============Copy The Data=============\n";
    for (int i = 0; i < 5; i++)
    {
        arr2[i] = (arrPtr[i]);
    }
    cout<<"================Displaying the Data ====================\n";
    for (int i = 0; i < 5; i++)
    {
        cout << arr2[i] << " ";
    }

    return 0;
}
