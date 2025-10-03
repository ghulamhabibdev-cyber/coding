#include <iostream>
using namespace std;
void rowWiseSum(int arr[][4], int row, int col)
{
    int sum = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            sum += arr[i][j];
        }
        cout << "sum of row : " << i << " is : " << sum << endl;
        sum = 0;
    }
}
int maxiSumRow(int arr[][4], int row, int col)
{
    int maxi = INT32_MIN;
    int sum = 0;
    int rowNum = -1;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            sum += arr[i][j];
        }
        if (sum > maxi)
        {
            rowNum = i;
        }
    }
    return rowNum;
}
void printLikeWave(int arr[][4], int nrow, int ncol)
{
    for (int col = 0; col < ncol; col++)
    {
        if (col & 1)
        {
            for (int row = nrow - 1; row >= 0; row--)
            {
                cout << arr[row][col] << " ";
            }
            cout << endl;
        }
        else
        {
            for (int row = 0; row < nrow; row++)
            {
                cout << arr[row][col] << " ";
            }
            cout << endl;
        }
    }
}
int main()
{
    int arr[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    printLikeWave(arr, 3, 4);
    return 0
}