#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits>
#include <list>
#include <math.h>
using namespace std;

class A
{
};
int square(int a)
{
    return a * a;
}
int main()
{
    int ans = sqrt(2025);
    cout << ans << endl;
    cout << square((ans - 1)) + square(1) << endl;
    return 0;
}