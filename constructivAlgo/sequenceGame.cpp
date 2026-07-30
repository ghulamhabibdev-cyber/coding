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
vector<int> sequenceGame(vector<int> arr)
{
    int n = arr.size();
    int prev = arr[0];
    vector<int> ans;
    ans.push_back(arr[0]);
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] <= arr[i + 1])
        {
            prev = arr[i];
            ans.push_back(arr[i+1]);
        }
        else
        {
            int dif = arr[i] - arr[i + 1];
            ans.push_back(dif);
            ans.push_back(arr[i + 1]);
        }
    }
    
    return ans;
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
        vector<int> ans = sequenceGame(arr);
        for (int n : ans)
        {
            cout << n << " ";
        }
       
    }

    return 0;
}