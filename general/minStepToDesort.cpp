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
int minStepToDesortArray(vector<int> arr)
{
    int curr = 0;
    int prev = INT_MAX;
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            return 0;
        }
        else if (arr[i] < arr[i + 1])
        {
            int diff = arr[i + 1] - arr[i];
            diff = diff / 2;
            curr = diff;

            if (curr < prev)
            {
                curr++;
                prev = min(curr, prev);
                curr = 0;
            }
        }
        else
        {
            prev=1;
        }
    }
    return prev;
}
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
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int minStep = minStepToDesortArray(arr);
        cout << minStep << endl;
    }

    return 0;
}