#include <iostream>
using namespace std;

class a{

};
int countDigigts(int n)
{
    int count=0;
    while(n!=0)
    {
        n/=10;
        count++;
    }
    return count;
}
bool checkArmstrong(int num)
{
    int n=num;
    int digits=countDigigts(n);
    int result=0;
    while(n!=0)
    {
        int rem=n%10;
        int ans=1;
        for(int i=0;i<digits;i++)
        {
            ans*=rem;
        }
        result+=ans;
        n/=10;

    }
    if(result==num)
    {
        return true;
    }
    return 0;
}
int main() {
    int number;
    cout<<"Enter a Number \n";
    cin>>number;
    // cout<<countDigigts(number);
    cout<<checkArmstrong(number);

    return 0;
}