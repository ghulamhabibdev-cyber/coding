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
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int sum = 0;
        int inc = 2;
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            if (sum + 2 * inc > n)
            {
                flag = false;
                break;
            }
            else
            {
                sum += inc;
                inc += 2;
            }
        }
        if (!flag && sum != 0)
        {
            cout << 2 << endl;
        }
        else
        {
            cout << n << endl;
        }
    }
    return 0;
}