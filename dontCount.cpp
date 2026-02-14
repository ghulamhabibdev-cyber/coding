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
int maxStepCount(string x, string s)
{
    int count = 0;
    while (x.length() <= s.length())
    {
        x += x;
        count++;
    }
    return count;
}
int main()
{
    int t;
    cin >> t;
    string x, s;
    int lX, lS;
    vector<int> arr;
    while (t--)
    {
        cin >> lX >> lS;
        // cin.ignore();
        // cin.ignore();
        cin >> x >> s;
        int ans = maxStepCount(x, s);
        arr.push_back(ans);
    }
    for (int n : arr)
    {
        cout << n << endl;
    }

    return 0;
}