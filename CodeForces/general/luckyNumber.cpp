#include <iostream>
using namespace std;

class A
{
};
bool isLucky(int n)
{
    if(n==0)
    {
        return false;
    }
    while(n>0)
    {
        int d=n%10;
        if(d!=4&&d!=7)
        {
            return false;
        }
        n/=10;
    }
    return true;
}
int main()
{
    long long  num;
    cin >> num;
    long long count = 0;
    while (num > 0)
    {
        int dig = num % 10;
        if (dig == 4 ||dig == 7)
        {
            count++;
        }
        num/=10;
    }
    if (isLucky(count))
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}