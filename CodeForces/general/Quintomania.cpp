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
bool solve(vector<int> arr, int n)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        int diff = abs(arr[i] - arr[i + 1]);
      
        if(diff<5||diff>7)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int n;
        cin >> n;
        vector<int> res;
        while (n--)
        {
            int num;
            cin >> num;
            res.push_back(num);
        }
        bool ans = solve(res, n);
        if (ans)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}