#include <iostream>
#include <vector>
using namespace std;
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    // var section
    int n = nums.size();
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        int max = INT_MIN;
        for (int j = i; j < k + i; j++)
        {
            if (nums[j] > max)
            {
                max = nums[j];
            }
        }
        ans.push_back(max);
    }

    return ans;
}
int main()
{
    vector<int>ans=maxSlidingWindow()

    return 0;
}
