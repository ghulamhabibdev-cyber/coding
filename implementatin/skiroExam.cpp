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
bool makeArrayZero(int ones, int twos)
{
    if (ones % 2 == 0 && twos % 2 == 0)
    {
        return true;
    }
    else if (ones % 2 == 1 && twos % 2 == 1)
    {
        return false;
    }
    int rem = twos * 2;
    if (rem - ones == 0)
    {
        return true;
    }
    if((ones%2==0||twos%2==1)&&(ones%2==1||twos%2==0))
    {
        return true;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int ones, twos;
        cin >> ones >> twos;
        if (makeArrayZero(ones, twos))
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