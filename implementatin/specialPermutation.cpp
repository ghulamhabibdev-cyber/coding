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
vector<int> findSpecialPermutation(int n)
{
    if (n == 2)
    {
        return {2, 1};
    }
    vector<int> arr;
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 1)
        {
            arr.push_back(i + 1);
        }
        else
        {
            arr.push_back(i - 1);
        }
    }
    int num = arr.size();

    if (n % 2 == 0)
    {

        arr[num - 1] = n - 1;
        return arr;
    }
    arr[num - 1] = n;
    swap(arr[n - 2], arr[n - 1]);
    return arr;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr = findSpecialPermutation(n);
        for (int num : arr)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}