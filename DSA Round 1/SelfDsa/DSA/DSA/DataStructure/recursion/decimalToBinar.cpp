#include <bits/stdc++.h>
using namespace std;
int DecimalToBinary(int number)
{
    if(number==0)
    {
        return 0;
    }
    
   
   
    int ans=number%2;
    
    
    ans=ans+DecimalToBinary(number/2);
   
    return ans*10;


}
int main()
{
  cout<<DecimalToBinary(10);
    return 0;
}