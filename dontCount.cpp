#include <iostream>
#include <vector>
using namespace std;

int solve(string x, string s)
{
    int count = 0;

    while (true)
    {
        if (x.find(s) != string::npos)
            return count;

        if (x.length() > 100)
            return -1;

        x += x;
        count++;
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        string x, s;

        cin >> n >> m;
        cin >> x >> s;

        cout << solve(x, s) << endl;
    }
}
