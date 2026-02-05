#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits>
#include <list>
using namespace std;

class A
{
};
bool isPrime(int n)
{
    for(int i=2;i<=n/2;i++)
    {
        if(n%i==0)
        {
            return false;
        }
    }
    return true;
}
bool isNextPrime(int currPrime, int nextPrime)
{
    for (int i = currPrime + 1; i <nextPrime; i++)
    {
        if(isPrime(i))
        {
            return false;
        }
    }
    if(isPrime(nextPrime))
    {
        return true;
    }
    return false;
}
int main()
{
    int currPrime;
    int nextPrime;
    cin >> currPrime >> nextPrime;
    bool isPrime = isNextPrime(currPrime, nextPrime);
    if (isPrime)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}