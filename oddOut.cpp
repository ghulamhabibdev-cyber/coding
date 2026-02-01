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
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        int ans = 0;
        cin >> a >> b >> c;
        ans ^= a;
        ans ^= b;
        ans ^= c;
        arr.push_back(ans);
    }
    for (int x : arr)
    {
        cout << x << endl;
    }
    return 0;
}