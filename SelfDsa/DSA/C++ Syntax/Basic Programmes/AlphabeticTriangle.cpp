#include<iostream>
using namespace std;
void AlphabeticTrianle();
int main()
{

    AlphabeticTrianle();
    return 0;
}
void AlphabeticTrianle()
{
    int n;
    cout<<"Enter a Number : ";
    cin>>n;
    char a='A';
    int i=1;
    while(i<=n)
    {
        int j=1;
        while(j<=i)
        {
            cout<<a<<" ";
            
            j++;
        }
        i++;
        a++;
        cout<<"\n";
    }
}