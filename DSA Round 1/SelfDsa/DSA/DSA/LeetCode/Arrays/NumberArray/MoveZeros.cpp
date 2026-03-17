#include<iostream>
using namespace std;
void moveZeros(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if(arr[i]==0 && arr[i]!=arr[j])
            {
                int temp=arr[j];
                arr[j]=arr[i];
                arr[i]=temp;

            }
        }
    }
}
void moveZeros2(int arr[],int size)
{
    int i=0;
    for(int j=0;j<size;j++)
    {
        //  int arr[7]={ 2,3,4,5,0,0,0};
        if(arr[j]!=0)
        {
            int temp=arr[j];
            arr[j]=arr[i];
            arr[i]=temp;
            i++;
        }
        
    }
}
void PrintArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}
int main()
{
    int arr[7]={ 0,2,3,4,0,0,5};
    // moveZeros(arr,7);
    moveZeros2(arr,7);
    PrintArray(arr,7);
}