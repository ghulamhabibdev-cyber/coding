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
int finSqaureArea(pair<int, int> cordinateX, pair<int, int> cordinatY)
{
    int x = cordinateX.first - cordinateX.second;
    int y = cordinatY.first - cordinatY.second;
    return x * y;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n = 4;
        pair<int, int> cordinateX;
        pair<int, int> cordinateY;
        cin >> cordinateX.first;
        cin >> cordinateY.first;
        for (int i = 0; i < n-1; i++)
        {
            int xi;
            int yi;
            cin >> xi >> yi;
            if (xi > cordinateX.first)
            {
                int tempCord = cordinateX.first;
                cordinateX.first = xi;
                cordinateX.second = tempCord;
            }
            else if(xi<cordinateX.first)
            {
                cordinateX.second=xi;
            }
            if (yi > cordinateY.first)
            {
                int tempCord = cordinateY.first;
                cordinateY.first = yi;
                cordinateY.second = tempCord;
            }
            else if(yi<cordinateY.first)
            {
                cordinateY.second = yi;
            }
        }
        // cout << "here : find area  : " << endl;
        // cout << cordinateX.first << " : " << cordinateX.second << endl;
        // cout << cordinateY.first << " : " << cordinateY.second << endl;
        int squareArea = finSqaureArea(cordinateX, cordinateY);
        cout << squareArea << endl;
    }
    return 0;
}