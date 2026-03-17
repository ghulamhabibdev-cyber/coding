#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n=5;
    int i=1;
    int evenSum=0;
    int oddSum=0;
    while(i<=n)
    {
        if(i%2==0)
        {
            evenSum+=i;
        }else{
            oddSum+=i;
        }
        i++;
    }
    cout<<"Odd sum : "<<oddSum<<endl;
    cout<<"Even SUm : "<<evenSum<<endl;
    return 0;
}
