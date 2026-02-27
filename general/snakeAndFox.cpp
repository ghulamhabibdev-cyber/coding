#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits>
#include <list>
using namespace std;

class A
{
};
vector<string> snakePattern(int row, int col)
{
    bool alter = false;
    vector<string> snake;
    for (int i = 1; i <= row; i++)
    {

        string currBody = "";
        if (i % 2 == 1)
        {
            currBody = string(col, '#');
        }
        else
        {

            for (int j = 0; j < col; j++)
            {
                currBody += '.';
            }

            if (alter)
            {
                currBody[0] = '#'; // left
            }
            else
            {
                currBody[col - 1] = '#'; // right
            }
            alter = !alter;
        }
       

        snake.push_back(currBody);
    }
    return snake;
}
int main()
{
    int row, col;
    cin >> row >> col;
    vector<string> snakeBody = snakePattern(row, col);
    int n = snakeBody.size();
    for (int i = 0; i < n; i++)
    {
        cout << snakeBody[i] << endl;
    }

    return 0;
}