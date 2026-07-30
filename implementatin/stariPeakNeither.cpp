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

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a < b&&b < c)
        {
            cout << "STAIR" << endl;
        }
        else if (a<b&&b> c)
        {
            cout << "PEAK" << endl;
        }
        else
        {
            cout << "NONE" << endl;
        }
    }

    return 0;
}