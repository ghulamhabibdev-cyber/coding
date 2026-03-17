#include <iostream>
using namespace std;

int main()
{

    int arr[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};

    int wave[4][4]; // temporary array to store wave order

    // Fill wave array column-wise in wave pattern
    for (int i = 0; i < 4; i++)
    {
        if (i % 2 == 0)
        {
            // Even column → top to bottom
            for (int j = 0; j < 4; j++)
                wave[j][i] = arr[j][i];
        }
        else
        {
            // Odd column → bottom to top
            for (int j = 0; j < 4; j++)
                wave[j][i] = arr[3 - j][i];
        }
    }

    // Print visually column-wise
    cout << "Column-wise Wave (Visual):\n\n";
    for (int r = 0; r < 4; r++)
    {
        for (int c = 0; c < 4; c++)
        {
            cout << wave[r][c] << "\t";
        }
        cout << endl;
    }

    return 0;
}
