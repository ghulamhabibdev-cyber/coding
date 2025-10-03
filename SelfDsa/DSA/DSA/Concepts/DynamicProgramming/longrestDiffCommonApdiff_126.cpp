#include <bits/stdc++.h>
using namespace std;
class a
{
    public:
    
};
int longesSubsequence(vector<int>&arr,int diff)
{
    unordered_map<int,int >dp;
    int ans=0;
    for(int i=0;i<arr.size();i++)
    {
        int temp=arr[i]-diff;
        int tempans=0;
        // check answer for temp exist or not
        if(dp.count(temp))
        {
            tempans=dp[temp];
        }
        dp[arr[i]]=1+tempans;
        ans=max(ans,dp[arr[i]]);
    }
    

    return ans;
}
int main()
{
    vector<int> arr = {1, 5, 7, 8, 5, 3, 4, 2, 1};
    int diff = 2;
    cout << "Longest subsequence length with difference " << diff 
         << " = " << longesSubsequence(arr, diff) << endl;
    return 0;
}