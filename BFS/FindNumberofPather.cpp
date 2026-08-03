#include <iostream>
#include <vector>

using namespace std;

bool valid(int row, int col, int n, int m, const vector<vector<int>>& grid, const vector<vector<bool>>& vis) {
    if (row < 0 || row >= n || col < 0 || col >= m) {
        return false;
    }
    if (grid[row][col] == 0 || vis[row][col]) {
        return false;
    }
    return true;
}

int getRow(int r, int index) {
    int x[4] = {-1, 1, 0, 0};
    return r + x[index];
}

int getCol(int c, int index) {
    int y[4] = {0, 0, -1, 1};
    return c + y[index];
}

// Pass vectors by reference (&) to avoid massive performance penalties
void helper(const vector<vector<int>>& grid, vector<vector<bool>>& vis, int r, int c, int n, int m, int &ans) {
    // If destination is reached, increment path count
    if (r == n - 1 && c == m - 1) {
        ans++;
        return;
    }

    // Mark current cell as visited
    vis[r][c] = true;

    // Explore all 4 directional neighbors
    for (int k = 0; k < 4; k++) {
        int nextRow = getRow(r, k);
        int nextCol = getCol(c, k);

        if (valid(nextRow, nextCol, n, m, grid, vis)) {
            helper(grid, vis, nextRow, nextCol, n, m, ans);
        }
    }

    vis[r][c] = false;
}

int totalNumberOfPaths(const vector<vector<int>>& grid) {
    if (grid.empty() || grid[0].empty() || grid[0][0] == 0) {
        return 0;
    }
    
    int n = grid.size();
    int m = grid[0].size();
    
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    int ans = 0;
    
    helper(grid, vis, 0, 0, n, m, ans);
    return ans;
}

int main() {
    vector<vector<int>> grid = {
        {1, 1, 0},
        {1, 1, 1},
        {0, 1, 1}
    };
    
    cout << "Total Number of Paths: " << totalNumberOfPaths(grid) << endl;
    return 0;
}
