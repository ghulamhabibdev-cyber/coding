#include<iostream>
using namespace std;
void Max()
{
    int arr[10]={12,13,23,23,23,23,23,2323,23,23};
    int max=arr[0];
    for(int i=0;i<sizeof(arr)/sizeof(arr[i]);i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }
    }
    cout<<"MAX OF ARRAY : "<<max<<endl;
}

void Min()
{
    int arr[10]={12,13,23,23,23,23,23,-2323,23,23};
    int min=arr[0];
    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
    {
        if(min>arr[i])
        {
            min=arr[i];
        }

    }
    cout<<"MIN OF ARRAY : "<<min<<endl;
    

}
int main()
{
    Max();
    Min();

}