#include <bits/stdc++.h>
using namespace std;
void selectionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}
void selectSort(vector<int>&arr)
{
    int n=arr.size();
    int i=0;
    while(i<n-1)
    {
        int minIndex=i;
        int j=i+1;
        while(j<n)
        {
            if(arr[j]<arr[minIndex])
            {
                minIndex=j;
            }
            j++;
        }
        swap(arr[i],arr[minIndex]);
        i++;
    }
}
template <class Type>
void printVector(vector<Type> arr)
{
    for (Type n : arr)
    {
        cout << n << " ";
    }
}
int main()
{
    vector<int> arr = {23, 4, 23, 43, 5, 3, 2, 1, 434, 545, 34, 32, 2, 13, 45, 6, 76, 4, 89, 11, 21, 12, 13, 14};
    // selectionSort(arr);
    selectSort(arr);
    printVector(arr);
    return 0;
}
