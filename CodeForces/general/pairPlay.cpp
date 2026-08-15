#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int s1, s2, s3, s4;
        cin >> s1 >> s2 >> s3 >> s4;

        // Winners of semifinals
        int w1 = max(s1, s2);
        int w2 = max(s3, s4);

        // Find top two skills overall
        int arr[4] = {s1, s2, s3, s4};
        sort(arr, arr + 4);

        int largest = arr[3];
        int second_largest = arr[2];

        if ((w1 == largest && w2 == second_largest) ||
            (w1 == second_largest && w2 == largest))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}
