
#include <iostream>
using namespace std;
void PrintlikeSpiaral(int arr[][5], int row, int col)
{
    int startRow = 0;
    int startCol = 0;
    int endingRow = row -1;
    int endingCol = col -1;
    int count = 0;
    int total = row * col;
    while (count < total)
    {
        // print firstRow
        for (int index = startCol; count < total && index <= endingCol; index++)
        {
            cout << arr[startRow][index] << " ";
            count++;
        }
        startRow++;
        // printing ending colmns
        for (int index = startRow; count < total && index <= endingRow; index++)
        {
            cout << arr[index][endingCol] << " ";
            count++;
        }
        endingCol--;
        // print last row colmn
        for (int index = endingCol; count < total && index >= startCol; index--)
        {
            cout << arr[endingRow][index] << " ";
            count++;
        }
        endingRow--;
        // printing first colmn
        for (int index = endingRow; count < total && index >= startRow; index--)
        {
            cout << arr[index][startCol] << " ";
            count++;
        }
        startCol++;
    }
}

int main()
{
    int arr[4][5] = {{1, 2, 3, 4, 5}, 
                    {6, 7, 8, 9, 10}, 
                    {11, 12, 13, 14, 15},
                    {16, 17, 18, 19, 20}};
    PrintlikeSpiaral(arr, 4, 5);
}