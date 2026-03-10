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
int findMaxSeated(int m, int a, int b, int c)
{
    int totalSeated = 0;
    int mini = min(m, a);
    int remfirstRow = m - mini;
    totalSeated += mini;
    if (remfirstRow != 0)
    {
        mini = min(remfirstRow, c);
        remfirstRow = remfirstRow - mini;
        c = c - mini;
        totalSeated += mini;
    }
     int  bMini = min(m, b);
     int rowSecondRow = m - bMini;
     totalSeated += bMini;
     if (rowSecondRow != 0)
     {
         bMini = min(rowSecondRow, c);
         totalSeated += bMini;
     }
    return totalSeated;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int m, a, b, c;
        cin >> m >> a >> b >> c;
        int maxSeated = findMaxSeated(m, a, b, c);
        cout << maxSeated << endl;
    }
    return 0;
}