#include <bits/stdc++.h>
using namespace std;

int main()
{
    int row, col;
    cout << "Enter row \n";
    cin >> row;
    cout << "enter col\n";
    cin >> col;
    int i = 1;
    while (i <= row)
    {
        int j = 1;

        while (j <= col)
        {
            cout << i;
            j++;
        }
        cout << endl;
        i++;
    }
    return 0;
}
