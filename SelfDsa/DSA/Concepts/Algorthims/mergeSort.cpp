#include <bits/stdc++.h>
using namespace std;
void merge(int arr[], int s, int e)
{
    int mid = s + (e - s) / 2;
    int len1=mid+s+1;
    int len2=e-mid;
    int *firt=new  int[len1];
    int *second=new int[len2];
    int mainArr=s;
    for(int i=0;i<len1;i++)
    {
        firt[i]=arr[mainArr++];
    }
    mainArr=mid+1;
    for(int i=0;i<len2;i++)
    {
        second[i]=arr[mainArr++];
    }
    int index1=0;
    int index2=0;
    mainArr=s;
    while (index1<len1&&index2<len2)
    {
        if(firt[index1]<second[index2])
        {
            arr[mainArr++]=firt[index1++];
        }
        else{
            arr[mainArr++]=second[index2++];
        }
        /* code */
    }
    while (index1<len1)
    {
        arr[mainArr++]=firt[index1++];

        /* code */
    }
    while (index2<len2)
    {
        arr[mainArr++]=second[index2++];
        /* code */
    }
    
    
}
void mergeSort(int *arr, int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int mid = s + (e - s) / 2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);
    merge(arr, s, e);
}
int main()
{

    int arr[5]={1,32,45,45,5};
    mergeSort(arr,0,4);
    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<endl;
    }
    return 0;
}