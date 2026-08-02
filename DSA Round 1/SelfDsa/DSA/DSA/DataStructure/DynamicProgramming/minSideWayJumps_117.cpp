#include <bits/stdc++.h>
using namespace std;
class a
{
public:
};
int solveSideJumpsRec(vector<int> &obstacle, int currLane, int currPos)
{

    int n = obstacle.size() - 1;
    // if frog reach the destination then no need to jump
    if (currPos == n)
    {
        return 0;
    }
    // check if next pos has has no obtactle
    if (obstacle[currPos + 1] != currLane)
    {
        return solveSideJumpsRec(obstacle, currLane, currPos + 1);
    }
    // check if next pos has obstacle in same lans then make side jmps
    else
    {
        int ans = INT_MAX;
        for (int i = 1; i <= 3; i++)
        {
            // chck wether the jumps made is not in same lan and side lane dont ha
            // have obstacle
            if (currLane != i && obstacle[currPos] != i)
            {

                ans = min(ans, 1 + solveSideJumpsRec(obstacle, i, currPos));
            }
        }
        return ans;
    }
}
int solveMem(vector<int> &obstacle, int currLane, int currPos, vector<vector<int>> &dp)
{

    int n = obstacle.size() - 1;
    // if frog reach the destination then no need to jump
    if (currPos == n)
    {
        return 0;
    }
    if (dp[currLane][currPos] != -1)
    {
        return dp[currLane][currPos];
    }
    // check if next pos has has no obtactle
    if (obstacle[currPos + 1] != currLane)
    {
        return dp[currLane][currPos] = solveMem(obstacle, currLane, currPos + 1, dp);
    }
    // check if next pos has obstacle in same lans then make side jmps
    else
    {
        int ans = INT_MAX;
        for (int i = 1; i <= 3; i++)
        {
            // chck wether the jumps made is not in same lan and side lane dont ha
            // have obstacle
            if (currLane != i && obstacle[currPos] != i)
            {

                ans = min(ans, 1 + solveMem(obstacle, i, currPos, dp));
            }
        }
        dp[currLane][currPos] = ans;
        return dp[currLane][currPos];
    }
}
int solveTab(vector<int> &obstacle)
{
    vector<vector<int>> dp(4, vector<int>(obstacle.size(), INT_MAX));
    int n = obstacle.size() - 1;
    dp[0][n] = 0;
    dp[1][n] = 0;
    dp[2][n] = 0;
    dp[3][n] = 0;
    for (int currPos = n - 1; currPos >= 0; currPos--)
    {
        for (int currLane = 1; currLane <= 3; currLane++)
        {
            if (obstacle[currPos + 1] != currLane)
            {
                dp[currLane][currPos] = dp[currLane][currPos + 1];
            }
            // check if next pos has obstacle in same lans then make side jmps
            else
            {
                int ans = 1e9;
                for (int i = 1; i <= 3; i++)
                {
                    // chck wether the jumps made is not in same lan and side lane dont ha
                    // have obstacle
                    if (currLane != i && obstacle[currPos] != i)
                    {

                        ans = min(ans, 1 + dp[i][currPos + 1]);
                    }
                }
                dp[currLane][currPos] = ans;
            }
        }
    }
    return min(dp[2][0], min(1 + dp[1][0], 1 + dp[3][0]));
}
int solveOpt(vector<int> obstacle)
{
    int n = obstacle.size() - 1;
    vector<int> curr(4, INT_MAX);
    vector<int> next(4, INT_MAX);
    next[0] = 0;
    next[1] = 0;
    next[2] = 0;
    next[3] = 0;

    for (int currPos = n - 1; currPos >= 0; currPos--)
    {
        for (int currLane = 1; currLane <= 3; currLane++)
        {
            if (obstacle[currPos + 1] != currLane)
            {
                curr[currLane] = next[currLane];
            }
            // check if next pos has obstacle in same lans then make side jmps
            else
            {
                int ans = 1e9;
                for (int i = 1; i <= 3; i++)
                {
                    // chck wether the jumps made is not in same lan and side lane dont ha
                    // have obstacle
                    if (currLane != i && obstacle[currPos] != i)
                    {

                        ans = min(ans, 1 +next[i]);
                    }
                }
                curr[currLane] = ans;
            }
        }
        next=curr;
    }
    return min(next[2],min(1+next[1],1+next[3]));
}
int mimSideWaysJumps(vector<int> &obstacle)
{
    int ans = 0;
    // ans = solveSideJumpsRec(obstacle, 2, 0);
    vector<vector<int>> dp(4, vector<int>(obstacle.size(), -1));
    // ans = solveMem(obstacle, 2, 0, dp);
    // ans = solveTab(obstacle);
    ans=solveOpt(obstacle);
    return ans;
}
int main()
{
    vector<int> obstacle = {0, 1, 2, 3, 0};     // Example input
    cout << mimSideWaysJumps(obstacle) << endl; // Expected Output: 2

    return 0;
}