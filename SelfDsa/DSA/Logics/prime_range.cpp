#include<iostream>
using namespace std;
int main()
{
    int n;
    bool flag=true;
    cout<<"Enter range OF prime\n";
    cin>>n;
    for(int i=11;i<n;i++){
        for(int j=2;j<=9;j++){
            if(i%j==0){
                flag=false;
                break;
            }
            if(i%j!=0){
                flag=true;
            }
        }
        if(flag==true){
            cout<<i<<"\t";
        }
    }
}