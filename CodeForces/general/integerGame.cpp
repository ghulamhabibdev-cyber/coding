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
void gameOfInteger(int n)
{
    for (int i = 1; i <= n; i++)
    {
        int number;
        cin >> number;
        if (number % 3 == 0)
        {
            cout << "Second" << endl;
        }
        else
        {
            cout << "First" << endl;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    gameOfInteger(n);

    return 0;
}