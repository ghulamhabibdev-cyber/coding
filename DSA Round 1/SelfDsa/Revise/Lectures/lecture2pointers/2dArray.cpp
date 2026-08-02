#include<iostream>
using namespace std;

int main()
{

    int **ptr = new int *[3]; // Step 1: Allocate array of 3 int pointers (rows)

    for (int i = 0; i < 3; i++)
    {
        ptr[i] = new int[4]; // Step 2: For each row, allocate 4 ints (columns)
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            ptr[i][j] = (i + 1) * (j + 1);
            cout << ptr[i][j] << " ";
        }
        cout << endl;
    }

    // Step 3: Free memory
    for (int i = 0; i < 3; i++)
    {
        delete[] ptr[i]; // delete each row
    }
    delete[] ptr;
    return 0;
}
