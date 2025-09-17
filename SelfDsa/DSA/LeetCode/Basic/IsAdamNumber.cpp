#include<iostream>
using namespace std;
int RevNumber(int number)
{
    int ans=0;
    while (number!=0)
    {
        ans=(ans*10)+number%10;
        number/=10;

    }
    return ans;
    
}
int Square(int num){
    return num*num;
}
bool IsAdamNumber(int number)
{
    int numSqaure=Square(number);
    int rev=RevNumber(number);
    int revNumsqu=Square(rev);
    revNumsqu=RevNumber(revNumsqu);
    if(revNumsqu==numSqaure)
    {

        return true;
    }
    return false;
    
    
    
}
int main()
{

    int num;
    cout<<"Enterr number";
    cin>>num;
    bool yes=IsAdamNumber(num);
    if(yes==true)
    {
        cout<<num<< " : is Addam Number : \n";
    }
   
}