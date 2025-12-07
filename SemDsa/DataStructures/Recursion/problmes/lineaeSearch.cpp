#include<iostream>
using namespace std;
int search(int arr[],int size,int key)
{
    if(size<0)
    {
        return -1;
    }
    if(key==arr[size-1])
    {
        return size-1;
    }
    return search(arr,size-1,key);

}
int main()
{
    int arr[5]={1,2,3,4,5};
    int n;
    cout<<"Enter a eleemt :0<=n<=5\n";
    cin>>n;
    int index=search(arr,5,n);
    if(index>=0)
    {
        cout<<arr[index]<<endl;
    }
    return 0;
}
