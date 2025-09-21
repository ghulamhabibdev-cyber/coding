#include<bits/stdc++.h>
using namespace std;
int uniqueBST(int n)
{
    if(n<=1)
    {
        return 1;
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans+=uniqueBST(i-1)*uniqueBST(n-i);
    }
    return ans;

}
int solveDp(vector<int>&dp,int n)
{
    if(n<=1)
    {
        return 1;
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans+=solveDp(dp,i-1)*solveDp(dp,n-i);
    }
    dp[n] =ans;
    return dp[n];

}
int solveTab(int n)
{
    vector<int>dp(n+1,0);
    dp[0]=dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            dp[i]+=dp[j-1]*dp[i-j];
        }
    }
    return dp[n];
}
int main()
{
    int n;
    cin>>n;
    // int ans=uniqueBST(n);
    vector<int>dp(n+1,-1);
    // int ans=solveDp(dp,n);
    int ans=solveTab(n);
    cout<<"Unique bst : "<<ans<<endl;
{

}

    return 0;
}