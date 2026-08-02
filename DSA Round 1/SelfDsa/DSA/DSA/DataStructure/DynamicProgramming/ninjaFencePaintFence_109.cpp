#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
class a
{
    public:
    
};
int add(int a,int b)
{
    return (a%MOD+b%MOD)%MOD;
}
int mul(int a,int b)
{
   return (1LL * (a % MOD) * (b % MOD)) % MOD;
}
int solveRec(int n,int k)
{
    if(n==1)
    {
        return k;
    }
    if(n==2)
    {
         return add(k, mul(k, k-1));
    }
    int ans=add(mul(solveRec(n-2,k),k-1),mul(solveRec(n-1,k),k-1));
    return ans;
}
int solveMem(int n,int k,vector<int>dp)
{
      if(n==1)
    {
        return k;
    }
    if(n==2)
    {
         return add(k, mul(k, k-1));
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }
     dp[n]=add(mul(solveMem(n-2,k,dp),k-1),mul(solveMem(n-1,k,dp),k-1));
    return dp[n];
}
int solveTab(int n,int k)
{
    vector<int>dp(n+1,-1);
    dp[1]=k;
    dp[2]=add(k, mul(k, k-1));
    for(int i=3;i<=n;i++)
    {
        dp[i]=add(mul(dp[i-2],k-1),mul(dp[i-1],k-1));
    }
    return dp[n];
}
int solveOpt(int n,int k)
{
    int prev1=k;
    int prev2=add(k, mul(k, k-1));
     for(int i=3;i<=n;i++)
    {
        int ans=add(mul(prev1,k-1),mul(prev2,k-1));
       prev2=prev1;
       prev1=ans;
    }
    return prev1;
}
int pintNinjaProblem(int n,int k)
{

    vector<int>dp(n+1,-1);
    int ans=0;
    // ans= solveRec(n,k);
    // ans=solveMem(n,k,dp);
    // ans=solveTab(n,k);
    ans=solveOpt(n,k);

    return ans;
}
int main()
{
    cout<<"Total wasy to paint : " << pintNinjaProblem(3,3);
    return 0;
}