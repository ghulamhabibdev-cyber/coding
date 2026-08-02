#include<iostream>
using namespace std;
void NoDivisibilities()
{
    int n;
    int n1;
    cout<<"Enter Number "<<endl;
    cin>>n;
    cout<<"Enter Number2 "<<endl;
    cin>>n1;
    for(int i=1;i<=100;i++)
    {
        if(i%n==0 &&i%n1==0)
        {
            cout<<i<<endl;
        }
    }
}
int main()
{

    NoDivisibilities();
    return 0;
}