#ifndef H_TicTacToe
#define H_TicTacToe
#include <bits/stdc++.h>
using namespace std;
class tictactoe
{
    string player1Name;
    string player2Name;
    bool isWinner;
    int **board;

public:
    tictactoe(string name1,string name2);
    void setNames(string name1,string name2);
    void startGame();
    bool findWinner();
    string winnerIs();
};
tictactoe::tictactoe(string name1,string name2)
{
    this->player1Name=name1;
    this->player2Name=name2;
    board=new int*[3];
    for(int i=0;i<3;i++)
    {
        board[i]=new int[3];
    }
}
#endif
