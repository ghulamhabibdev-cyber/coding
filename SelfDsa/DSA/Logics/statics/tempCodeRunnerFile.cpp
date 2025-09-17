#include<iostream>
#include<vector>
#include <iterator>
using namespace std;
void SortDataSet(int arr[],int len){
    
    cout<<len<<"Size is |\n";
    int temp;
    for(int i=0;i<len-1;i++)
    {for(int j=0;j<len-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;

            }

        }

    }
    for(int i=0;i<len;i++)
    {
        cout<<arr[i]<<"\t";
    }
}
int main()
{
    int arr[5]={12,34,54,45,34};
    int len=sizeof(arr)/sizeof(arr[0]);
    SortDataSet(arr,len);

}

