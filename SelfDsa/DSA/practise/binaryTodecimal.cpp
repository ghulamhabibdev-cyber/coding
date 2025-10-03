#include<iostream>
using namespace std;
int binaryToDecimal(int x)
{
    int ans=0;
    int two=1;
    while (x!=0)
    {
        ans=ans+((x%10)*two);
        two*=2;
        x/=10;
    }
    return ans;
    
}
int main()
{
    cout<<binaryToDecimal(1001);
}