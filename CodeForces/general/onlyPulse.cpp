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
int noobih_Monk(vector<int> arr)
{
    sort(arr.begin(), arr.end());
    int count = 0;
    int n = arr.size();
    while (arr[0] != arr[n - 1] && count != 5)
    {
        arr[0]++;
        count++;
    }
    int i = 0;
    while (arr[01] != arr[n - 1] && count != 5)
    {
        arr[1]++;
        count++;
    }
    while (count != 5)
    {
        arr[i++]++;
        if (i == 3)
        {
            i = 0;
        }
        count++;
    }
    long ans = 1;
    for (int i = 0; i < n; i++)
    {
        // cout << "element at idex : " << arr[i] << endl;
        ans = arr[i] * ans;
    }
    return ans;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n = 3;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        long ans = noobih_Monk(arr);
        cout << ans << endl;
    }
    return 0;
}