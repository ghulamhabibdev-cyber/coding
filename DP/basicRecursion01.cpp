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
int TwoMultiply(int n)
{
    if (n == 1)
    {
        return 2;
    }
    int ans = TwoMultiply(n - 1);
    ans += 2;
    return ans;
}
int main()
{
    int ans = TwoMultiply(5);
    cout << ans << endl;
    return 0;
}