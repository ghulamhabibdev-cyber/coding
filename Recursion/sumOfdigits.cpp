#include <iostream>
using namespace std;

class A
{
};
int sum(int n)
{
    if (n <= 9)
    {
        return n;
    }
    int d = n % 10;
    n = n / 10;
    int ans = sum(n);
    ans = ans + d;
    return ans;
}
int main()
{
    int n = 434;
    cout << sum(n) << endl;
    return 0;
}