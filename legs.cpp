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
int maxLegs(int n)
{
    int count = 0;
    while (n > 2)
    {
        n -= 4;
        count++;
    }
    if (n == 2)
    {
        count++;
    }
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
        int count = maxLegs(n);
        cout << count << endl;
    }
    return 0;
}