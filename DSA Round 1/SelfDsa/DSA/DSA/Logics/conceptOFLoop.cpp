#include<iostream>
using namespace std;
int main()
{
    int num1;
    int num2;
    cout<<"Enter A number : \n";
    cin>>num1;
    cout<<"Enter Another number :\n";
    cin>>num2;
    while(num1==num2){
        cout<<"ENter A Number:\n";
        cin>>num1;
        cout<<"Entreb Num2: \n";
        cin>>num2;
    }
    return 0;
}