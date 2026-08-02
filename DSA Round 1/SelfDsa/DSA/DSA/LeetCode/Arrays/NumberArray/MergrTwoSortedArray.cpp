#include <iostream>
using namespace std;
void merge(int arr[], int n, int arr2[], int m,int arr3[])
{
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < n && j < m)
    {
        if(arr[i]<arr2[j])
        {
            arr3[k++]=arr[i++];
         
        }
        else{
             arr3[k++]=arr2[j++];
             
        }
        /* code */
    }
    while (i<n)
    
    {
        arr3[k++]=arr[i++];
        

        /* code */
    }
     while (j<m)
    
    {
        arr3[k++]=arr2[j++];
        ;
        
        /* code */
    }
    
}
int main()
{

    int arr[5]={1,2,3,5,7};
    int arr2[3]={4,6,8};
    int a[8];
    merge(arr,5,arr2,3,a);
    for(int i=0;i<8;i++)
    {
        cout<<a[i]<<"\t";
    }
    return 0;
}