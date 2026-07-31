#include<iostream>
using namespace std;
void TrianglePatteren()
{
    int n;
    cout<<"Enter Number : ";
    cin>>n;
    int i=0;
    while(i<n)
    {
        int j=0;
        while(j<=i)
        {
            cout<<"*";
            j++;
        }
        cout<<"\n";
        i++;
    }
    int n1;
    cout<<"Enter Number : ";
    cin>>n1;
    for(int i=0;i<=n1;i++)
    {
        for(int j=0;j<=i;j++)
        {
            cout<<"*";

        }
        cout<<"\n";

    }
    int n2;
    cout<<"3Enter No : ";
    cin>>n2;
    int k1=0;
     
    do{
        int k3=0;
        
        do{
            cout<<"*";
            k3++;

        }while(k3<=k1);
        cout<<"\n";
        k1++;
    }while(k1<=n2);
}
int main()
{
    TrianglePatteren();
    return 0;
}