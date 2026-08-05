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
int subSetSum(vector<int> &arr, int sum, int index, int n)
{
    if (sum == 0)
    {
        return 1;
    }
    if (index >= n || sum < 0)
    {
        return 0;
    }
    if (arr[index] == 0)
    {
        index++;
    }
    return subSetSum(arr, sum, index + 1, n) + subSetSum(arr, sum - arr[index], index, n);
}
int main()
{
    vector<int> arr = {2, 3, 4};
    int n = arr.size();
    int sum = 6;
    int ans = subSetSum(arr, sum, 0, n);
    cout << ans << endl;
    return 0;
}