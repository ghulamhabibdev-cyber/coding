#include<iostream>
using namespace std;
int partition(int arr[],int s,int e)
{
    // count total numbers less then pivot
    int pivot=arr[0];
    int cnt=0;
    for(int i=s+1;i<e;i++)
    {
        if(arr[i]<pivot)
        {
            cnt++;
        }
    }





    return pivotIndex;
}
void quickSort(int arr[],int s,int e)
{
    if(s>=e)
    {
        return ;
    }
    int p=partition(arr,s,e);
    quickSort(arr,s,p-1);
    quickSort(arr,p+1,e);
}
int main()
{
    int arr[15]={34,55,5,5,5,4,5,1,3,400,43,45,545,645,345};
    int n=15;
    quickSort(arr,0,n-1);
    return 0;
}
