#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;

        bool hasPair = false;

        for (int i = 0; i < s.size() - 1; i++)
        {
            if (s[i] == s[i + 1])
            {
                hasPair = true;
                break;
            }
        }

        if (hasPair)
            cout << 1 << endl;
        else
            cout << s.size() << endl;
    }

    return 0;
}