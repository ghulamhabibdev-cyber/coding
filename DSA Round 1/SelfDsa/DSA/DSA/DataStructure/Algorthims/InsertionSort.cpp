#include<iostream>
using namespace std; 
void printArray(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<"\t";
    }
}
void insertionSort(int arr[],int size)
{
    // {4,232,4,6,20}
    for(int i=1;i<size;i++)
    {
        int temp=arr[i];
        int j=i-1;
        for(;j>=0;j++)
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
int main()
{
    return 0;
}
