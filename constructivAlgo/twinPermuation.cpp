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
int findMax(vector<int> arr)
{
    int maxi = arr[0];
    for (int num : arr)
    {
        if (num > maxi)
        {
            maxi = num;
        }
    }
    return maxi;
}
vector<int> findTwinPermutation(vector<int> &nums)
{
    queue<int> q;
    int maxi = findMax(nums);
    int n = nums.size();
    vector<int> v(n);
    v[n - 1] = maxi;
    int prev = maxi + nums[n - 1];
    q.push(--maxi);
    unordered_map<int, bool> mp;
    for (int i = n - 2; i >= 0; i--)
    {

        int front = q.front();
        if(!q.empty())
        while ((front + nums[i] > prev))
        {
            q.push(--front);
        }
        while (mp.find(front) != mp.end())
        {
            q.pop();
            front = q.front();
        }
        mp[front] = true;

        v[i] = front;
        prev = front + nums[i];
    }

    return v;
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
        vector<int> ans = findTwinPermutation(arr);
        for (int n : ans)
        {
            cout << n << " ";
        }
        cout << endl;
    }

    return 0;
}