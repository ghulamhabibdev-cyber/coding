#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

class A {
};
void insertSort2(vector<int>&arr)
{
    int n=arr.size();
    for(int i=1;i<n;i++)
    {
        for(int j=i;j>0;j--)
        {
            if(arr[j]<arr[j-1])
            {
                swap(arr[j],arr[j-1]);
            }
            else{
                break;
            }
        }
    }
}
void insertionSort(vector<int>&arr)
{
    int n=arr.size();
    for(int i=0;i<n;i++)
    {
        int temp=arr[i];
        int j=i-1;
        for(;j>=0;j--)
        {
            if(arr[j]>temp)
            {
                arr[j+1]=arr[j];
            }
            else{
                break;
            }
        }
        arr[j+1]=temp;
    }
}
void printArr(vector<int>arr)
{
    int n=arr.size();
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
void practiseInsertionSort(vector<int>&arr)
{
    int n=arr.size();
    for(int i=1;i<n;i++)
    {
        int temp=arr[i];
        int j=i-1;
        while(j>=0)
        {
            if(arr[j]>temp)
            {
                arr[j+1]=arr[j];
                j--;
            }
            else{
                break;
            }
        }
        arr[j+1]=temp;
    }
}
int main() {
    vector<int>arr={7,4,6,3,1,9,2,0};
    // insertSort2(arr);
    practiseInsertionSort(arr);
    printArr(arr);

    
    return 0;
}