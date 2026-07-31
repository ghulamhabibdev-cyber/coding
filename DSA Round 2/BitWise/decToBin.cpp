#include <iostream>
using namespace std;

class A {
};
int binaryToDecimal(int n)
{
    int ans=0;
    int pow=1;
    while(n>0)
    {
        int rem=n%2;
        n/=2;
        ans+=rem*pow;
        pow*=10;
    }
    return ans;
}
int main() {
    int decimalNumber;
    cin>>decimalNumber;
    cout<<binaryToDecimal(decimalNumber)<<endl;
    cout<<endl;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<binaryToDecimal(i)<<endl;
    }
    
    return 0;
}