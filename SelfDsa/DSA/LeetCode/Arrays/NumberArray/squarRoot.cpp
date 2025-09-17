#include<iostream>
using namespace std;
int SquareRoot(int n)
{
    int start=0;
    int end=n;
    int ans=-1;
    long long int mid=start+(end-start)/2;
    while (start<=end)
    {
        long long int  sqaure=mid*mid;
        if(sqaure==n)
        {
            return mid;
        }
        if(sqaure<n)
        {
            ans=mid;
            start=mid+1;
        }
        else{
            end=mid-1;
        }
        mid=start+(end-start)/2;
    }
    return ans;

}
double MorePreciseSquare(int n,int precision,int temp)
{
    double factor=1;
    double ans=temp;
    for(int i=0;i<precision;i++)
    {
        factor=factor/10;
        for(double j=ans;j*j<n;j+=factor)
        {
            ans=j;
        }
    }
    return ans;
}
int main()
{
    int n;
    cout<<"Entet Number : \n";
    cin>>n;
    int temp=SquareRoot(n);
    cout<<temp<<endl;
    cout<<MorePreciseSquare(n,5,temp);

}