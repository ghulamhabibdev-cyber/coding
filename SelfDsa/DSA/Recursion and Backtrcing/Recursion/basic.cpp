#include <iostream>
using namespace std;
void recurin(int n)
{
    if (n >= 5)
    {
        cout << "I am at base condiont  : " << n << endl;
        return;
    }
    if (n == 3)
    {
        cout << "I ==== the case " << endl;
    }
    recurin(n + 1);
    // recurin(n - 1);
    cout << "Value of  n    : " << n << endl;
    cout << "I am at that n : " << n << endl;
    return;
}
int sum(int n)
{
    if (n == 0)
    {
        return 0;
    }
    int ans = n + sum(n - 1);

    return ans;
}
int fact(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    int ans = n * fact(n - 1);
    return ans;
}
int fib(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    int ans = fib(n - 1) + fib(n - 2);
    return ans;
}
int arrSum(int arr[],int n)
{
    if(n==0)
    {
        return 0;
    }
    int ans=arrSum(arr,n-1)+arr[n-1];
    return ans;
}
int main()
{
    // recurin(0);
    // cout<<sum(5)<<endl;;
    // cout<<fact(5)<<endl;
    // cout << fib(6) << endl;
    int arr[5]={100,200,300,400,500};
    int n=5;
    cout<<arrSum(arr,n)<<endl;
    return 0;
}
