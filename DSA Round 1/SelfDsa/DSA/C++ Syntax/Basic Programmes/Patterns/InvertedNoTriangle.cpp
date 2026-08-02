#include<iostream>
using namespace std;
void InvertedNoTriangle()
{
    int n;
    cout<<"Enter no : ";
    cin>>n;
    int i=n;
    while (i>0)
    {
        int j=1;
        while (j<=i)
        {
            cout<<j<<" ";
            j++;
            /* code */
        }
        cout<<"\n";
        i--;
        
        /* code */
    }

    
}
int main()
{
    InvertedNoTriangle();
}