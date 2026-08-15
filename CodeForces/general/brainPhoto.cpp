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
bool isColor(int row, int col)
{
    vector<vector<char>> arr(row, vector<char>(col));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
        }
    }
    bool flag=false;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] == 'W' || arr[i][j] == 'B' || arr[i][j] == 'G')
            {
                flag=false;
            }
            else{
                flag=true;
                break;
            }
        }
        if(flag)
        {
            break;
        }

    }
    return flag;
}
int main()
{
    int row, col;
    cin >> row >> col;
    bool ans = isColor(row, col);
    if (ans)
    {
        cout << "#Color";
    }
    else
    {
        cout << "#Black&White";
    }

    return 0;
}