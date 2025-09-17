#include <bits/stdc++.h>
using namespace std;
class a
{
public:
};
int solveRec(int index, int endIndex, vector<int> slice, int n)
{
    if (n == 0 || index > endIndex)
    {
        return 0;
    }
    int take = slice[index] + solveRec(index + 2, endIndex, slice, n - 1);
    int noTake = 0 + solveRec(index + 1, endIndex, slice, n);
    int ans = max(take, noTake);

    return ans;
}
int solveMEM(int index,int endIndex,vector<int>slice,int n, vector<vector<int>> &dp2)
{
    if (n == 0 || index > endIndex)
    {
        return 0;
    }
    if(dp2[index][n]!=-1)
    {
        return dp2[index][n];
    }
    int take = slice[index] + solveMEM(index + 2, endIndex, slice, n - 1,dp2);
    int noTake = 0 + solveMEM(index + 1, endIndex, slice, n,dp2);

    int ans = max(take, noTake);
    dp2[index][n]=ans;

    return dp2[index][n];

}
int solveTab(vector<int>slices)
{
    int k=slices.size();
    vector<vector<int>>dp1(k+2,vector<int>(k/3+1,0));
    vector<vector<int>>dp2(k+2,vector<int>(k/3+1,0));

    // for case 1
    for(int index=k-2;index>=0;index--)
    {
        for(int n=1;n<=k/3;n++)
        {
            int take = slices[index] + dp1[index + 2][ n - 1];
            int noTake = 0 + dp1[index + 1][n];
        
            int ans = max(take, noTake);
            dp1[index][n]=ans;
        }
    }
    int case1=dp1[0][k/3];
    for(int index=k-1;index>=0;index--)
    {
        for(int n=1;n<=k/3;n++)
        {
            int take = slices[index] + dp2[index + 2][ n - 1];
            int noTake = 0 + dp2[index + 1][n];
        
            int ans = max(take, noTake);
            dp2[index][n]=ans;
        }
    }
    int case2=dp2[1][k/3];
    return max(case1,case2);

}
int solveOp(vector<int>slices)
{
    int k=slices.size();
    vector<int>prev1(k+2,0);
    vector<int>curr1(k+2,0);
    vector<int>next1(k+2,0);

    // for case 1
    for(int index=k-2;index>=0;index--)
    {
        for(int n=1;n<=k/3;n++)
        {
            int take = slices[index] + next1[ n - 1];
            int noTake = 0 + curr1[n];
        
            int ans = max(take, noTake);
            prev1[n]=ans;
        }
        next1=curr1;
        curr1=prev1;
    }
    int case1=curr1[k/3];

    vector<int>prev2(k+2,0);
    vector<int>curr2(k+2,0);
    vector<int>next2(k+2,0);
    for(int index=k-1;index>=0;index--)
    {
        for(int n=1;n<=k/3;n++)
        {
            int take = slices[index] + next2[ n - 1];
            int noTake = 0 + curr2[n];
        
            int ans = max(take, noTake);
            prev2[n]=ans;
        }
        next2=curr2;
        curr2=prev2;
    }
    int case2=curr2[k/3];
    return max(case1,case2);
}
int maxSizeSlices(vector<int> slice)
{
    int k = slice.size();
    // int case1 = solveRec(0, k - 2, slice, k / 3);
    // int case2 = solveRec(1, k - 1, slice, k / 3);
    int ans = 0;
    //  int case1 = solveRec(0, k - 2, slice, k / 3);
    //  int case2 = solveRec(1, k - 1, slice, k / 3);
    // vector<vector<int>> dp2(k, vector<int>(k/3 + 1, -1));
    // int case1=solveMEM(0,k-2,slice,k/3,dp2);
    // vector<vector<int>> dp3(k, vector<int>(k/3 + 1, -1));
    // int case2=solveMEM(1,k-1,slice,k/3,dp3);
    
    // ans = max(case1, case2);
    // ans=solveTab(slic e); 
    ans=solveOp(slice);
    return ans;
} 
int main()
{
    vector<int> slices = {2, 4, 6, 8, 10, 12};
    cout << maxSizeSlices(slices) << endl; // Expected: 10
    return 0;
    return 0;
}