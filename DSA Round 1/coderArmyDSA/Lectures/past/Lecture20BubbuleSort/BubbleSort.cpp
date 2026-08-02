#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

class A
{
};
void bubbleSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = n - 2; i >= 0; i--)
    {
        bool isSwaped = 0;
        for (int j = 0; j <= i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                isSwaped=1;
            }
        }
        if(!isSwaped)
        {
            break;
        }
    }
}
void bubleSort2(vector<int>&arr)
{
    int n=arr.size();
    for(int i=0;i<n-2;i++)
    {
           bool isSwaped = 0;
        for(int j=0;j<n-i-1;j++)
        {
             if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                isSwaped=1;
            }
        }
         if(!isSwaped)
        {
            break;
        }
    }
}
void bubbleSortDec(vector<int>&arr)
{
    int n=arr.size();
    for(int i=n-2;i>=0;i--)
    {
        for(int j=i;j>=0;j--)
        {
            if(arr[j]<arr[j+1])
            {
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
void bubleSort4(vector<int>&arr)
{
    int n=arr.size();
    for(int i=0;i<n-2;i++)
    {
        for(int j=n-i-2;j>=0;j--)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
template<typename T>
void printArray(vector<T>arr)
{
    int n=arr.size();
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{
    vector<int>vec={4,2,3,1,5};
    // bubbleSort(vec);
    // bubbleSort(vec);
    // bubbleSortDec(vec);
    bubleSort4(vec);
    printArray(vec);

    return 0;
}