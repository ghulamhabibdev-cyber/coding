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
pair<int, int> manhattanCentre(vector<vector<char>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();
    pair<int, int> p = make_pair(INT_MIN, INT_MIN);
    int i = 0;
    int j = 0;
    for (i = 0; i < rows; i++)
    {
        bool found=false;
        for (j = 0; j < cols; j++)
        {
            char ch = matrix[i][j];

            if (ch == '#')
            {
                found=true;
                break;
            }
        }
        if (found)
        {
            break;
        }
        j = 0;
    }
    int ib = 0;
    int jb = 0;
    for (ib = rows - 1; ib >= 0; ib--)
    {
        bool found=false;
        for (jb = cols - 1; jb >= 0; jb--)
        {
            char ch = matrix[ib][jb];

            if (ch == '#')
            {
                found=true; 
                // cout << "j : " << j << " Jb : " << jb << endl;
                break;
            }
        }
        if (found)
        {
            break;
        }
        jb=cols-1;
    }

    int center = (i + ib) / 2;
    p = make_pair(center + 1, j + 1);
    return p;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int rows, cols;
        cin >> rows >> cols;
        vector<vector<char>> matrix(rows, vector<char>(cols));
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cin >> matrix[i][j];
            }
        }
        pair<int, int> p = manhattanCentre(matrix);
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}