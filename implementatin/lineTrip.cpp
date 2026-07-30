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

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int sz;
        int x;
        cin >> sz;
        cin >> x;
        vector<int> arr;
        for (int j = 0; j < sz; j++)
        {
            int ai;
            cin >> ai;
            arr.push_back(ai);
        }
        int maxi = x - arr[arr.size() - 1];
        maxi *= 2;
        // cout << "hi " << maxi << endl;
        int initial = arr[0];
        int newMaxi = 0;
        for (int k = 1; k < arr.size(); k++)
        {
            int ans = arr[k] - initial;
            newMaxi = max(ans, max(initial, maxi));
            initial = arr[k];
        }
        initial=arr[0];
        maxi = max(maxi, max(initial, newMaxi));
        cout << maxi << endl;
    }
    return 0;
}