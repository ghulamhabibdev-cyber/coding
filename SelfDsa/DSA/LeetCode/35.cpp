#include <bits/stdc++.h>
using namespace std;
class a
{
public:
};
int searchInsert(vector<int> &nums, int target)
{
    int left = 0;
    int right = nums.size();
    int mid = left + (right - left) / 2;
    while (left <= right)
    {
        if(nums[mid]==target)
        {
            return mid;
        }
        else if(target>nums[mid])
        {
            left=mid+1;
        }
        else{
            right=mid-1;
        }
       
        mid = left + (right - left) / 2;
    }
    return mid;
}
int main()
{
    cout << "Hello\n";
}