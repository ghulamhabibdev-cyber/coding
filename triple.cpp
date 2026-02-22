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
int getElementHaveThreeFreq(vector<int> arr)
{
    sort(arr.begin(), arr.end());
    int n = arr.size();
    int count = 0;
    int prev = -1;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            count++;
            prev = arr[i];
        }
        else
        {
            if (count >= 2)
            {
                return prev;
            }
            else
            {
                count = 0;
            }
        }
    }
    if (count >= 2)
    {
        return prev;
    }
    return -1;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        if (n <= 2)
        {
            cout << -1 << endl;
        }
        else
        {
            int ans = getElementHaveThreeFreq(arr);
            cout << ans << endl;
        }
    }

    return 0;
}