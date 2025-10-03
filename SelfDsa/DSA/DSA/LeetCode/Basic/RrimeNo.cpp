#include <iostream>
using namespace std;
bool IsPrime(int n)
{
    for (int i = 2; i < n / 2; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
void PrintRangePrime(int range)
{
    bool isPrime=true;
    for(int i=1;i<=range;i++)
    {
        for(int j=2;j<=i/2;j++)
        {
            if(i%j==0)
            {
                isPrime=false;
                break;

            }
            else{
                isPrime=true;
            }

        }
        if(isPrime==true)
        {
            cout<<i<<endl;
        }
    }
}
int main()
{
    // cout << IsPrime(6) << endl;
    // cout << IsPrime(7) << endl;
    // cout << IsPrime(5) << endl;
    // cout << IsPrime(100) << endl;
    // cout << IsPrime(17) << endl;
    PrintRangePrime(100);
}