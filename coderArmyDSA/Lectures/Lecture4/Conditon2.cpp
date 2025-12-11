#include <iostream>
using namespace std;

class a{

};
bool checkPass(int n)
{
    if(n>33)
    {
        return 1;
    }
    return 0;
}
bool checkBigNum(int num1,int num2)
{
    if(num1>num2)
    {
        return true;
    }
    return false;
}
bool checkEven(int number)
{
    if(number%2==0)
    {
        return 1;
    }
    return 0;
}
int main() {
    // int package;
    // cout<<"Enter package \n";
    // cin>>package;
    // if(package>10)
    // {
    //     cout<<"Accepted \n";
    // }
    // else{
    //     cout<<"Rejected \n";
    // }



    // int marks;
    // cout<<"Enter your marks\n";
    // cin>>marks;
    // if(checkPass(marks))
    // {
    //     cout<<"Pass \n";
    // }
    // else{
    //     cout<<"Fail \n";
    // }



    // int a,b;
    // cout<<"Enter number \n";
    // cin>>a;
    // cout<<"Enter Number \n";
    // cin>>b;
    // if(checkBigNum(a,b))
    // {
    //     cout<<"Yes \n";
    // }
    // else
    // cout<<"No\n";
    int n;
    cout<<"Enter Number \n";
    cin>>n;
    if(checkEven(n))
        cout<<"Even\n";
    else
        cout<<"Odd\n";
    return 0;
}