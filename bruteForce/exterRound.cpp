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
int nextTenMultiple(int n)
{
    int ans = 1;
    while (ans <= n)
    {
        ans *= 10;
    }
    return ans / 10;
}
int findTotalExtreme(int n)
{
    if (n <= 9)
    {
        return n;
    }
    int count = 9;
    int num = 10;
    int nextMulitple = nextTenMultiple(n);
    int diff = n / nextMulitple;
    while (num != nextMulitple)
    {
        count += 9;
        num *= 10;
    }
    count += diff;
    return count;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int extremeRoundCount = findTotalExtreme(n);
        cout << extremeRoundCount << endl;
    }

    return 0;
}