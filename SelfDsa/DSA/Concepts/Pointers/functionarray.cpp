#include<iostream>
using namespace std;
void print(int *p)
{
    *p+=4;
    cout<<p<<endl;
}
void Update(int *ptr)
{
    *ptr+=10;
    cout<<" udated : "<<(*ptr)<<endl;
}
void updateAdree(int *p)
{
    p=p+1;
    cout<<"P : in function : "<<p<<endl;
}
int getSum(int *arr,int n){
    cout<<"size ;;;;: "<<sizeof(arr)<<endl;
   int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];


    }
    return sum;
}
int main()
{
    // int i=4;
    // int *p=&i;
    // cout<<"P : add"<<p<<endl;
    // print(p);
    // cout<<"Now check me i=9 : "<<i<<endl;
    // Update(&i);
    // print(p);
    //  cout<<"Now check me i=9 : "<<i<<endl;
    //  updateAdree(p);
    //  cout<<p<<endl;
    int arr[6]={1,2,3,4,5,6};

    cout<<getSum(arr+3,3);
}