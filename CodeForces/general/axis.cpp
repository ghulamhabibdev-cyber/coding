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
int findAxis(vector<int> arr)
{
    sort(arr.begin(), arr.end());
    int mid = arr[1];
    int ans = abs(arr[0] - mid) + abs(arr[2] - mid);
    return ans;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n = 3;
        vector<int> arr;
        for (int i = 0; i < n; i++)
        {
            int num;
            cin >> num;
            arr.push_back(num);
        }
        int ans = findAxis(arr);
        cout << ans << endl;
    }
    return 0;
}