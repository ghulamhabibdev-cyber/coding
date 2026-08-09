class Solution
{
public:
    int getRow(int r, int index)
    {
        int x[4] = {-1, 1, 0, 0};
        int row = r + x[index];
        return row;
    }
    int getCol(int c, int index)
    {
        int y[4] = {0, 0, -1, 1};
        int col = c + y[index];
        return col;
    }
    bool valid(int row, int col, int n, int m)
    {
        if (row < 0 || row >= n || col < 0 || col >= m)
        {
            return false;
        }
        return true;
    }
    void dfs(vector<vector<int>> &grid, vector<vector<bool>> &vis, int n, int m, int r, int c, int &res)
    {
        vis[r][c] = true;
        res += 1;
        for (int k = 0; k < 4; k++)
        {
            int row = getRow(r, k);
            int col = getCol(c, k);
            if (valid(row, col, n, m) && grid[row][col] == 1 && !vis[row][col])
            {

                dfs(grid, vis, n, m, row, col, res);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {

        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        int maxi = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && grid[i][j] == 1)
                {
                    int count = 0;
                    dfs(grid, vis, n, m, i, j, count);
                    maxi = max(count, maxi);
                }
            }
        }
        return maxi;
    }
};