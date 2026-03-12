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
void upScallingMatrix(int n)
{
    int rows = 2 * n;
    int cols = 2 * n;
    vector<vector<char>> matrix(rows, vector<char>(cols));
    bool toggle = true;
    for (int row = 0; row < rows; row += 2)
    {
        bool curr = toggle;
        for (int col = 0; col < cols; col += 2)
        {
            for (int i = row; i < 2 + row; i++)
            {
                for (int j = col; j < 2 + col; j++)
                {
                    if (curr)
                    {
                        matrix[i][j] = '#';
                    }
                    else
                    {
                        matrix[i][j] = '.';
                    }
                }
            }
            curr = !curr;
        }
        toggle = !toggle;
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << matrix[i][j];
        }
        cout << endl;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        upScallingMatrix(n);
    }

    return 0;
}