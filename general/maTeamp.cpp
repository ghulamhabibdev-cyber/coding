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
int minDiff(vector<int> arr)
{
    sort(arr.begin(), arr.end());
    int prevDiff = INT_MAX;
    int n = arr.size();
    bool found = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int curr = abs(arr[j] - arr[i]);
            
            prevDiff = min(prevDiff, curr);
            if (prevDiff == 0)
            {
                found = true;
                break;
            }
        }
        if (found)
        {
            break;
        }
    }
    return prevDiff;
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
        int dif = minDiff(arr);
        cout << dif << endl;
    }

    return 0;
}