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
    vector<long long> arr;
    for (int i = 0; i < n; i++)
    {
        long long candies;
        cin >> candies;
        long long ans = (candies - 1) / 2;
        if (ans % 2 == 0)
        {

            arr.push_back(ans);
        }
        else
        {
            arr.push_back(ans);
        }
    }
    // cout << "======================"<<endl;
    for (long long x : arr)
    {
        cout << x << endl;
    }
    return 0;
}