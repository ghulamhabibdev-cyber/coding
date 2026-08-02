#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;
string ReturnReverseNo(int num)
{
    int i=0;
    char digits[20];
    string number="";
    if(num==0)
    return 0;
    int rem;
    while (num!=0)
    {
        rem=num%10;
        digits[i]='0'+rem;
        i++;
        num=num/10;
       
    }
    for(int dig=0;dig<i;dig++)
    {
        number+=digits[dig];
    }
 
    return number;
    
}
int main()
{
   cout<<ReturnReverseNo(150);

    
}