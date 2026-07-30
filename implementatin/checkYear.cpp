#include <iostream>
#include <cmath>
#include<cstdlib>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;

        int year = stoi(s);

        int x = sqrt(year);

        if (x * x != year)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << 0 << " " << x << endl;
        }
    }

    return 0;
}