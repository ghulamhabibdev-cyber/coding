#include <bits/stdc++.h>
using namespace std;
int sumOfArray(int *arr,int size)
{
    if(size==0)
    {
        return 0;
    }
    int sum=0;
    sum+=arr[0];
    sum=sum+sumOfArray(arr+1,size-1);
    return sum;
}
int main()
{
  int arr[100];
  for(int i=1;i<=100;i++)
  {
    arr[i-1]=i;
  }
  cout<<sumOfArray(arr,100);
    return 0;
}
