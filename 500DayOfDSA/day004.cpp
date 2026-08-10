class Solution
{
public:
    int getRow(int r, int index)
    {
        int x[4] = {-1, 1, 0, 0}; // top bottom left right
        int row = r + x[index];
        return row;
    }
    int getCol(int c, int index)
    {
        int y[4] = {0, 0, -1, 1}; // top bottom left right
        int col = c + y[index];
        return col;
    }
    bool valid(int row, int col, int n, int m)
    {
        if (row < 0 || col < 0 || row >= n || col >= m)
        {
            return false;
        }
        return true;
    }
    void calculatePerimeter(vector<vector<int>> &grid, vector<vector<bool>> &vis, int row, int col, int n, int m, int &count)
    {
        vis[row][col] = true;
        for (int i = 0; i < 4; i++)
        {
            int gRow = getRow(row, i);
            int gCol = getCol(col, i);
            if (valid(gRow, gCol, n, m) && grid[gRow][gCol] == 1 && (!vis[gRow][gCol]))
            {
                calculatePerimeter(grid, vis, gRow, gCol, n, m, count);
            }
            if (valid(gRow, gCol, n, m) && grid[gRow][gCol] == 0)
            {
                count++;
            }
            if (!valid(gRow, gCol, n, m))
            {
                count++;
            }
        }
    }
    int islandPerimeter(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    int count = 0;
                    calculatePerimeter(grid, vis, i, j, n, m, count);
                    return count;
                }
            }
        }
        return 0;
    }
};