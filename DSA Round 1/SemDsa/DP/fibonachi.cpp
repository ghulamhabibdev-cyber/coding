#include <iostream>
#include<vector>
using namespace std;

class A {
};
int solve(int n,vector<int>&dp)
{
    if(n==0||n==1)
    {
        dp[n]=n;
        return dp[n];
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    int ans=solve(n-1,dp)+solve(n-2,dp);
    dp[n]=ans;
    return ans;
}
vector<int>factorial(int n)
{
    vector<int>dp(n+1,-1);
    solve(n,dp);
    return dp;

}
vector<int>Tabulation(int n)
{
    vector<int>dp(n,0);
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp;
}
int main() {
    int n;
    cout<<"Enter a number \n";
    cin>>n;
    vector<int>dp;
    // dp=factorial(n);
    dp=Tabulation(n);
    int size=dp.size();
    for(int i=0;i<size;i++)
    {
        cout<<dp[i]<<" \n";
    }
    
    return 0;
}