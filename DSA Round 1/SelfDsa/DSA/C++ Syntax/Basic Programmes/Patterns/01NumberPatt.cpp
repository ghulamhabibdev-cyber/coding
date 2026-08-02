#include<iostream>
using namespace std;
void Patern(){
    int n;
    cout<<"Enter A Number ";
    cin>>n;
    int n1=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<n1<<"  ";
            n1++;
                 
        }
        cout<<endl;
        
    }
}
int main()
{
    Patern();
    return 0;
}