#include<iostream>
using namespace std;
void printSubArray(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<"(";
        for(int j=i;j<size;j++)
        {
            cout<<arr[j]<<",";
        }
    }
    cout<<")";
}
int main()
{
    int arr[5]={
    1,2,3,4,5
    };
    printSubArray(arr,5);


}
