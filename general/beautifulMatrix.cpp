#include <iostream>
#include <vector>
using namespace std;
pair<int, int> findRowColmn(vector<vector<int>> matrix)
{
    int i = 0;

    pair<int, int> p;
    while (i < 5)
    {
        int j = 0;
        while (j < 5)
        {

            if (matrix[i][j] == 1)
            {
                p = make_pair(i, j);
                return p;
            }
            j++;
        }
       
        i++;
    }
    return {-1,-1};
}
int rowSwapStep(vector<vector<int>> &matrix, int currRow, int currCol)
{
    int count = 0;
    if (currRow < 2)
    {
        while (currRow != 2)
        {
            // swap(matrix[currRow][currCol], matrix[currRow + 1][currCol]);
            currRow++;
            count++;
        }
    }
    else
    {
        while (currRow != 2)
        {
            // swap(matrix[currRow][currCol], matrix[currRow - 1][currCol]);
            currRow--;
            count++;
        }
    }
    return count;
}
int colSwapStep(vector<vector<int>> &matrix, int currCol)
{
    int count=0;
    if (currCol <= 2)
    {
        while (currCol != 2)
        {
            // swap(matrix[2][currCol], matrix[2][currCol+1]);
            currCol++;
            count++;
        }
    }
    else{
        while(currCol!=2)
        {
            //  swap(matrix[2][currCol], matrix[2][currCol-1]);
            currCol--;
            count++;
        }
    }
    return count;
}

void printMatrix(vector<vector<int>> matrix)
{
    int i = 0;
    while (i < 5)
    {
        int j = 0;
        while (j < 5)
        {

            cout << matrix[i][j] << " ";
            j++;
        }
        cout << endl;

        i++;
    }
}

int main()
{
  vector<vector<int>> matrix(5, vector<int>(5, 0));

    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            int n;
            cin>>n;
            matrix[i][j]=n;
        }
    }
     
    pair<int, int> rowCol = findRowColmn(matrix);
    int rowNo = rowCol.first;
    int colNo = rowCol.second;
    int rowStep = rowSwapStep(matrix, rowNo, colNo);
    rowStep+=colSwapStep(matrix,colNo);
    cout << rowStep << endl;
    // printMatrix(matrix);
    return 0;
}