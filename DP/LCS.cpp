#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits>
#include <list>
using namespace std;

class A
{
};
int LCS(string s1, string s2, int n, int m, int i, int j)
{
    if (i == n || j == m)
    {
        return 0;
    }
    if (s1[i] == s2[j])
    {
        return 1 + LCS(s1, s2, n, m, i + 1, j + 1);
    }
    int c1 = LCS(s1, s2, n, m, i, j + 1);
    int c2 = LCS(s1, s2, n, m, i + 1, j);
    return max(c1, c2);
}

int LCSMemomization(string s1, string s2, int n, int m, int i, int j, vector<vector<int>> &dp)
{
    if (i == n || j == m)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    if (s1[i] == s2[j])
    {
        int ans = 1 + LCSMemomization(s1, s2, n, m, i + 1, j + 1, dp);
        dp[i][j] = ans;
        return ans;
    }
    int c1 = LCSMemomization(s1, s2, n, m, i, j + 1, dp);
    int c2 = LCSMemomization(s1, s2, n, m, i + 1, j, dp);
    int ans = max(c1, c2);
    dp[i][j] = ans;
    return ans;
}

int LCSTabulation(string s1, string s2)
{
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 0; i <= n; i++)
    {
        dp[i][m] = 0;
    }
    for (int j = 0; j <= m; j++)
    {
        dp[n][j] = 0;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if (s1[i] == s2[j])
            {
                dp[i][j] = 1 + dp[i + 1][j + 1];
            }
            else
            {
                dp[i][j] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
    }
    return dp[0][0];
}
int main()
{
    string s1 = "abcde";
    string s2 = "ace";
    int n = s1.length();
    int m = s2.length();
    int ans = LCS(s1, s2, n, m, 0, 0);
    cout << ans << endl;
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int mAns = LCSMemomization(s1, s2, n, m, 0, 0, dp);
    cout << "dp Ans : " << mAns << endl;

    cout << "========== Tabulation ============ \n";
    int tAns = LCSTabulation(s1, s2);
    cout << "tAns   : " << tAns << endl;
    return 0;
}