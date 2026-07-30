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
bool makeSameParity(vector<int> nums)
{
    int n = nums.size();
    vector<int> arr(n), array(n);
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 1)
            arr[i] = nums[i] + 1;
        else
            arr[i] = nums[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            array[i] = nums[i] + 1;
        else
            array[i] = nums[i];
    }


    bool evenParity = true;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] % 2 != arr[i - 1] % 2)
        {
            evenParity = false;
            break;
        }
    }
    bool oddParity = true;
    for (int i = 1; i < n; i++)
    {
        if (array[i] % 2 != array[i - 1] % 2)
        {
            oddParity = false;
            break;
        }
    }

    return evenParity || oddParity;
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
        if (makeSameParity(arr))
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