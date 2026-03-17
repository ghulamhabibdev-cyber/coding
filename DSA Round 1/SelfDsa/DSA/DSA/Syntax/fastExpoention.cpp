#include <iostream>
using namespace std;
int fastExponention(int x,int n,int m)
{
    
    int result=1;
    while (n>0)
    {
      if(n&1)
      {
        result=(result)%m*((x)%m)%m;
      }
      x=((x)%m*(x)%m)%m;
      n=n>>1;
    }
 return result;   
}
int main()
{
    cout<<(10>>1);
    cout<<fastExponention(2,3,1);

}