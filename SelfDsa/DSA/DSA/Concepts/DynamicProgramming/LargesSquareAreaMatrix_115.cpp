#include <bits/stdc++.h>
using namespace std;
class a
{
public:
};
int solveSquareRec(vector<vector<int>> matrix, int i, int j, int &maxi)
{

    if (i >= matrix.size() || j >= matrix[0].size())
    {
        return 0;
    }
    int right = solveSquareRec(matrix, i, j + 1, maxi);
    int diagonal = solveSquareRec(matrix, i + 1, j + 1, maxi);
    int down = solveSquareRec(matrix, i + 1, j, maxi);
    if (matrix[i][j] == 1)
    {
        int ans = 1 + min(right, min(diagonal, down));
        maxi = max(maxi, ans);
        return ans;
    }
    else
    {
        return 0;
    }
}
int solveSquareMem(vector<vector<int>> matrix, int i, int j, int &maxi, vector<vector<int>> dp)
{

    if (i >= matrix.size() || j >= matrix[0].size())
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int right = solveSquareMem(matrix, i, j + 1, maxi, dp);
    int diagonal = solveSquareMem(matrix, i + 1, j + 1, maxi, dp);
    int down = solveSquareMem(matrix, i + 1, j, maxi, dp);
    if (matrix[i][j] == 1)
    {
        dp[i][j] = 1 + min(right, min(diagonal, down));
        maxi = max(maxi, dp[i][j]);
        return dp[i][j];
    }
    else
    {
        return dp[i][j] = 0;
    }
}
int solveSquareTab(vector<vector<int>> matrix, int &maxi)
{

    int row = matrix.size();
    int col = matrix[0].size();
    vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));
    for (int i = row - 1; i >= 0; i--)
    {
        for (int j = col - 1; j >= 0; j--)
        {

            if (matrix[i][j] == 1)
            {
                int right = dp[i][j + 1];
                int diagonal = dp[i + 1][j + 1];
                int down = dp[i + 1][j];
                dp[i][j] = 1 + min(right, min(diagonal, down));
                maxi = max(maxi, dp[i][j]);
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    return maxi;
}
int solveOpt(vector<vector<int>> matrix, int &maxi)
{
    int row = matrix.size();
    int col = matrix[0].size();
    vector<int>curr(col+1,0);
    vector<int>next(col+1,0);
    for (int i = row - 1; i >= 0; i--)
    {
        for (int j = col - 1; j >= 0; j--)
        {

            if(matrix[i][j] == 1)
            {
                int right = curr[j + 1];
                int diagonal = next[j + 1];
                int down = next[j];
               curr[j] = 1 + min(right, min(diagonal, down));
                maxi = max(maxi, curr[j]);
            }
            else
            {
                curr[j] = 0;
            }
            next=curr;    
        }
    }
    return maxi;
}
int lagestSquare(int n, int m, vector<vector<int>> matrix)
{
    int ans = 0;
    int maxi = 0;
    vector<vector<int>> dp(n, vector<int>(m, -1));
    // ans = solveSquareRec(matrix, 0, 0, maxi);
    // ans = solveSquareMem(matrix, 0, 0, maxi, dp);
    // ans = solveSquareTab(matrix, maxi);
    ans=solveOpt(matrix,maxi);

    return maxi;
}
int main()
{

    vector<vector<int>> matrix = {
        {1, 0, 1, 0, 0},
        {1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 0, 0, 1, 0}};

    cout << "Largest square of 1s: " << lagestSquare(matrix.size(), matrix[0].size(), matrix) << endl;
    return 0;
}