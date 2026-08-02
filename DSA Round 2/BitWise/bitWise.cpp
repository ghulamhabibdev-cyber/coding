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
    int a = 4, b = 8;
    cout << (a & b) << endl;
    cout << (a | b) << endl;
    cout << (a ^ b) << endl;
    cout << (b << 1) << endl;
    cout << (5 - 2 * 6) << endl;
    // equal precedence
    cout << (5 * 4 % 2) << endl;
    unsigned x = -10;
    cout << x << endl;
    return 0;
}