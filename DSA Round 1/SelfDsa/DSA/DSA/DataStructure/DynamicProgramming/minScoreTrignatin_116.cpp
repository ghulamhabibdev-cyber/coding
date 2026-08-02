#include <bits/stdc++.h>
using namespace std;
class a
{
public:
};
int solveMinPolygonProb(vector<int> &v, int i, int j)
{
    if (i + 1 == j)
    {
        return 0;
    }
    int ans = INT_MAX;
    for (int k = i + 1; k < j; k++)
    {
        ans = min(ans, v[i] * v[k] * v[j] + solveMinPolygonProb(v, i, k) + solveMinPolygonProb(v, k, j));
    }
    return ans;
}
int solveMinPolygonProbMEM(vector<int> &v, int i, int j, vector<vector<int>> &dp)
{
    if (i + 1 == j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int ans = INT_MAX;
    for (int k = i + 1; k < j; k++)
    {
        ans = min(ans, v[i] * v[k] * v[j] + solveMinPolygonProb(v, i, k) + solveMinPolygonProb(v, k, j));
    }
    dp[i][j] = ans;
    return dp[i][j];
}
int solveMinPolygonProbTab(vector<int> &v)
{
    int n = v.size();

    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i + 2; j < n; j++)
        {

            int ans = INT_MAX;
            for (int k = i + 1; k < j; k++)
            {
                ans = min(ans, v[i] * v[k] * v[j] + dp[i][k]+dp[k][j]);
            }
           dp[i][j]=ans;
           
        }
    }
   return dp[0][n-1];
}
int minScoreTriangulation(vector<int> value)
{
    int ans = 0;
    int n = value.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    // ans = solveMinPolygonProb(value,0,n-1);
    // ans = solveMinPolygonProbMEM(value, 0, n - 1, dp);
    ans=solveMinPolygonProbTab(value);
    return ans;
}
int main()
{
    vector<int> v = {1, 2, 3, 4};
    cout << "Minimum Score Triangulation: " << minScoreTriangulation(v) << endl;
    return 0;
}