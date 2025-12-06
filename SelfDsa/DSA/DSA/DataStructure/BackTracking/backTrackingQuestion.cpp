#include <bits/stdc++.h>
using namespace std;
class a
{
public:
};
// rat in maze problem solve this by backtracking
// bool isSafe(int newX, int newY, vector<vector<bool>> &visited, vector<vector<int>> &arr, int n)
// {
//     if ((newX >= 0 && newX < n) && (newY >= 0 && newY < n) && (visited[newX][newY] != 1) && arr[newX][newY])
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }
// void solve(int x, int y, vector<vector<int>> &arr, int n, vector<string> &ans, vector<vector<bool>> &visited, string path)
// {
//     if (x == n - 1&&y == n - 1)
//     {
//         ans.push_back(path);
//         return;
//     }
//     // movement
//     // d,l,,r,u
//     // down
//     visited[x][y] = 1;
//     if (isSafe(x + 1, y, visited, arr, n))
//     {
//         solve(x + 1, y, arr, n, ans, visited, path + "D");
//     }
//     // left
//     if (isSafe(x, y - 1, visited, arr, n))
//     {
//         visited[x][y] == 1;
//         solve(x, y - 1, arr, n, ans, visited, path + "L");
//     }
//     // right
//     if (isSafe(x, y + 1, visited, arr, n))
//     {
//         visited[x][y] == 1;
//         solve(x, y + 1, arr, n, ans, visited, path + "R");
//     }
//     // up
//     if (isSafe(x - 1, y, visited, arr, n))
//     {
//         visited[x][y] == 1;
//         solve(x - 1, y, arr, n, ans, visited, path + "U");
//     }
//     visited[x][y] = 0;
// }
// vector<string> ratInMazeProblem(vector<vector<int>> &arr, int n)
// {
//     vector<string> ans;
//     vector<vector<bool>> visited(n, vector<bool>(n, 0));
//     string path = "";
//     solve(0, 0, arr, n, ans, visited, path);
//     return ans;
// }
bool isSafeMaz(int newX, int newY, vector<vector<bool>> &visisted, vector<vector<int>> arr, int n)
{
    if ((newX >= 0 && newX < n) && (newY >= 0 && newY < n) && (visisted[newX][newY] != 1) && (arr[newX][newY]))
    {
        return true;
    }
    return false;
}
void solveMaze(int x, int y, vector<vector<int>> &arr, int n, vector<vector<bool>> &visited, vector<string> &ans, string path)
{
    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(path);
        return;
    }
    visited[x][y] = 1;
    // for down mowvemnet of rat
    if (isSafeMaz(x + 1, y, visited, arr, n))
    {
        solveMaze(x + 1, y, arr, n, visited, ans, path + "D");
    }
    // for Left mowvemnet of rat
    if (isSafeMaz(x, y - 1, visited, arr, n))
    {
        solveMaze(x, y - 1, arr, n, visited, ans, path + "L");
    }
    // for right mowvemnet of rat
    if (isSafeMaz(x, y + 1, visited, arr, n))
    {
        solveMaze(x, y + 1, arr, n, visited, ans, path + "R");
    }
    // for up mowvemnet of rat
    if (isSafeMaz(x - 1, y, visited, arr, n))
    {
        solveMaze(x - 1, y, arr, n, visited, ans, path + "U");
    }
    visited[x][y] = 0;
}

vector<string> ratInMazeProblemImp(vector<vector<int>> &arr, int n)
{
    vector<string> ans;
    string path = "";
    vector<vector<bool>> visited(n, vector<bool>(n, 0));
    solveMaze(0, 0, arr, n, visited, ans, path);
    return ans;
}
bool isSafeQueen(int row, int col, vector<vector<int>> &board, int n)
{
    int x = row;
    int y = col;

    // check row on left
    while (y >= 0)
    {
        if (board[x][y] == 1)
            return false;
        y--;
    }

    // check upper-left diagonal
    x = row;
    y = col;
    while (x >= 0 && y >= 0)
    {
        if (board[x][y] == 1)
            return false;
        x--;
        y--;
    }

    // check lower-left diagonal
    x = row;
    y = col;
    while (x < n && y >= 0)
    {
        if (board[x][y] == 1)
            return false;
        x++;
        y--;
    }

    return true;
}

void addSolution(vector<vector<int>> &board, vector<vector<int>> &ans, int n)
{
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}

void solveQueen(int col, vector<vector<int>> &ans, vector<vector<int>> &board, int n)
{
    if (col == n)
    {
        addSolution(board, ans, n);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (isSafeQueen(row, col, board, n))
        {
            board[row][col] = 1;
            solveQueen(col + 1, ans, board, n);
            // backtracking
            board[row][col] = 0;
        }
    }
}

vector<vector<int>> nQueens(int n)
{
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> ans;
    solveQueen(0, ans, board, n);
    return ans;
}
// suduko solver problem by using backtracking
// by puting 1 to 9 digit
bool isSafeVal(int row, int col, vector<vector<int>> &board, int val)
{
    
    
    for (int i = 0; i < board.size(); i++)
    {
        // row check
        if (board[row][i] == val)
        {
            return false;
        }
        // col check
        if (board[i][col] == val)
        {
            return false;
        }
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val)
        {
            return false;
        }
    }
    return true;
}
bool solve(vector<vector<int>> &board)
{
    int n = board[0].size();
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (board[row][col] == 0)
            {
                for (int val = 1; val <= 9; val++)
                {
                    if (isSafeVal(row, col, board, val))
                    {
                        board[row][col] = val;
                        bool possibleSolvetion = solve(board);
                        if (possibleSolvetion)
                        {
                            return true;
                        }
                        else
                        {
                            board[row][col] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

// void solveSuduko(vector<vector<int>> &suduko)
// {
//     solve(suduko);
// }
void printBoard(vector<vector<int>> &board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}
void solveSuduko(vector<vector<int>> &suduko)
{
    if (solve(suduko))
    {
        cout << "Solved Sudoku:" << endl;
        printBoard(suduko);
    }
    else
    {
        cout << "No solution exists!" << endl;
    }
}
int main()
{

    // rat in maze problem

    // vector<vector<int>> v = {
    //     {1, 0, 1, 0},
    //     {1, 1, 1, 0},
    //     {1, 1, 1, 0},
    //     {0, 1, 1, 1}};
    // vector<string> ans = ratInMazeProblemImp(v, 4);
    // for (int i = 0; i < v.size(); i++)
    // {
    //     cout << ans[i] << "\n";
    // }

    // nqueeen problem

    // int n = 5;
    // vector<vector<int>> solutions = nQueens(n);

    // cout << "Number of solutions: " << solutions.size() << "\n";

    // for (int i = 0; i < solutions.size(); i++)
    // {
    //     cout << "Solution " << i + 1 << ":\n";
    //     for (int j = 0; j < solutions[i].size(); j++)
    //     {
    //         cout << solutions[i][j] << " ";
    //         if ((j + 1) % n == 0)
    //             cout << "\n";
    //     }
    //     cout << "\n";
    // }

    // suduko problem

    vector<vector<int>> sudoku = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}};
    solveSuduko(sudoku);
    return 0;
}
