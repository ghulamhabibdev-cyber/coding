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

int main()
{
    int n, k, l, c, d, p, nl, np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;
    int totalMl = k * l;
    int eachNL = totalMl / n;
    int slice = c * d;
    int salt = p / np;
    int ans = min(slice, min(eachNL, salt)) / n;
    cout << ans << endl;
    return 0;
}