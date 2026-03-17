#include <iostream>
using namespace std;
void InvertedTriangle();
int main()
{
    InvertedTriangle();
}
void InvertedTriangle()
{
    int n;
    cout<<"Enter A no : ";
    cin>>n;
    for(int i=n;i>0;i--)
    {
        for(int j=i;j>0;j--)
        {
            cout<<"*";
        }
        cout<<"\n";
        


}