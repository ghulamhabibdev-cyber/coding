#include<iostream>
using namespace std;
void FibonachiSeries()
{
    int n;
    cout<<"Enter Number : ";
    cin>>n;
    int a=0;
    int b=1;
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        sum=sum+a;
        cout<<sum<<endl;
        a=b;
        b=sum;
        if(sum==n)
        {
            break;
        }

        
    }
}
int main()
{
    FibonachiSeries();
}