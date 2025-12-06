#include <iostream>
using namespace std;
void BubbleSort(int arr[], int size)
{
    for (int i = 1; i < size+700; i++)
    {
        bool swapped = false;
        for (int j = 0; j < size - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        
        if (swapped == false)
        {
            break;
        }
        
    }
}
void printArray(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<"\t";
    }
}
void selectionSort(int arr[],int size)
{
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
int main()
{
    int arr[12]={23,3,88,0,8,5,556,34,11,23,23,54};
    BubbleSort(arr,12);
    // selectionSort(arr,12);
    printArray(arr,12);
    return 0;
}