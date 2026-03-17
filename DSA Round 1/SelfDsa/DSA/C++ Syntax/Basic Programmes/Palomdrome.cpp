#include<iostream>
using namespace std;
void PalindromeChecker()
{
    int number;
    cout<<"Enter Number : "<<endl;
    cin>>number;
    int temp=number;
    int remind;
    int n=0;
    
    while (number!=0)
    {
        remind=number%10;
        n=n*10+remind;
        number=number/10;
    }
    if(temp==n)
    {
        cout<<temp<< " Is Palindrome "<<endl;
    }
    
}
int main()
{

    PalindromeChecker();

    return 0;
}