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
bool checkDrawSqaure(int l, int r, int d, int u)
{
    if (l == r && r == d && d == u && u == l)
    {
        // for (int i = 0; i < l; i++)
        // {
        //     for (int j = 0; j < l; j++)
        //     {
        //         cout << "#" << " ";
        //     }
        //     cout << endl;
        // }
        return true;
    }
    return false;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int l, r, d, u;
        cin >> l >> r >> d >> u;
        bool drawSucess = checkDrawSqaure(l, r, d, u);
        if (drawSucess)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}