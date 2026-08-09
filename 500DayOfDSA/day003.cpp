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
    bool valid(int r, int j, int n, int m)
    {
        if (r < 0 || r >= n || j < 0 || j >= m)
        {
            return false;
        }
        return true;
    }
    void colorPicture(vector<vector<int>> &grid, vector<vector<bool>> &vis,
                      int n, int m, int val, int i, int j, int color)
    {
        vis[i][j] = true;
        grid[i][j] = color;
        for (int k = 0; k < 4; k++)
        {
            int row = getRow(i, k);
            int col = getCol(j, k);
            if (valid(row, col, n, m) && grid[row][col] == val &&
                (!vis[row][col]))
            {
                grid[row][col] = color;
                colorPicture(grid, vis, n, m, val, row, col, color);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                  int color)
    {
        int n = image.size();
        int m = image[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int val = image[sr][sc];
        colorPicture(image, vis, n, m, val, sr, sc, color);
        return image;
    }
};