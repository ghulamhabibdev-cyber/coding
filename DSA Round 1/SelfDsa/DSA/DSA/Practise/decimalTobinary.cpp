#include <iostream>
using namespace std;
void DecimalToBianry(int x)
{
    int rem=0;
        int ans=1;
        int ten=10;
    while (x>1)
    {
        rem=x%2;
     ans=ans*ten+rem;  
     x/=2;
     ten=10;
    }
    cout<<ans<<endl;
    

}
int main()
{
     DecimalToBianry(20);
}