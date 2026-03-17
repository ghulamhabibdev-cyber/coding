#include <bits/stdc++.h>
using namespace std;
class a
{
public:
};
bool check(vector<int> base, vector<int> newBox)
{
    if (newBox[0] <= base[0] && newBox[1] <= base[1] && newBox[2] <= base[2])
    {
        return true;
    }
    return false;
}
int solveOpt_1(int n, vector<vector<int>> &cubiod)
{
    // vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    vector<int> currRow(n + 1, 0);
    vector<int> next(n + 1, 0);

    for (int curr = n - 1; curr >= 0; curr--)
    {
        for (int prev = curr - 1; prev >= -1; prev--)
        {
            int take = 0;
            if (prev == -1 || check(cubiod[curr], cubiod[prev]))
            {
                take = cubiod[curr][2] + next[curr + 1];
            }
            int notTake = 0 + next[prev + 1];
            int ans = max(take, notTake);
            currRow[prev + 1] = ans;
        }
        next = currRow;
    }
    return next[0];
}
int heightOfCuboid(vector<vector<int>> cubiod)
{
    for (auto &a : cubiod)
    {
        sort(a.begin(), a.end());
    }
    sort(cubiod.begin(), cubiod.end());
    int ans = 0;
    ans = solveOpt_1(cubiod.size(), cubiod);
    return ans;
}
int main()
{
    vector<vector<int>> cuboid = {
        {50, 45, 20},
        {95, 37, 53},
        {45, 23, 12}};

    cout << "Max Height: " << heightOfCuboid(cuboid) << endl;
    return 0;
}