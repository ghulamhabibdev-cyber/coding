#include<iostream>
using namespace std;

int main()
{
    int arr[8]={21,4,3,545,656,43,32,34};
    int index=0;
    for(int i=0;i<8;i++)
    {
        int temp=arr[i];
        int j=i-1;
        while(j>=0)
        {
            if(arr[j]>temp)
            {
                arr[j+1]=arr[j];
            }else{
                break;
            }
            j--;
        }
        arr[j+1]=temp;
    }
    for(int i=0;i<8;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
