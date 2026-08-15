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
int findSum(int x, int n)
{
    if (n % 2 == 1)
    {
        return x;
    }
    return 0;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, n;
        cin >> x >> n;
        int sum = findSum(x, n);
        cout << sum << endl;
    }

    return 0;
}