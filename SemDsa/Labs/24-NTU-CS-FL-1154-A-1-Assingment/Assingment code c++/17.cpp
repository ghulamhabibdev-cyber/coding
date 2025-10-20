// Write a program to insert a new element at a specific position (in between) in a 1D array.
#include<iostream>
using namespace std;
void insertAtPos(int arr[],int size,int pos,int data)
{
    if(pos<0||pos>=size)
    {
        cout<<"Wrong position\n";
        return ;
    }
    arr[pos]=data;
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
    const int size=5;
    int arr[size]={34,34,23,43};
    printArr(arr,size);
    insertAtPos(arr,size,4,3000);
    printArr(arr, size);

    return 0;
}
