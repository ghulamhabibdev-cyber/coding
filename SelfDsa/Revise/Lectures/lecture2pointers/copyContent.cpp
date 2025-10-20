#include<iostream>
using namespace std;

int main()
{
    int arr[5]={32,34,43,43,434};
    int arr3[5];
    int * p1=arr;
    int * p3=arr3;
    for(int i=0;i<5;i++)
    {
       *(p3+i)=*(p1+i);
    }
    for(int i=0;i<5;i++)
    {
        cout<<arr3[i]<<" ";
    }
        return 0;
}
