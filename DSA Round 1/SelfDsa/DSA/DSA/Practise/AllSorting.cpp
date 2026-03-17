#include <iostream>
using namespace std;
void SelectionSort(int arr[],int size)
{
    // {23,4,23,54,1}
    for(int i=0;i<size;i++)
    {
        int index=i;
        for(int j=i+1;j<size;j++)
        {
            if(arr[j]<arr[index])
            {
                index=j;

            }
        }
        int temp=arr[i];
        arr[i]=arr[index];
        arr[index]=temp;
    }
}
void InsertionSort(int arr[],int size)
{
    for(int i=1;i<size;i++)
    {
    // {4,232,4,6,20}
        int temp=arr[i];
        int j=i-1;
        for(;i>=0;j--)
        {
            if(arr[j]>temp)
            {
                arr[j+1]=arr[j];
            }
            else
            {
                break;
            }
        }
        arr[j+1]=temp;
    }
}
void BubbleSort(int arr[],int size)
{
    for(int i=1;i<size;i++)
    {
        for(int j=0;j<size-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
int printArray(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<"\t";
    }
}
int main()
{

    int arr[9]={3,545,6,545,3,0,23,54,54};
    // SelectionSort(arr,8);
    // InsertionSort(arr,8);
    // BubbleSort(arr,8);
    printArray(arr,8);
}