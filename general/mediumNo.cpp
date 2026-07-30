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

    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        vector<int> arr;
        int a, b, c;
        cin >> a >> b >> c;
        arr.push_back(a);
        arr.push_back(b);
        arr.push_back(c);
        sort(arr.begin(), arr.end());
        ans.push_back(arr[1]);
    }
    for (int x : ans)
    {
        cout << x << endl;
    }
    return 0;
}