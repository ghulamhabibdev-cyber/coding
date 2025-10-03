#include <bits/stdc++.h>
using namespace std;
int sumOfDigits(int n)
{
    if (n == 0)
    {
        return 0;
    }
    int sum =0;
    sum+= n % 10;
    sum=sum+sumOfDigits(n/10);
    return sum;
   
}
int main()
{
    cout<<sumOfDigits(3451);
    return 0;
}
