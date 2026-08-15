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
double volumeFraction(double n)
{
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        int frac;
        cin >> frac;
        sum += frac;
    }
    double ans = sum / n;
    return ans;
}
int main()
{
    double n;
    cin >> n;
    double ans = volumeFraction(n);
    cout << ans << endl;
    return 0;
}