#include<iostream>
using namespace std;
void PositvieAndNegativeCounter()
{
    int arr[10];
    int size=sizeof(arr)/sizeof(arr[0]);
    int negCounter=0;
    int posCounter=0;

    for(int i=0;i<size;i++)
    {
        cout<<"Enter Number : "<<endl;
        cin>>arr[i];
        if(arr[i]>0){
            posCounter++;
        }
         if(arr[i]<0)
        {
            negCounter++;
        }
    }
    cout<<"Positive Counter : "<<posCounter<<endl;
    cout<<"Negative Counter : "<<negCounter<<endl;
}
int main()
{
    PositvieAndNegativeCounter();
    return 0;
}