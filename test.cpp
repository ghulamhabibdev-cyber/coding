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
int GCD(int a, int b)
{
    while (b != 0)
    {
        int rem = a % b;
        cout << rem << endl;
        a = b;
        b = rem;
    }
    return a;
}
int main()
{
    int a = 503;
    int b = 509;
    cout << GCD(a, b) << endl;
    return 0;
}