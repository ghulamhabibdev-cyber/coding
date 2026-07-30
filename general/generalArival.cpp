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
int minTimeTolineUp(int n)
{
    vector<int> line;
    for (int i = 0; i < n; i++)
    {
        int soldier;
        cin >> soldier;
        line.push_back(soldier);
    }
    int maxIndex = 0;
    int minIndex = n - 1;
    for (int i = 0; i < n; i++)
    {
        if (line[i] > line[maxIndex])
        {
            maxIndex = i;
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (line[i] < line[minIndex])
        {
            minIndex = i;
        }
    }
    int ans = maxIndex + (n - 1 - minIndex);
    if (maxIndex > minIndex)
    {
        ans--;
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    int ans = minTimeTolineUp(n);
    cout << ans << endl;
    return 0;
}