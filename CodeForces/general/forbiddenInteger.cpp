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
pair<int, vector<int>> canFoundDigit(int n, int k, int x)
{
    if (n == k && k != x)
    {
        return {1, {k}};
    }
    if (k == x)
    {
        k--;
    }
    int i = k;
    int count = 0;
    vector<int> arr;
    int num = n;
    int sum = 0;
    while (i > 0)
    {
        n = n - i;
        if (n < 0)
        {
            n += k;
            i--;
        }
        else if (n >= 0)
        {
            count++;
            sum += i;
            arr.push_back(i);
        }
        if (i == x)
        {
            i--;
        }
    }
    if (sum != num)
    {
        count = -1;
    }
    return {count, arr};
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, x;
        cin >> n >> k >> x;
        pair<int, vector<int>> p = canFoundDigit(n, k, x);
        int count = p.first;
        if (count > 0)
        {
            cout << "YES" << endl;
            cout << count << endl;
            for (int num : p.second)
            {
                cout << num << " ";
            }
            cout << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}