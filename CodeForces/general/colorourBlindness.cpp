#include <iostream>
#include <vector>
using namespace std;

bool isSame(vector<vector<char>> &arr, int n)
{
    for (int j = 0; j < n; j++)
    {
        if (arr[0][j] == arr[1][j])
            continue;

        if ((arr[0][j] == 'B' || arr[0][j] == 'G') &&
            (arr[1][j] == 'B' || arr[1][j] == 'G'))
            continue;

        return false;
    }
    return true;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<vector<char>> arr(2, vector<char>(n));

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> arr[i][j];
            }
        }

        if (isSame(arr, n))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
