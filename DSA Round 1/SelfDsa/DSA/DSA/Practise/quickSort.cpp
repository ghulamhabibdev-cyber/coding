#include <bits/stdc++.h>
using namespace std;
int partision(int arr[],int s,int e)
{
    int pivot=arr[s];
    int cnt=0;
    for(int i=s+1;i<=e;i++)
    {
        if(arr[i]<=pivot)
        {
            cnt++;
        }
    }
    int pivotidex=s+cnt;
    swap(arr[pivotidex],arr[s]);
    int i=s;int j=e;
    while (i<pivotidex&&j>pivotidex)
    {
        while (arr[i]<pivot)
        {
            i++;
            /* code */
        }
        while (arr[j]>pivot)
        {
            j--;
            /* code */
        }
        if(i<pivotidex&&j>pivotidex)
        {
            swap(arr[i++],arr[j--]);
        }
        
        
        /* code */
    }
    return pivotidex;

}
void quickSort(int arr[],int s,int e)
{
    if(s>=e)
    {
        return ;
    }
    int p=partision(arr,s,e);

    quickSort(arr,s,p-1);
    quickSort(arr,p+1,e);
}
int main()
{
    int n=5;
  int arr[n]={2,3,3,1,6};
  quickSort(arr,0,n-1);
  for(int i=0;i<n;i++)
  {
    cout<<arr[i]<<endl;
  }
    return 0;
}