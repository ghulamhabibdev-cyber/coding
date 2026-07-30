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
int minStepToamekGrea(int a, int b, int x)
{
    int minStep = 0;
    while (a <=x)
    {
        int curr=a+b;
        b=max(a,b);
        a=curr;
        minStep++;
    }
    return minStep;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, x;
        cin >> a >> b >> x;
        int minStep = minStepToamekGrea(a, b, x);
        cout << minStep << endl;
    }

    return 0;
}