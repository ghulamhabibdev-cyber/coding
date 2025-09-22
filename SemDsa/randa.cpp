#include <bits/stdc++.h>
using namespace std;
class a
{
};

int main()
{
    /*
    *****
    *****
    *****
    ABCDE
    */

    char ch = 'A';

    for (int i = 0; i < 4; i++)
    {

        for (int j = 0; j < 4; j++)
        {
            if (i == j+3-j)
            {
                cout << ch;
                ch++;
            }
            else
            {
                cout << "*";
            }
            
        }
        cout << endl;
    }

    return 0;
}
