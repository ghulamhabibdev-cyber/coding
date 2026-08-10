class Solution
{
public:
    int getRow(int r, int index)
    {
        int x[4] = {-1, 1, 0, 0};
        return r + x[index];
    }

    int getCol(int c, int index)
    {
        int y[4] = {0, 0, -1, 1};
        return c + y[index];
    }

    bool valid(int r, int c, int n, int m)
    {
        if (r < 0 || r >= n || c < 0 || c >= m)
        {
            return false;
        }
        return true;
    }

    void connectOcean(
        vector<vector<int>> &grid,
        vector<vector<bool>> &vis,
        int startRow,
        int startCol,
        int row,
        int col,
        int n,
        int m,
        int curr,
        bool &pacific,
        bool &atlantic)
    {
        // Check if current cell touches Pacific Ocean
        if (row == 0 || col == 0)
        {
            pacific = true;
        }

        // Check if current cell touches Atlantic Ocean
        if (row == n - 1 || col == m - 1)
        {
            atlantic = true;
        }

        vis[row][col] = true;

        for (int k = 0; k < 4; k++)
        {

            int r = getRow(row, k);
            int c = getCol(col, k);

            if (valid(r, c, n, m) &&
                !vis[r][c] &&
                grid[r][c] <= curr)
            {

                connectOcean(
                    grid,
                    vis,
                    startRow,
                    startCol,
                    r,
                    c,
                    n,
                    m,
                    grid[r][c],
                    pacific,
                    atlantic);
            }
        }

        // Backtracking
        vis[row][col] = false;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>> &grid)
    {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(
            n,
            vector<bool>(m, false));

        vector<vector<int>> res;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                bool pacific = false;
                bool atlantic = false;
                connectOcean(
                    grid,
                    vis,
                    i,
                    j,
                    i,
                    j,
                    n,
                    m,
                    grid[i][j],
                    pacific,
                    atlantic);

                if (pacific && atlantic)
                {
                    res.push_back({i, j});
                }
            }
        }

        return res;
    }
};