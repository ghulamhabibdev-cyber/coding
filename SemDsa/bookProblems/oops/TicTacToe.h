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

#endif
