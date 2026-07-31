#include<bits/stdc++.h>
using namespace std;
int solveRec(vector<int>&arr,map<pair<int,int>,int>&maxi,int left,int right)
{
    if(left==right)
    {
        return 0;
    }
    int maxivalue=INT_MAX;
    for(int i=left;i<right;i++)
    {
        maxivalue = min(maxivalue,
                        maxi[{left, i}] * maxi[{i + 1, right}] + solveRec(arr, maxi, left, i) + solveRec(arr, maxi, i + 1, right));
    }

    return maxivalue;
}
int solveDp(vector<int>&arr,map<pair<int,int>,int>&maxi,int left,int right,vector<vector<int>>&dp)
{

    if (left == right)
    {
        return 0;
    }
    if(dp[left][right]!=-1)
    {
        return dp[left][right];
    }
    int maxivalue = INT_MAX;
    for (int i = left; i < right; i++)
    {
        maxivalue = min(maxivalue,
                        maxi[{left, i}] * maxi[{i + 1, right}] + solveDp(arr, maxi, left, i,dp) + solveDp(arr, maxi, i + 1, right,dp));
    }
    dp[left][right]=maxivalue;

    return dp[left][right];
}
int mctFromLeafValues(vector<int>&arr)
{

    map<pair<int,int>,int >maxi;
    int n=arr.size();
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));

    for(int i=0;i<arr.size();i++)
    {
        maxi[{i,i}]=arr[i];
        for(int j=i;j<arr.size();j++)
        {
            maxi[{i, j}] = max(arr[j], maxi[{i, j-1}]);

        }
    }

    // for(int i=0;i<arr.size();i++)
    // {
    //     for(int j=0;j<arr.size();j++)
    //     {
    //         cout<<"For range  "<<i<<" --> "<<j<< " : "<<maxi[{i,j}]<<endl;
    //     }
    // }
    // return solveRec(arr,maxi,0,arr.size()-1);
    return solveDp(arr,maxi,0,arr.size()-1,dp);
    return 0;
}
int main()
{
    vector<int>arr={2,3,4,5,6,7,14};
   cout<< mctFromLeafValues(arr);
}
