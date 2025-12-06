#include <bits/stdc++.h>
using namespace std;
class a
{
public:
};
// I am trying to solve sukduk problem by backtring
// Making function that check each row and colmn to confirm that each row and
// colmn must has one  value once
//  then i will check that each 3*3 must has
bool isSafeToPutSudukoValue(int row, int col, vector<vector<int>> &board, int val)
{
    for(int i=0;i<9;i++)
    {
        if(board[row][i]==val)
        {
            return false;
        }
        if(board[i][col]==val)
        {
            return false;
        }
        if(board[3*(row/3)+i/3][3*(col/3)+i%3]==val)
        {
            return false;
        }
    }
    return true;
}
bool solveSukudko(vector<vector<int>> &board)
{
    for (int row = 0; row < board[0].size(); row++)
    {
        for (int col = 0; col < board[0].size(); col++)
        {
            if (board[row][col] == 0)
            {
                for (int digit = 1; digit <= 9; digit++)
                {
                    if (isSafeToPutSudukoValue(row, col, board, digit))
                    {
                        board[row][col] = digit;
                        bool possibleSolution = solveSukudko(board);
                        if(possibleSolution)
                        {
                            return true;
                        }
                        else{
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
void printSukudko(vector<vector<int>> &board)
{
    for(int row=0;row<board.size();row++)
    {
        for(int col=0;col<board.size();col++)
        {
            cout<<board[row][col]<<" ";
        }
        cout<<endl;
    }
}
void sudukoSolver(vector<vector<int>> &board)
{
    if(solveSukudko(board))
    {
        printSukudko(board);
    }
    else
    {
        cout << "No solution exists!" << endl;
    }
}

//

int main()
{

        vector<vector<int>> sudoku = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0}};
    sudukoSolver(sudoku);
    return 0;
}