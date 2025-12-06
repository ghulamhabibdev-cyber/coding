#include <bits/stdc++.h>
using namespace std;
class a
{
public:
};
int solveRec(int n, int x, int y, int z)
{
    if (n == 0)
    {
        return 0;
    }
    if (n < 0)
    {
        return -1e9;
    }
    int a = solveRec(n - x, x, y, z) + 1;
    int b = solveRec(n - y, x, y, z) + 1;
    int c = solveRec(n - z, x, y, z) + 1;
    return max(a, max(b, c));
}
int solveMem(int n, int x, int y, int z, vector<int> &dp)
{
    if (n == 0)
    {
        return 0;
    }
    if (n < 0)
    {
        return -1e9;
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    int a = solveMem(n - x, x, y, z,dp) + 1;
    int b = solveMem(n - y, x, y, z,dp) + 1;
    int c = solveMem(n - z, x, y, z,dp) + 1;
    dp[n]= max(a, max(b, c));
    return dp[n];
}
int solevTab(int n, int x, int y, int z)
{
    vector<int>dp(n+1,INT_MIN);
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        if(i-x>=0)
        {
            dp[i]=max(dp[i],dp[i-x]+1);

        }
         if(i-y>=0)
        {
            dp[i]=max(dp[i],dp[i-z]+1);
        }
         if(i-z>=0)
        {
            dp[i]=max(dp[i],dp[i-z]+1);
        }
    }
    return dp[n];
}
int cutIntoSegment(int len, int x, int y, int z)
{
    int ans =0;
    // ans= solveRec(len, x, y, z);
    vector<int>dp(len+1,-1);
    // ans=solveMem(len,x,y,z,dp);
    ans=solevTab(len,x,y,z);
    if (ans < 0)
    {
        return -1;
    }
    return ans;
}
int main()
{
    int len = 7, x = 5, y = 2, z = 2;
    cout << "Maximum number of segments: "
         << cutIntoSegment(len, x, y, z) << endl;
    return 0;
}