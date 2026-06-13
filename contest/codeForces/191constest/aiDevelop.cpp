#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long n, x, y, z;
        cin >> n >> x >> y >> z;

        long long withoutAI = (n + (x + y) - 1) / (x + y);

        long long withAI;

        long long writtenDuringSetup = x * z;

        if (writtenDuringSetup >= n)
        {
            withAI = z;
        }
        else
        {
            long long remaining = n - writtenDuringSetup;
            withAI = z + (remaining + (x + 10 * y) - 1) / (x + 10 * y);
        }

        cout << min(withoutAI, withAI) << '\n';
    }

    return 0;
}