#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits>
#include <list>
using namespace std;

class A
{
};
int findMax(int n)
{
    vector<vector<int>> arr(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        arr[0][i] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j == 0)
            {
                arr[i][j] = 1;
            }
            else
            {
                arr[i][j] = arr[i][j - 1] + arr[i - 1][j];
            }
        }
    }
    return arr[n - 1][n - 1];
}
int main()
{
    int n;
    cin >> n;
    int ans = findMax(n);
    cout << ans << endl;

    return 0;
}