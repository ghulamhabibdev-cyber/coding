#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits>
#include <list>
typedef bool gool;
using namespace std;

class A
{
};
gool isPossbile(int w, int h, int n)
{
    if (w >= h && w % 2 == 1 && h % 2 == 1 && n == 1)
    {
        return true;
    }
    else if (w >= h && w % 2 == 1 && h % 2 == 1 && n >= 2)
    {
        return false;
    }
    int count = 1;
    while(w%2==0)
    {
        w/=2;
        count*=2;
    }
    while(h%2==0)
    {
        h/=2;
        count*=2;
    }
    return count >= n;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int w, h, n;
        cin >> w >> h >> n;
        gool isPoss = isPossbile(w, h, n);
        if (isPoss)
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