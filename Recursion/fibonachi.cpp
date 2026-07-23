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
int fib(int n)
{
    if (n <= 1)
    {
        return n;
    }
    int ans = fib(n - 1) + fib(n - 2);
    return ans;
}
int main()
{
    cout << fib(5) << endl;
    return 0;
}