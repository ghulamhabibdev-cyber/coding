#include <iostream>
using namespace std;
void print(int arr[], int s, int e)
{
    for (int i = s; i <= e; i++)
    {
        cout << arr[i] <<" ";
    }
    cout<<endl;
}
int binarySearch(int arr[], int s, int e, int key)
{
    print(arr, s, e);
    if (s > e)
    {
        return -1;
    }
    int mid = s + (e - s) / 2;
    if (arr[mid] == key)
    {
        return mid;
    }
    if (arr[mid] < key)
    {
        return binarySearch(arr, mid + 1, e, key);
    }
    else
    {
        return binarySearch(arr, s, mid - 1, key);
    }
}
int main()
{
    int arr[7] = {12, 23, 34, 45, 56, 67, 78};
    int s = 0;
    int e = 6;
    int key = 78;
    int index = binarySearch(arr, s, e, key);
    if (index >= 0)
    {
        cout << "Element at index  :  " << arr[index] << endl;
    }
    return 0;
}
