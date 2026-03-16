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
int findMinDiff(int n)
{
    if (n == 2)
    {
        return 2;
    }
    vector<int> towPower;
    int base = 1;
    for (int i = 1; i <= n; i++)
    {
        base = base * 2;
        towPower.push_back(base);
        // cout << base << " ";
    }
    // cout << endl;
    int i = 0;
    int j = n - 1;
    int fileA = 0;
    int fileB = 0;
    bool toggle = false;
    while (i < j)
    {
        if (toggle)
        {
            fileA += towPower[i] + towPower[j];
        }
        else
        {
            fileB += towPower[i] + towPower[j];
        }
        toggle = !toggle;
        i++;
        j--;
    }
    return abs(fileA - fileB);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int ans = findMinDiff(n);
        cout << ans << endl;
    }

    return 0;
}