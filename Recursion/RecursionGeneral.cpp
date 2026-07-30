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
int fib1(int n)
{
    if (n <= 1)
    {
        return n;
    }
    int ans = fib1(n - 2) + fib1(n - 1);
    return ans;
}
int getNumber()
{
    int number;
    cout << "Enter A Number " << endl;
    cin >> number;
    return number;
}
int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    // int rem = a % b;
    // cout << "Rem : " << rem << endl;
    int ans = gcd(b, a % b);
    return ans;
}
int loopGcd(int a, int b)
{
    while (b != 0)
    {
        int rem = a % b;
        a = b;
        b = rem;
    }
    return a;
}
int main()
{
    // int number=getNumber();
    // int ans=fib1(number);
    // cout<<"fib ans for "<<number<<" : "<<ans<<endl;

    int a = 4;
    int b = 8;
    cout << gcd(a, b) << endl;
    // cout<<
    cout << "Gcd : " << loopGcd(a, b);

    return 0;
}