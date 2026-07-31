#include<bits/stdc++.h>
using namespace std;
void swapAlternative(int arr[],int size)
{
    int pos1=0;
    int pos2=1;
    // while(pos2<=size-1)
    // {
    //     int temp=arr[pos1];
    //     arr[pos1]=arr[pos2];
    //     arr[pos2]=temp;
    //     pos1+=2;
    //     pos2+=2;
    // }
    for(int i=0;i<size;i+=2)
    {
        if(i+1<size)
        {
            swap(arr[i],arr[i+1]);
        }
    }
}
void printArr(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<< " ";
    }
}
int main()
{
    int arr[6]={1,2,3,4,5,6};
    swapAlternative(arr,6);
    printArr(arr,6 );
    return 0;
}
