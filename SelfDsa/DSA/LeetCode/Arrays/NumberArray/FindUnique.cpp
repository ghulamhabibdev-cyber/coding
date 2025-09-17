#include<iostream>
using namespace std;
void FindUnque(int arr[],int size)
{
    int arrSizes[size]={0};
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
                if(arr[i]==arr[j])
                {
                    arrSizes[i]++;
                }
        }
    }
    int min=INT32_MAX;
    for(int i=0;i<size;i++)
    {
        if(arrSizes[i]<min)
        {
            min=i;
        }
    }
    cout<<"Unique"<<arr[min]<<endl;
    for(int i=0;i<size;i++)
    {
        cout<<arrSizes[i]<<endl;
    }
}
    // cout<<ArrayUnique(arr,5);
int ArrayUnique(int arr[],int n)
{
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans^=arr[i];

    }
    return ans;
}
int main()
{
    int arr[5]={2,10,10,3,3};
    // FindUnque(arr,5);
    cout<<ArrayUnique(arr,5);


}