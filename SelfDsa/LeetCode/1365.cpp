#include <bits/stdc++.h>
using namespace std;
vector<int> smallerNumbersThanCurrent(vector<int> &nums)
{
    vector<int> ans;

    map<int, int> mp;
    vector<int> solid = nums;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]] = 0;
    }
    vector<int> count(nums.size(), 0);
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        count[i] = i;
    }

    for (int i = 0; i < count.size(); i++)
    {
        if (i < count.size())
        {
            if (nums[i] == nums[i + 1])
            {
                count[i + 1] = count[i];
            }
        }
    }
    for (int i = 0; i < solid.size(); i++)
    {
        int val = nums[i];
        if (mp.find(val) != mp.end())
        {
            mp[val] = count[i];
        }
    }

    for (int i = 0; i < solid.size(); i++)
    {
        int val = solid[i];
        if (mp.find(val) != mp.end())
        {
            ans.push_back(mp[val]);
        }
    }

    return ans;
}
vector<int> smallerNumbersThanCurrent2(vector<int> num)
{
    vector<int> sortedNum = num;
    sort(sortedNum.begin(), sortedNum.end());
    unordered_map<int, int> mp;
    for (int i = 0; i < num.size(); i++)
    {
        if (!mp[sortedNum[i]])
        {
            mp[sortedNum[i]]=i+1;
        }

    }
    vector<int>ans;
    for(int i=0;i<num.size();i++)
    {
        ans.push_back(mp[num[i]]-1);

    }
    return ans;
}
int main()
{
    vector<int> num = {8, 2, 2, 2, 3, 3, 3, 3};
    num = smallerNumbersThanCurrent2(num);
    for (int i = 0; i < num.size(); i++)
    {
        cout << num[i] << " , ";
    }
    // cout << "Hello world";
}
