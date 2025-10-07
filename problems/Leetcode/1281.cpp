#include<bits/stdc++.h>
using namespace std;

int productOfDigit(int number)
{
    int prod = 1;
    while (number != 0)
    {
        int digit = number % 10;
        prod *= digit;
        number = number / 10;
    }
    return prod;
}
int sumOfDigit(int number)
{
    int sum = 0;
    while (number != 0)
    {
        int digit = number % 10;
        sum += digit;
        number = number / 10;
    }
    return sum;
}
int subtractProductAndSum(int n)
{
    int prod = productOfDigit(n);
    int sum = sumOfDigit(n);
    int ans = prod - sum;
    return ans;
}
int main()
{
    
}
