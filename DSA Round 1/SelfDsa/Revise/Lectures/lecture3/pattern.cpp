#include <bits/stdc++.h>
using namespace std;

int main()
{
    int row;
    int col;
    cout << "Enter row \n";
    cin >> row;
    cout << "enter col\n";
    cin >> col;
    int i = 1;
    while (i <= row)
    {
        int j = 0;
        while (j < col)
        {
            cout<<"*";
            j++;
        }
        cout<<endl;
        i++;

    }

    return 0;
}
