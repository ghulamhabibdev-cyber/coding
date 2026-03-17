#include<iostream>
using namespace std;
int* myarr(int size){
    static int arr[5]={12,23,23,23,4};
    
    return arr;
}
int main()
{
    int size=5;
    int *arr= myarr(size);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<endl;
    }
}