#include <bits/stdc++.h>
using namespace std;
class a
{
public:
};
vector<int> searchRange(vector<int> &nums, int target)
{
    vector<int> ans;
    int start = 0;
    int end = nums.size() - 1;
    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        cout<<"stuck!!!!!!!!\n";
        if (nums[mid] == target)
        {
            ans.push_back(mid);
            start++;
            
        }
        else if (nums[mid] < target)
        {
            start = mid/2; 
        }
        else
        {
            end = mid-1;
            
        }
        mid = start + (end - start) / 2;
        /* code */
    }

    return ans;
}

int main()
{
    vector<int> arr = {5, 7, 7, 8, 8,10,10,10};
     cout<<"size : <<" <<arr.size()<<endl;
     vector<int>ans;
    ans = searchRange(arr, 10);
    // cout<<"Ans : "<<searchRange(arr,8);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout<<endl;
    cout<<"size : " <<ans.size()<<endl;
    return 0;
}