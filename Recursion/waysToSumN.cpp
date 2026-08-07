#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    void waysToSum(int &count, vector<int> &arr, int sum, int t, int index)
    {
        if (sum == t)
        {
            count++;
            return;
        }
        if (sum > t || index >= arr.size())
        {
            return;
        }
        sum += arr[index];
        waysToSum(count, arr, sum, t, index);
        sum -= arr[index];
        waysToSum(count, arr, sum, t, index + 1);
    }
    int count(vector<int> &coins, int sum)
    {
        // code here.
        int count = 0;
        waysToSum(count, coins, 0, sum, 0);
        return count;
    }
};
int main()
{
    Solution s;
    vector<int> arr = {1, 5, 6};
    int sum = 7;
    int ans = s.count(arr, sum);
    cout << "Ways : " << ans << endl;
    return 0;
}