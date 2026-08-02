// Write a program to calculate the sum and average of elements of a 2D array.
#include <iostream>
using namespace std;

int main()
{
    const int row=3;
    const int col=3;
    int arr[row][col];
    cout << "===========Taking Input ===============\n";

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << "Enter A number \n";
            cin >> arr[i][j];
        }
    }
    cout << "=============Sum and Average of 2D Array=============\n";
    int sum = 0;
    int count = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            sum += arr[i][j];
            count++;
        }
    }
    cout << "Sum : " << sum << endl;
    cout << "Average : " << double(sum / count) << endl;

    return 0;
}
