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
int magnetGroup(int n)
{
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        int mag;
        cin >> mag;
        ans.push_back(mag);
    }
    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (ans[i] != ans[i + 1])
        {
            count++;
        }
    }
    count++;
    return count;
}
int main()
{
    int n;
    cin >> n;
    int ans = magnetGroup(n);
    cout << ans << endl;
    return 0;
}